///
/// \file VTPCardVerificationData.h
///

#ifndef VTPCardVerificationData_h
#define VTPCardVerificationData_h

///
/// \brief The protocol that defines the card verification data returned in some financial responses
///
@interface VTPCardVerificationData : NSObject

///
/// \brief Gets the AVS response code
///
/// This property contains the AVS response code for this transaction. This property is only populated if the card data is manually entered and AVS is enabled.
///
@property (retain, nonatomic) NSString *avsResponseCode;

///
/// \brief Gets the CVV response code
///
/// This property contains the CVV response code for this transaction. This property is only populated if the card data is manually entered.
///
@property (retain, nonatomic) NSString *cvvResponseCode;

@end

#endif /* VTPCardVerificationData_h */
