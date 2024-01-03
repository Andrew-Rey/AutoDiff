#include <cmath>
#include <cstddef>
#include <iostream>

/**
 * left recursive
 * expr -> expr + sub_expr | sub_expr
 * sub_expr -> sub_expr * item | item
 * item -> [0-9]
 */

template <size_t N, typename... Expr>
struct MetaExpr {
  static const int value = MetaExpr<N, Expr...>::value;
};

template <size_t N, typename SubExpr, typename... Expr>
struct MetaExpr<N, SubExpr, Expr...> {
  static const int value = SubExpr::value + MetaExpr<N - 1, Expr...>::value;
};

template <typename SubExpr, typename... Expr>
struct MetaExpr<1, SubExpr, Expr...> {
  static const int value = SubExpr::value;
};

template <size_t N, typename... SubExpr>
struct MetaSubExpr {
  static const int value = MetaSubExpr<N, SubExpr...>::value;
};

template <typename Item, typename... SubExpr>
struct MetaSubExpr<1, Item, SubExpr...> {
  static const int value = Item::value;
};

template <size_t N, typename Item, typename... SubExpr>
struct MetaSubExpr<N, Item, SubExpr...> {
  static const int value = Item::value * MetaSubExpr<N - 1, SubExpr...>::value;
};

template <int V>
struct Item {
  static const int value = V;
};

template <typename Expr>
constexpr auto rtCout() {
  std::cout << Expr::value << std::endl;
}

using item1 = Item<1>;
using item2 = Item<2>;
using item3 = Item<5>;

using sub1 = MetaSubExpr<2, item2, item3>;
using sub2 = MetaSubExpr<2, item2, sub1>;

// 2 * 5 + 2 * (2 * 5)
using expr = MetaExpr<2, sub1, sub2>;

int main() {
  rtCout<expr>();
  return 0;
}