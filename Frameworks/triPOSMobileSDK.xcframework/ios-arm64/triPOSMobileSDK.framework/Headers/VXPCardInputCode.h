///
/// \file VXPCardInputCode.h
///

#ifndef VXPCardInputCode_h
#define VXPCardInputCode_h

///
/// \enum VXPCardInputCode
///
typedef enum _VXPCardInputCode
{
    /// This field is not used
    VXPCardInputCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPCardInputCodeDefault = 0,
    /// Unknown
    VXPCardInputCodeUnknown,
    /// Magnetic stripe read
    VXPCardInputCodeMagstripeRead,
    /// Contactless card read
    VXPCardInputCodeContactlessMagstripeRead,
    /// Manually keyed
    VXPCardInputCodeManualKeyed,
    /// Manually keyed, magnetic stripe failure
    VXPCardInputCodeManualKeyedMagstripeFailure,
    /// Contact ICC
    VXPCardInputCodeChipRead,
    /// Contactless ICC
    VXPCardInputCodeContactlessChipRead,
    /// Manually keyed, chip read failure
    VXPCardInputCodeManualKeyedChipReadFailure,
    /// Magnetic stripe read, chip read failure
    VXPCardInputCodeMagstripeReadChipReadFailure,
    /// Magstripe Read Non-Technical Fallback
    VXPCardInputCodeMagstripeReadNonTechnicalFallback,
    /// Apple Tap to Pay or other soft POS/tap on COTS
    VXPCardInputCodeSoftPos,
}   VXPCardInputCode;

#endif /* VXPCardInputCode_h */
