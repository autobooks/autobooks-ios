///
/// \file VXPTransactionSetupMethod.h
///

#ifndef VXPTransactionSetupMethod_h
#define VXPTransactionSetupMethod_h

///
/// \enum VXPTransactionSetupMethod
///
typedef enum _VXPTransactionSetupMethod
{
    /// This field is not used
    VXPTransactionSetupMethodNotSet = VXPEnumNotSet,
    /// Default
    VXPTransactionSetupMethodDefault = 0,
    /// Credit card sale
    VXPTransactionSetupMethodCreditCardSale,
    /// Credit card authorization
    VXPTransactionSetupMethodCreditCardAuthorization,
    /// Credit card AVS only
    VXPTransactionSetupMethodCreditCardAVSOnly,
    /// Credit card force
    VXPTransactionSetupMethodCreditCardForce,
    /// Debit card sale
    VXPTransactionSetupMethodDebitCardSale,
    /// Check sale
    VXPTransactionSetupMethodCheckSale,
    /// Payment account create
    VXPTransactionSetupMethodPaymentAccountCreate,
    /// Payment account update
    VXPTransactionSetupMethodPaymentAccountUpdate,
    /// Sale
    VXPTransactionSetupMethodSale,
}   VXPTransactionSetupMethod;

#endif /* VXPTransactionSetupMethod_h */
