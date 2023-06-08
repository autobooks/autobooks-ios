///
/// \file VXPCardHolderPresentCode.h
///

#ifndef VXPCardHolderPresentCode_h
#define VXPCardHolderPresentCode_h

///
/// \enum VXPCardHolderPresentCode
///
typedef enum _VXPCardHolderPresentCode
{
    /// This field is not used
    VXPCardHolderPresentCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPCardHolderPresentCodeDefault = 0,
    /// Unknown
    VXPCardHolderPresentCodeUnknown,
    /// Present
    VXPCardHolderPresentCodePresent,
    /// Not present
    VXPCardHolderPresentCodeNotPresent,
    /// Mail order
    VXPCardHolderPresentCodeMailOrder,
    /// Phone order
    VXPCardHolderPresentCodePhoneOrder,
    /// Standing authorization
    VXPCardHolderPresentCodeStandingAuthorization,
    /// E-commerce
    VXPCardHolderPresentCodeECommerce,
}   VXPCardHolderPresentCode;

#endif /* VXPCardHolderPresentCode_h */
