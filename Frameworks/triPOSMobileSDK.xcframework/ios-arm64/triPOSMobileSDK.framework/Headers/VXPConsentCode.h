///
/// \file VXPConsentCode.h
///

#ifndef VXPConsentCode_h
#define VXPConsentCode_h

///
/// \enum VXPConsentCode
///
typedef enum _VXPConsentCode
{
    /// This field is not used
    VXPConsentCodeNotSet = VXPEnumNotSet,
    /// Not specified
    VXPConsentCodeNotSpecified = 0,
    /// Face-to-face
    VXPConsentCodeFaceToFace,
    /// Phone
    VXPConsentCodePhone,
    /// Internet
    VXPConsentCodeInternet,
}   VXPConsentCode;

#endif /* VXPConsentCode_h */
