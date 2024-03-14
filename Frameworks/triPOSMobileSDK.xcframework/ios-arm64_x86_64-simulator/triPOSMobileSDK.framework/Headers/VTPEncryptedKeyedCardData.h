///
/// \file VTPEncryptedKeyedCardData.h
///

#ifndef VTPEncryptedKeyedCardData_h
#define VTPEncryptedKeyedCardData_h

#import "VTPCardData.h"
#import "VTPCardDataEncryption.h"
#import "VTPSecurityCodeStatus.h"

///
/// \class VTPEncryptedKeyedCardData
///
/// \brief The encrypted keyed card data class
///
/// The encrypted keyed card data class.
///
@interface VTPEncryptedKeyedCardData : VTPCardData

///
/// \brief Encrypted card data
///
/// Encrypted data block for this card data.
///
/// \sa encryptedDataKeySerialNumber, encryptedDataEncryption
///
@property (nonatomic, retain) NSString *encryptedData;

///
/// \brief Encrypted data key serial number
///
/// Key serial number for the encrypted data block for this card data.
///
/// \sa encryptedData, encryptedDataEncryption
///
@property (nonatomic, retain) NSString *encryptedDataKeySerialNumber;

///
/// \brief Encrypted data encryption
///
/// Encrypted card data encryption.
///
/// \sa encryptedData, encryptedDataKeySerialNumber
///
@property (nonatomic) VTPCardDataEncryption encryptedDataEncryption;

///
/// \brief Masked account number
///
/// Masked account number for this card data.
///
@property (nonatomic, retain) NSString *maskedAccountNumber;

///
/// \brief Expiration date
///
/// Expiration date for this card data.
///
@property (nonatomic, retain) NSString *expirationDate;

///
/// \brief Security code status
///
/// The status of the security code.
///
@property (nonatomic) VTPSecurityCodeStatus securityCodeStatus;

@end

#endif /* VTPEncryptedKeyedCardData_h */
