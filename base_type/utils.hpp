#pragma once

#include <corecrt.h>
#include <list>
namespace autodiff {

namespace utils {

namespace t_pair {

template <typename _First, typename _Second>
struct t_pair {
  using first = _First;
  using second = _Second;
};

}  // namespace t_pair

namespace t_list {

struct EMPTY_LIST {};
constexpr EMPTY_LIST None = {};
/**
 * @brief general case
 */
template <size_t _Size, typename _Ty>
struct t_list {
  const _Ty& cur;
  const t_list<_Size, _Ty>& next;
  const size_t length = _Size;
  using value_type = _Ty;

  
};

/**
 * @brief zero case
 */
template <typename _Ty>
struct t_list<0, _Ty> {};

template <typename _Ty>
t_list(_Ty) -> t_list<0, _Ty>;

template <size_t _Size, typename _Ty>
t_list(_Ty, t_list<_Size, _Ty>) -> t_list<_Size + 1, _Ty>;

/**
 * @brief add element into list
 */
template <size_t _Size, typename _Ty>
constexpr auto operator>>=(const _Ty& elem, const t_list<_Size, _Ty>& li)
    -> t_list<_Size + 1, _Ty> {
  return t_list{elem, li};
}

template <typename _Ty>
constexpr auto operator>>=(const _Ty& elem, const EMPTY_LIST&)
    -> t_list<1, _Ty> {
  return t_list{elem};
}

// template <typename _Iter, size_t _Idx>
// struct get {
//   const _Iter::value_type elem = 
// };

// template <typename _Iter>
// struct get<_Iter, 0> {};

}  // namespace t_list

}  // namespace utils
}  // namespace autodiff