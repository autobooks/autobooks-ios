///
/// \file VTPAuthorizationResponse.h
///

#ifndef VTPAuthorizationResponse_h
#define VTPAuthorizationResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseTipAmount.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseCardVerification.h"
#import "VTPFinancialResponseEmv.h"
#import "VTPFinancialResponseHost.h"
#import "VTPStoreAndForwardResponse.h"

///
/// \class VTPAuthorizationResponse
///
/// \brief The definition of the authorization response
///
@interface VTPAuthorizationResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseTipAmount, VTPFinancialResponseCard, VTPFinancialResponseCardVerification, VTPFinancialResponseEmv, VTPFinancialResponseHost, VTPStoreAndForwardResponse>

@end

#endif /* VTPAuthorizationResponse_h */
