///
/// \file VTPEncryptedSwipedCardData.h
///

#ifndef VTPEncryptedSwipedCardData_h
#define VTPEncryptedSwipedCardData_h

#import "VTPCardData.h"
#import "VTPCardDataEncryption.h"
#import "VTPSecurityCodeStatus.h"

///
/// \class VTPEncryptedSwipedCardData
///
/// \brief The encrypted swiped card data class
///
/// The encrypted swiped card data class.
///
@interface VTPEncryptedSwipedCardData : VTPCardData

///
/// \brief Encrypted track 1 data
///
/// Encrypted data block for track 1.
///
/// \sa encryptedTrack1KeySerialNumber, encryptedDataEncryption
///
@property (nonatomic, retain) NSString *encryptedTrack1;

///
/// \brief Encrypted track 1 key serial number
///
/// Key serial number for the encrypted track 1 block for this card data.
///
/// \sa encryptedTrack1, encryptedDataEncryption
///
@property (nonatomic, retain) NSString *encryptedTrack1KeySerialNumber;

///
/// \brief Encrypted track 2 data
///
/// Encrypted data block for track 2.
///
/// \sa encryptedTrack2KeySerialNumber, encryptedDataEncryption
///
@property (nonatomic, retain) NSString *encryptedTrack2;

///
/// \brief Encrypted track 2 key serial number
///
/// Key serial number for the encrypted track 2 block for this card data.
///
/// \sa encryptedTrack2, encryptedDataEncryption
///
@property (nonatomic, retain) NSString *encryptedTrack2KeySerialNumber;

///
/// \brief Encrypted data encryption
///
/// Encrypted card data encryption.
///
/// \sa encryptedTrack1, encryptedTrack1KeySerialNumber, encryptedTrack2, encryptedTrack2KeySerialNumber
///
@property (nonatomic) VTPCardDataEncryption encryptedDataEncryption;

///
/// \brief Masked track 1 data
///
/// Masked track 1 data including sentinels and checksum.
///
@property (nonatomic, retain) NSString *maskedTrack1;

///
/// \brief Masked track 2 data
///
/// Masked track 2 data including sentinels and checksum.
///
@property (nonatomic, retain) NSString *maskedTrack2;

@end

#endif /* VTPEncryptedSwipedCardData_h */
