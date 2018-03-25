/*
 * type_traits不不属于STL，是SGI所实现的;
 * 对于non-trivial类型，即用户自定义类型
 * 对于trivial类型，即内置类型，可以使用memcpy()或memmove()
 */
__type_traits<T>::has_trivial_default_constructor
__type_traits<T>::has_trivial_copy_constructor
__type_traits<T>::has_trivial_assigment_operator
__type_traits<T>::has_trivial_destuctor
__type_traits<T>::is_POD_type

struct __true_type {}; // 代表内置类型
struct __false_type {};

template<class Type>
struct __type_traits {
  typedef __true_type       this_dummy_member_must_be_first;

  typedef __false_type      has_trivial_default_constructor
  typedef __false_type      has_trivial_copy_constructor
  typedef __false_type      has_trivial_assigment_operator
  typedef __false_type      has_trivial_destuctor
  typedef __false_type      is_POD_type
};