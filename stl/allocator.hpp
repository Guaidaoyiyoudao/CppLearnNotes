#include<malloc.h>
#include<cstddef>



//本分配器只具有第二级分配
//

class Alloc
{
    const static int _MAX_BYTES = 128;
    const static int _ALIGN_BYTE = 8;//8字节对齐
    const static size_t _NOFFREELISTS = 16; // 128 / 8
    
private:

    //字节对齐
    static size_t _round_up(size_t bytes)
    {
        return (bytes+_ALIGN_BYTE-1)&~(static_cast<size_t>(_ALIGN_BYTE)-1);
    }
    //根据字节大小确定在哪一条链表
    static unsigned int _free_index(size_t __n)
    {
        return static_cast<unsigned int>((__n+_ALIGN_BYTE-1))/(_ALIGN_BYTE-1);
    }
    union obj
    {
        obj* m_free_link;
        char client_data[1];
    };
    
    static void* fill_up(size_t bytes)
    {
        int nobjs = 20;
        char* chunk = chunk_alloc(bytes,nobjs);

        if(nobjs==1)
            return chunk;

        //构建空闲链表
        char* result = chunk;
        obj** __my_free_list = _my_free_lists + _free_index(bytes);
        obj* current;
       //第一个块返回给client,剩余的块构建链表 
        *__my_free_list  = current = reinterpret_cast<obj*>(chunk+bytes);
        for(int i=1;i<nobjs-1;i++)
        {
            current->m_free_link = current+bytes;
            current = current->m_free_link;
        }
        current->m_free_link = nullptr;
        return result; 
        
    }

    static char* chunk_alloc(size_t bytes,int& nobjs)
    {
        size_t total_bytes = bytes*nobjs;
        size_t left_bytes = _free_start - _free_end;     
        char* result = nullptr; 
        if(left_bytes>=total_bytes)
        {
            result = _free_start;
            _free_start += total_bytes;

            return result;
        }
        //还可以分配几个
        else if(left_bytes>=bytes)
        {
            nobjs = static_cast<int>(left_bytes / bytes);
            total_bytes = nobjs*bytes;
            result = _free_start;
            _free_start += total_bytes;
            return result;
        }
        //一个都分配不了了
        else
        {

            //把剩余的空间编入到空闲链表里面
            if(left_bytes>0)
            {
                
                obj** __my_free_list = _my_free_lists + _free_index(left_bytes);
                reinterpret_cast<obj*>(_free_start)->m_free_link = *__my_free_list;
                *__my_free_list = reinterpret_cast<obj*>(_free_start);
                _free_start += left_bytes;

            }
             
            size_t bytes_to_get = 2*total_bytes + (size_t)(_heap_size>>4);
            _free_start = (char*)malloc(bytes_to_get);

           
            //如果分配失败
            if(_free_start==nullptr)
            {
                //尝试从空闲链表中弄到内存空间
                for(size_t i = (size_t)_ALIGN_BYTE;i<=_MAX_BYTES;i+=(size_t)_ALIGN_BYTE)
                {
                    obj** __my_free_list = _my_free_lists + _free_index(i);
                    obj* p = *__my_free_list;
                    //该链表还有空闲块
                    if(p!=nullptr)
                    {

                        *__my_free_list = p->m_free_link;
                        _free_start = reinterpret_cast<char*>(p);
                        _free_end = _free_start + i;

                        return chunk_alloc(bytes,nobjs);
                    }


                }
            }
            //分配成功
            
            _heap_size += bytes_to_get;
            _free_end = _free_start + bytes_to_get;

            return chunk_alloc(bytes,nobjs);
        }

    }



private:  
    static obj* _my_free_lists[_NOFFREELISTS];
    static char* _free_start;
    static char* _free_end;
    static size_t _heap_size;
public:
    
    static void* allocate(size_t __n)
    {
        
        void * _ret = nullptr;

        obj** __my_free_list = _my_free_lists + _free_index(__n);
        
        obj* p = *__my_free_list;
        
        if(p==nullptr)
        {
           _ret = fill_up(_round_up(__n)); 
        }
        else
        {
            _ret = reinterpret_cast<void*>(p);
            *__my_free_list = p->m_free_link;
        }
        return _ret;
    }
    static void deallocate(void* p,size_t __n)
    {
      
       obj** __my_free_list = _my_free_lists + _free_index(__n); 

       static_cast<obj*>(p)->m_free_link = *__my_free_list;
       
       *__my_free_list = static_cast<obj*>(p);
    }


};

char* Alloc::_free_start = nullptr;
char* Alloc::_free_end = nullptr;
size_t Alloc::_heap_size = 0;
Alloc::obj* Alloc::_my_free_lists[Alloc::_NOFFREELISTS] = {nullptr};
