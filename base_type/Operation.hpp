// #pragma once

// // #include "__decl__.hpp"
// #include "Expr.hpp"

// /**
//  * @brief the virtual base class of binary operations
//  * every binary operation should inherit it and realize the pure virtual
//  * function value()
//  *
//  * @tparam TOperate the operation function
//  * @tparam TLHS left hand side type
//  * @tparam TRHS right hand side type
//  * @tparam TValue element value type
//  */
// template <typename TOperate, typename TLhs, typename TRlhs, typename TValue = float>
// struct BinaryOperate : public Expr<BinaryOperate<TOperate, TLhs, TRlhs, TValue>> {
//   /**
//    * @brief delayed evaluation
//    *
//    * @return TValue the element value
//    */
//   virtual TValue value() = 0;
// };

