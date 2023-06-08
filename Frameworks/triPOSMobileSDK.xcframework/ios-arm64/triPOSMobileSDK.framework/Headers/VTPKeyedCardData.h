///
/// \file VTPKeyedCardData.h
///

#ifndef VTPKeyedCardData_h
#define VTPKeyedCardData_h

#import "VTPCardData.h"
#import "VTPSecurityCodeStatus.h"

///
/// \class VTPKeyedCardData
///
/// \brief The keyed card data class
///
/// The keyed card data class.
///
@interface VTPKeyedCardData : VTPCardData

///
/// \brief Account number
///
/// Account number for this card data. This property is masked if the card data is encrypted.
///
@property (nonatomic, retain) NSString *accountNumber;

///
/// \brief Expiration date
///
/// Expiration date for this card data. This property may be masked if the card data is encrypted.
///
@property (nonatomic, retain) NSString *expirationDate;

///
/// \brief Security code status
///
/// The status of the security code.
///
/// \sa securityCode
///
@property (nonatomic) VTPSecurityCodeStatus securityCodeStatus;

///
/// \brief Security code
///
/// The manually keyed security code. This property is nil or masked if the card data is encrypted.
///
/// \sa securityCodeStatus
///
@property (nonatomic, retain) NSString *securityCode;

@end

#endif /* VTPKeyedCardData_h */
