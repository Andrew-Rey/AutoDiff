#include <cstddef>
#include <iostream>
#include <stack>
#include <type_traits>

#include "./base_type/Expr.hpp"

using item1 = Item<10, 5, float>;
using item2 = Item<10, 4, float>;
using item3 = Item<10, 3, float>;

// sub1 = 10/5 * 10/4 = 5.0
using sub1 = SubExpr<2, float, item1, item2>;
// sub2 = sub1 * 10/3 = 5.0 * 10/3
using sub2 = SubExpr<2, float, item3, sub1>;
// sub1 + sub2 = 5.0 + 5.0 * 10/3
using expr = Expr<2, float, sub1, sub2>;

template <typename _ValueTy, typename _Expr>
void runtime_cout() {
  std::stack<_ValueTy> vs{};
  using is_single = typename _Expr::is_single;
  while (std::is_same<is_single, std::false_type>::value) {
    using ltype = typename _Expr::ltype;
    using rtype = typename _Expr::rtype;
    vs.push(rtype::value);
    using is_single = typename ltype::is_single;
    std::cout << typeid(ltype).name() << std::endl;
  }
  while (!vs.empty()) {
    std::cout << vs.top() << " + ";
    vs.pop();
  }
  std::cout << " = " << _Expr::value << std::endl;
}

int main() {
  runtime_cout<float, expr>();
  return 0;
}
