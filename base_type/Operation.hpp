#pragma once

#include "CalGraph.hpp"
#include <vcruntime.h>

namespace autodiff {
namespace operation {

template <typename _Operation, typename _LNode, typename _RNode>
struct OperationTriple {
  using op_type = _Operation;
  using ltype = _LNode;
  using rtype = _RNode;
};

template <size_t _Size, typename... _Item> struct LinkTable;

template <size_t _Size, typename _OneItem, typename... _Item>
struct LinkTable<_Size, _OneItem, _Item...> {};

template <typename... _OperationTriple> struct OutTable {};

template <typename... _OperationTriple> struct InTable {};

} // namespace operation
} // namespace autodiff