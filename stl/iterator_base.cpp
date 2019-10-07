

//5种迭代器类型

struct input_iterator_tag{};
struct output_iterator_tag{};
struct forward_iterator_tag: public input_iterator_tag{};
struct bidirectional_iterator_tag: public forward_iterator_tag{};
struct random_access_iterator_tag: public bidirectional_iterator_tag{};

template<class _Tp,class _Distance>
struct input_iterator
{
    using iterator_category = input_iterator_tag;
    using value_type = _Tp;
    using difference_type = _Distance;
    using pointer = _Tp*;
    using reference = _Tp&;
};
struct output_iterator
{
    using iterator_category = output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;
};

template<class _Tp,class _Distance>
struct forward_iterator
{
    using iterator_category = forward_iterator_tag;
    using value_type = _Tp;
    using difference_type = _Distance;
    using pointer = _Tp*;
    using reference = _Tp&;
};

template<class _Tp,class _Distance>
struct bidirectional_iterator
{
    using iterator_category = bidirectional_iterator_tag;
    using value_type = _Tp;
    using difference_type = _Distance;
    using pointer = _Tp*;
    using reference = _Tp&;
};
//**************************5种迭代器类
template<class _Category,class _Tp,class _Distance = int,class _Pointer = _Tp*,class _Reference = _Tp&>
struct iterator
{
    using iterator_category = _Category;
    using value_type = _Tp;
    using difference_type = _Distance;
    using pointer = _Pointer;
    using reference = _Reference;
};
//通用迭代器类型，要写迭代器就要继承上面这个模板


//类型萃取

template<class _Iterator>
struct iterator_traits
{
    using iterator_category =  typename _Iterator::iterator_category;
    using value_type = typename _Iterator::value_type; 
    using difference_type = typename _Iterator::difference_type;
    using pointer = typename _Iterator::pointer;
    using reference = typename _Iterator::reference; 
};
template<class _Tp>
struct iterator_traits<_Tp*>
{
    using iterator_type = random_access_iterator_tag;
    using value_type = _Tp;
    using difference_type = int;
    using pointer = _Tp*;
    using reference = _Tp&;
};
template<class _Tp>
struct iterator_traits<const _Tp*>
{
    using iterator_type = random_access_iterator_tag;
    using value_type = _Tp;
    using difference_type = int;
    using pointer = const _Tp*;
    using reference = const _Tp&;
};
