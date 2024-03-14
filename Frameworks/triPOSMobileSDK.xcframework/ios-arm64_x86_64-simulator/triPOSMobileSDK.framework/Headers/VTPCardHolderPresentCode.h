///
/// \file VTPCardHolderPresentCode.h
///

#ifndef VTPCardHolderPresentCode_h
#define VTPCardHolderPresentCode_h

///
/// \enum VTPCardHolderPresentCode
///
typedef enum _VTPCardHolderPresentCode
{
    /// Default
    VTPCardHolderPresentCodeDefault,
    /// Unknown
    VTPCardHolderPresentCodeUnknown,
    /// Present
    VTPCardHolderPresentCodePresent,
    /// Not present
    VTPCardHolderPresentCodeNotPresent,
    /// Mail order
    VTPCardHolderPresentCodeMailOrder,
    /// Phone order
    VTPCardHolderPresentCodePhoneOrder,
    /// Standing authorization
    VTPCardHolderPresentCodeStandingAuthorization,
    /// E-commerce
    VTPCardHolderPresentCodeECommerce,
}   VTPCardHolderPresentCode;

#endif /* VTPCardHolderPresentCode_h */
