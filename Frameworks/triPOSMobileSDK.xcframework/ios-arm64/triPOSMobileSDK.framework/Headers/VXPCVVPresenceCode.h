///
/// \file VXPCVVPresenceCode.h
///

#ifndef VXPCVVPresenceCode_h
#define VXPCVVPresenceCode_h

///
/// \enum VXPCVVPresenceCode
///
typedef enum _VXPCVVPresenceCode
{
    /// This field is not used
    VXPCVVPresenceCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPCVVPresenceCodeDefault = 0,
    /// Not provided
    VXPCVVPresenceCodeNotProvided,
    /// Provided
    VXPCVVPresenceCodeProvided,
    /// Illegible
    VXPCVVPresenceCodeIllegible,
    /// Customer illegible
    VXPCVVPresenceCodeCustomerIllegible,
}   VXPCVVPresenceCode;

#endif /* VXPCVVPresenceCode_h */
