#include <cmath>
#include <cstddef>
#include <iostream>
#include <array>
using namespace std;

template<uint64_t N>
constexpr uint64_t Value()
{
    return N + 100;
}

// recursive case
template<uint64_t N, uint64_t... args>
struct Array : Array<N - 1, Value<N - 1>(), args...> {
};

// base case
template<uint64_t... args>
struct Array<0, Value<0>(), args...> {
    static std::array<uint64_t, sizeof...(args) + 1> data;
};

template<uint64_t... args>
std::array<uint64_t, sizeof...(args) + 1> Array<0, Value<0>(), args...>::data = {Value<0>(), args...};

int main()
{
    Array<10> myArray;
    for (size_t i = 0; i < myArray.data.size(); ++i) {
        cout << myArray.data[i] << endl;
    }

    return 0;
}

// /**
//  * left recursive
//  * expr -> expr + sub_expr | sub_expr
//  * sub_expr -> sub_expr * item | item
//  * item -> [0-9]
//  */

// template <size_t N, typename... Expr>
// struct MetaExpr {
//   static const int value = MetaExpr<N, Expr...>::value;
// };

// template <size_t N, typename SubExpr, typename... Expr>
// struct MetaExpr<N, SubExpr, Expr...> {
//   static const int value = SubExpr::value + MetaExpr<N - 1, Expr...>::value;
// };

// template <typename SubExpr, typename... Expr>
// struct MetaExpr<1, SubExpr, Expr...> {
//   static const int value = SubExpr::value;
// };

// template <size_t N, typename... SubExpr>
// struct MetaSubExpr {
//   static const int value = MetaSubExpr<N, SubExpr...>::value;
// };

// template <typename Item, typename... SubExpr>
// struct MetaSubExpr<1, Item, SubExpr...> {
//   static const int value = Item::value;
// };

// template <size_t N, typename Item, typename... SubExpr>
// struct MetaSubExpr<N, Item, SubExpr...> {
//   static const int value = Item::value * MetaSubExpr<N - 1, SubExpr...>::value;
// };

// template <int V>
// struct Item {
//   static const int value = V;
// };

// template <typename Expr>
// constexpr auto rtCout() {
//   std::cout << Expr::value << std::endl;
// }

// using item1 = Item<1>;
// using item2 = Item<2>;
// using item3 = Item<5>;

// using sub1 = MetaSubExpr<2, item2, item3>;
// using sub2 = MetaSubExpr<2, item2, sub1>;

// // 2 * 5 + 2 * (2 * 5)
// using expr = MetaExpr<2, sub1, sub2>;

// int main() {
//   rtCout<expr>();
//   return 0;
// }