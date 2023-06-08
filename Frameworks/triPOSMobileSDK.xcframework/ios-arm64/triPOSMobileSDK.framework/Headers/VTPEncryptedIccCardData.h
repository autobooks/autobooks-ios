///
/// \file VTPEncryptedIccCardData.h
///

#ifndef VTPEncryptedIccCardData_h
#define VTPEncryptedIccCardData_h

#include "VTPIccCardData.h"
#include "VTPEmvDataEncryption.h"

///
/// \class VTPEncryptedIccCardData
///
/// \brief The encrypted ICC card data class
///
/// The encrypted ICC card data class.
///
@interface VTPEncryptedIccCardData : VTPIccCardData

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

+(VTPEncryptedIccCardData *)encryptedIccCardDataWithTags:(VTCTlvCollection)tags;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPEncryptedIccCardData_h */
