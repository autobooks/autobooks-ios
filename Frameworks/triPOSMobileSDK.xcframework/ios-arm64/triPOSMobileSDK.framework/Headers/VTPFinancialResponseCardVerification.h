///
/// \file VTPFinancialResponseCardVerification.h
///

#ifndef VTPFinancialResponseCardVerification_h
#define VTPFinancialResponseCardVerification_h

#import "VTPCardVerificationData.h"

///
/// \protocol VTPFinancialResponseCardVerification
///
/// \brief The protocol that defines the card verification data returned in some financial responses
///
@protocol VTPFinancialResponseCardVerification

///
/// \brief Gets the card verification data
///
/// This property contains the card verification data for this transaction.
///
@property (retain, nonatomic) VTPCardVerificationData *cardVerification;

@end

#endif /* VTPFinancialResponseCardVerification_h */
