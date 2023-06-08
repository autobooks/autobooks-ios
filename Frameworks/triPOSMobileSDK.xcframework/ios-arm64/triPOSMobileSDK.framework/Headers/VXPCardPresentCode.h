///
/// \file VXPCardPresentCode.h
///

#ifndef VXPCardPresentCode_h
#define VXPCardPresentCode_h

///
/// \enum VXPCardPresentCode
///
typedef enum _VXPCardPresentCode
{
    /// This field is not used
    VXPCardPresentCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPCardPresentCodeDefault = 0,
    /// Unknown
    VXPCardPresentCodeUnknown,
    /// Present
    VXPCardPresentCodePresent,
    /// Not present
    VXPCardPresentCodeNotPresent,
}   VXPCardPresentCode;

#endif /* VXPCardPresentCode_h */
