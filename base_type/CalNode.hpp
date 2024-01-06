#pragma once

#include "Operation.hpp"

namespace autodiff {

namespace node {

template <typename _ValueTy> struct CalNode {
  const _ValueTy &value;
};

/**
 * link two nodes from `_LNode` to `_RNode`
 */
template <typename _Operation, typename _LNode, typename _RNode>
constexpr auto link() {
  return op::OperationTriple<_Operation, _LNode, _RNode>{};
}

} // namespace node
} // namespace autodiff