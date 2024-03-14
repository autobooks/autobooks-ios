///
/// \file VXPTokenProvider.h
///

#ifndef VXPTokenProvider_h
#define VXPTokenProvider_h

///
/// \enum VXPTokenProvider
///
typedef enum _VXPTokenProvider
{
    /// This field is not used
    VXPTokenProviderNotSet = VXPEnumNotSet,
    /// Null
    VXPTokenProviderNull = 0,
    /// ExpressPASS
    VXPTokenProviderExpressPass,
    /// OmniToken
    VXPTokenProviderOmniToken,
    /// Paymetric
    VXPTokenProviderPaymetric,
    /// TransArmor
    VXPTokenProviderTransArmor,
}   VXPTokenProvider;

#endif /* VXPTokenProvider_h */
