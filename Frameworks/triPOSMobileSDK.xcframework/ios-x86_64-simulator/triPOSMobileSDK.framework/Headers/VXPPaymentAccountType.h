///
/// \file VXPPaymentAccountType.h
///

#ifndef VXPPaymentAccountType_h
#define VXPPaymentAccountType_h

///
/// \enum VXPPaymentAccountType
///
typedef enum _VXPPaymentAccountType
{
    /// This field is not used
    VXPPaymentAccountTypeNotSet = VXPEnumNotSet,
    /// Credit card
    VXPPaymentAccountTypeCreditCard = 0,
    /// Checking account
    VXPPaymentAccountTypeChecking,
    /// Savings account
    VXPPaymentAccountTypeSavings,
    /// ACH
    VXPPaymentAccountTypeACH,
    /// Other
    VXPPaymentAccountTypeOther,
}   VXPPaymentAccountType;

#endif /* VXPPaymentAccountType_h */
