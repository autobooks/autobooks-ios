///
/// \file VXPMotoECICode.h
///

#ifndef VXPMotoECICode_h
#define VXPMotoECICode_h

///
/// \enum VXPMotoECICode
///
typedef enum _VXPMotoECICode
{
    /// This field is not used
    VXPMotoECICodeNotSet = VXPEnumNotSet,
    /// Default
    VXPMotoECICodeDefault = 0,
    /// Not used
    VXPMotoECICodeNotUsed,
    /// Single
    VXPMotoECICodeSingle,
    /// Recurring
    VXPMotoECICodeRecurring,
    /// Installment
    VXPMotoECICodeInstallment,
    /// Secure e-commerce
    VXPMotoECICodeSecureElectronicCommerce,
    /// Non-authenticated secure transaction
    VXPMotoECICodeNonAuthenticatedSecureTransaction,
    /// Non-authenticated secure e-commerce transaction
    VXPMotoECICodeNonAuthenticatedSecureECommerceTransaction,
    /// Non-secure e-commerce transaction
    VXPMotoECICodeNonSecureECommerceTransaction,
}   VXPMotoECICode;

#endif /* VXPMotoECICode_h */
