#pragma once

#include <cstdlib>
#include <type_traits>
#include <vcruntime.h>

namespace autodiff {

namespace graph {

/**
 * calculation graph
 * define graph size and expression
 * - (which includes operation, left-node, right-node)
 * store graph with adjacent matrix
 */
template <size_t _Size, typename... _Expr> struct CalGraph {
  const size_t node_size = _Size;
};

// /**
//  * store all calculational nodes with a sorted order
//  */
// template <size_t _Size, typename _Node> struct CalGraph {
//   const _Node curr;
//   const CalGraph<_Size - 1, _Node> next;
// };

// template <typename _Node> struct CalGraph<0, _Node> {
//   const _Node curr;
// };

// struct EndofGraph {};
// constexpr EndofGraph eog = {};

// /**
//  * dueduction guide
//  */
// template <typename _Node> CalGraph(_Node) -> CalGraph<0, _Node>;
// template <size_t _Size, typename _Node>
// CalGraph(_Node, CalGraph<_Size, _Node>) -> CalGraph<_Size + 1, _Node>;

// /**
//  * insert node into the graph
//  */
// template <size_t _Size, typename _Node>
// constexpr auto operator>>=(const _Node &node,
//                            const CalGraph<_Size, _Node> &graph)
//     -> CalGraph<_Size + 1, _Node> {
//   return CalGraph{node, graph};
// }

// template <typename _Node>
// constexpr auto operator>>=(const _Node &node, const EndofGraph &)
//     -> CalGraph<0, _Node> {
//   return CalGraph{node};
// }

} // namespace graph
} // namespace autodiff