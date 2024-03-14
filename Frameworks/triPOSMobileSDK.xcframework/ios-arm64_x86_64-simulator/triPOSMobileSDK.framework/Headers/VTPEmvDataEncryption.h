///
/// \file VTPEmvDataEncryption.h
///

#ifndef VTPEmvDataEncryption_h
#define VTPEmvDataEncryption_h

///
/// \enum VTPEmvDataEncryption
///
/// EMV data encryption types.
///
typedef enum _VTPEmvDataEncryption
{
    /// No encryption
    VTPEmvDataEncryptionNone,
    /// Data variant, Mx9xx format
    VTPEmvDataEncryptionDataVariantEpsMxFormat,
    /// PIN variant, Mercury format
    VTPEmvDataEncryptionPinVariantMercuryFormat,
    /// Data variant, track 2 data
    VTPEmvDataEncryptionDataVariantTrack2Data,
    /// Apple Tap to Pay on iPhone
    VTPEmvDataEncryptionAppleTapToPay,
}   VTPEmvDataEncryption;

#endif /* VTPEmvDataEncryption_h */
