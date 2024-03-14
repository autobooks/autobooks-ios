///
/// \file VPDNull+CardInput.h
///

#import <Foundation/Foundation.h>

#ifndef VPDNull_CardInput_h
#define VPDNull_CardInput_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDCardInput.h"
#import "VPDNull.h"

extern NSString * const VPDNullCardInputKeyedAccountNumber;
extern NSString * const VPDNullCardInputKeyedExpirationDate;
extern NSString * const VPDNullCardInputKeyedSecurityCode;
extern NSString * const VPDNullCardInputKeyedEncrypted;
extern NSString * const VPDNullCardInputKeyedAccountNumberMasked;

extern NSString * const VPDNullCardInputTrack1;
extern NSString * const VPDNullCardInputTrack1Encrypted;
extern NSString * const VPDNullCardInputTrack1Masked;

extern NSString * const VPDNullCardInputTrack2;
extern NSString * const VPDNullCardInputTrack2Encrypted;
extern NSString * const VPDNullCardInputTrack2Masked;

extern NSString * const VPDNullCardInputTrackKsn;
extern const VTPCardDataEncryption VPDNullCardInputTrackEncryptedFormat;

@interface VPDNull(CardInput) <VPDCardInput>

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDNull_CardInput_h */