#include <new.h>

/*
 * construct()
 */
template<class T1, class T2>
inline void construct(T1* p, const T2& value) {
    new (p) T1(value);
}

/*
 * destroy()第一版本
 */
template<class T>
inline void destroy(T* pointer) {
    pointer->~T();
}

/*
 * destroy()第二版本
 */
template <class ForwardIterator>
inline void
__destroy_aux(ForwardIterator first, ForwardIterator last, __false_type) { // 显示定义的析构函数, non-trivial destructor
  for (; first<last; ++first)
    destroy(&*first);
}

template <class ForwardIterator>
inline void
__destroy_aux(ForwardIterator first, ForwardIterator last, __true_type) {} // 隐式构造函数, trivial destructor
 
template<class ForwardIterator, class T>
inline void __destroy(ForwardIterator first, ForwardIterator last, T*) { 
  typedef typename __type_traits<T>::has_trivial_destructor trivial_destructor;
  __destroy_aux(first, last, trivial_destructor());
}

template <class ForwardIterator>
inline void destroy(ForwardIterator first, ForwardIterator last) {
  __destroy(first, last, value_type(first));
}

/*
 * destroy()针对char*和wchar_t*的特化版
 */
inline void destroy(char*, char*) {}
inline void destroy(wchar_t*, wchar_t*) {}