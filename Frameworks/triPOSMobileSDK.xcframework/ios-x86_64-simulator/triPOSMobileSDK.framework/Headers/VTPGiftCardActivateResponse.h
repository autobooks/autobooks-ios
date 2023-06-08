///
/// \file VTPGiftCardActivateResponse.h
///

#ifndef VTPGiftCardActivateResponse_h
#define VTPGiftCardActivateResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseHost.h"
#import "VTPValutecRewardsResponse.h"

///
/// \class VTPGiftCardActivateResponse
///
/// \brief The definition of the sale response
///
@interface VTPGiftCardActivateResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCard, VTPFinancialResponseHost, VTPValutecRewardsResponse>

@end

#endif /* VTPGiftCardActivateResponse_h */
