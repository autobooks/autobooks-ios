///
/// \file VTPEncryptedContactlessIccCardData.h
///

#ifndef VTPEncryptedContactlessIccCardData_h
#define VTPEncryptedContactlessIccCardData_h

#include "VTPContactlessIccCardData.h"
#include "VTPEmvDataEncryption.h"

///
/// \class VTPEncryptedContactlessIccCardData
///
/// \brief The encrypted ICC card data class
///
/// The encrypted ICC card data class.
///
@interface VTPEncryptedContactlessIccCardData : VTPContactlessIccCardData

///
/// \brief Gets or sets the encrypted data.
///
/// This property gets or sets the encrypted data.
///
@property (retain, nonatomic) NSString *encryptedData;

///
/// \brief Gets or sets the encrypted data key serial number
///
/// This property gets or set the encrypted data key serial number.
///
@property (retain, nonatomic) NSString *encryptedDataKeySerialNumber;

///
/// \brief Gets or sets the encrypted data encryption
///
/// This property gets or sets the encrypted data encryption.
///
@property (nonatomic) VTPEmvDataEncryption encryptedDataEncryption;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

+(VTPEncryptedContactlessIccCardData *)encryptedContactlessIccCardDataWithTags:(VTCTlvCollection)tags;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPEncryptedContactlessIccCardData_h */
