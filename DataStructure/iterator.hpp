
template<typename T>
class Iterator
{
    using value_type = T;
    using pointer = T*;
public:
    //constructor
    Iterator(pointer p=nullptr):it(p){}
    Iterator(const Iterator& other);
    Iterator(Iterator&& other);
    ~Iterator();
    // operator
    Iterator& operator =(const Iterator& other);
    Iterator& operator =(Iterator&& other);
    bool operator ==(const Iterator& other)const;
    bool operator !=(const Iterator& other)const;
    value_type& operator *();
    Iterator& operator ++();
    Iterator& operator --();
    Iterator& operator ++(int);
    Iterator& operator --(int);
    
    
private:
    pointer it;
};
