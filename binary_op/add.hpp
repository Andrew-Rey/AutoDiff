#pragma once
#include "../base_type/Operation.hpp"

template <typename TLhs, typename TRhs, typename TValue = float>
struct Add : public BinaryOperate<Add<TLhs, TRhs>, TLhs, TRhs, TValue> {
  const TLhs& _lhs;
  const TRhs& _rhs;
  const TValue& _result;
  inline TValue value() const { return this->_result = _lhs + _rhs; }
};