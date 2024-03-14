///
/// \file VTPEncryptedContactlessMagneticStripeCardData.h
///

#ifndef VTPEncryptedContactlessMagneticStripeCardData_h
#define VTPEncryptedContactlessMagneticStripeCardData_h

#import "VTPEncryptedSwipedCardData.h"
#import "VTCTlvUtility.h"

///
/// \class VTPEncryptedContactlessMagneticStripeCardData
///
/// \brief The encrypted magnetic stripe card data class
///
/// The encrypted magnetic stripe card data class.
///
@interface VTPEncryptedContactlessMagneticStripeCardData : VTPEncryptedSwipedCardData

///
/// \brief Gets or sets the tags
///
/// This property gets or sets the tags.  Required for some MSD transactions.
///
@property (retain, nonatomic) VTCTlvCollection tags;

///
/// \brief Gets the application identifier
///
/// This property gets the application identifier.
///
@property (retain, nonatomic, readonly) NSString *applicationIdentifier;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

-(instancetype)initWithEncryptedSwipedCardData:(VTPEncryptedSwipedCardData *)encryptedSwipedCardData;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPEncryptedContactlessMagneticStripeCardData_h */
