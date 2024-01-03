#pragma once

#include <cstddef>
#include <type_traits>
#include <utility>

/**
 * @brief for a simple example, define the syntax with left-recursive:
 * Expr -> Expr * SubExpr | SubExpr
 * SubExpr -> SubExpr + Item | Item
 */

/**
 * @brief expression definition
 */

template <size_t _SubExprNum, typename _ValueTy, typename... _Expr>
struct Expr;

template <typename _ValueTy>
struct Expr<0, _ValueTy> {
  using is_single = std::true_type;
};

template <typename _ValueTy>
using EmptyExpr = Expr<0, _ValueTy>;

template <size_t _SubExprNum, typename _ValueTy, typename _SubExpr,
          typename... _Expr>
struct Expr<_SubExprNum, _ValueTy, _SubExpr, _Expr...> {
  using is_single = std::false_type;
  using ltype = Expr<_SubExprNum - 1, _ValueTy, _Expr...>;
  using rtype = _SubExpr;
  static constexpr _ValueTy value =
      _SubExpr::value + Expr<_SubExprNum - 1, _ValueTy, _Expr...>::value;
};

template <typename _ValueTy, typename _SubExpr, typename... _Expr>
struct Expr<1, _ValueTy, _SubExpr, _Expr...> {
  using is_single = std::true_type;
  using ltype = EmptyExpr<_ValueTy>;
  using rtype = _SubExpr;
  static constexpr _ValueTy value = _SubExpr::value;
};

/**
 * @brief sub-expression definition
 */

template <size_t _ItemNum, typename _ValueTy, typename... _SubExpr>
struct SubExpr;

template <typename _ValueTy>
struct SubExpr<0, _ValueTy> {
  using is_single = std::true_type;
};

template <typename _ValueTy>
using EmptySubExpr = SubExpr<0, _ValueTy>;

template <size_t _ItemNum, typename _ValueTy, typename _Item,
          typename... _SubExpr>
struct SubExpr<_ItemNum, _ValueTy, _Item, _SubExpr...> {
  using is_single = std::false_type;
  using ltype = SubExpr<_ItemNum - 1, _ValueTy, _SubExpr...>;
  using rtype = _Item;
  static constexpr _ValueTy value =
      _Item::value * SubExpr<_ItemNum - 1, _ValueTy, _SubExpr...>::value;
};

template <typename _ValueTy, typename _Item, typename... _SubExpr>
struct SubExpr<1, _ValueTy, _Item, _SubExpr...> {
  using is_single = std::true_type;
  using ltype = EmptySubExpr<_ValueTy>;
  using rtype = _Item;
  static constexpr _ValueTy value = _Item::value;
};

template <size_t _Numerator, size_t _Denominator, typename _ValueTy>
struct Item {
  static constexpr _ValueTy value =
      std::is_floating_point<_ValueTy>::value
          ? (_ValueTy)_Numerator / (_ValueTy)_Denominator
          : _Numerator;
};