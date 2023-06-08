///
/// \file VTPCardDataEncryption.h
///

#ifndef VTPCardDataEncryption_h
#define VTPCardDataEncryption_h

///
/// \enum VTPCardDataEncryption
///
/// Card data encryption types.
///
typedef enum _VTPCardDataEncryption
{
    /// No encryption
    VTPCardDataEncryptionNone,
    /// Data variant, EPS format
    VTPCardDataEncryptionDataVariantEpsFormat,
    /// PIN variant, EPS format
    VTPCardDataEncryptionPinVariantEpsFormat,
    /// PIN variant, Mercury format
    VTPCardDataEncryptionPinVariantMercuryFormat,
    /// Data variant, Mx9xx format
    VTPCardDataEncryptionDataVariantEpsMxFormat,
    /// UPP On-Guard SDE
    VTPCardDataEncryptionDataVariantTetraFormat,
    /// UPP TDES DUKPT Generic
    VTPCardDataEncryptionDataVariantTetraTDESFormat,
}   VTPCardDataEncryption;

#endif /* VTPCardDataEncryption_h */
