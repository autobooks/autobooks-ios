///
/// \file VXPHealthcareAccountType.h
///

#ifndef VXPHealthcareAccountType_h
#define VXPHealthcareAccountType_h

///
/// \enum VXPHealthcareAccountType
///
typedef enum _VXPHealthcareAccountType
{
    /// This field is not used
    VXPHealthcareAccountTypeNotSet = VXPEnumNotSet,
    /// Not specified
    VXPHealthcareAccountTypeNotSpecified = 0,
    /// Savings account
    VXPHealthcareAccountTypeSavings,
    /// Checking account
    VXPHealthcareAccountTypeChecking,
    /// Credit card
    VXPHealthcareAccountTypeCreditCard,
    /// Universal
    VXPHealthcareAccountTypeUniversal,
    /// Stored value account
    VXPHealthcareAccountTypeStoredValueAccount,
    /// Cash benefits account
    VXPHealthcareAccountTypeCashBenefitsAccount,
    /// Food stamps account
    VXPHealthcareAccountTypeFoodStampsAccount,
}   VXPHealthcareAccountType;

#endif /* VXPHealthcareAccountType_h */
