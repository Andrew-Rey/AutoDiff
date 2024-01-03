#include <cstddef>
#include <iostream>
#include <stack>
#include <type_traits>

#include "./base_type/Expr.hpp"

using item1 = Item<1012, 51, float>;
using item2 = Item<34, 12, float>;
using item3 = Item<1612, 223, float>;

// sub1 = 10/5 * 10/4 = 5.0
using sub1 = SubExpr<2, float, item1, item2>;
// sub2 = sub1 * 10/3 = 5.0 * 10/3
using sub2 = SubExpr<2, float, item3, sub1>;
// sub1 + sub2 = 5.0 + 5.0 * 10/3
using expr = Expr<2, float, sub1, sub2>;

template <typename _Expr> void runtime_cout() {
  std::cout << _Expr::value << std::endl;
}

int main() {
  runtime_cout<expr>();
  return 0;
}
