// #pragma once

// #include <vector>

// // #include "__decl__.hpp"

// #include "Expr.hpp"

// template <typename TValue>
// struct CalNode : public Expr<CalNode<TValue>> {
//   CalNode() = default;
//   CalNode(const TValue& value) : _value(value) {}
//   CalNode(const CalNode& other) : _value(other._value) {}
//   CalNode(TValue&& value) : _value(value) {}

//   inline TValue value() const { return _value; }

//   template <typename TSubExpr>
//   inline CalNode& operator=(const Expr<TSubExpr>& sub) {
//     const TSubExpr& src = sub.self();
//     this->_value = src.value();
//     return *this;
//   }

//  private:
//   TValue _value;
// };