///
/// \file VTPGiftCardBalanceInquiryResponse.h
///

#ifndef VTPGiftCardBalanceInquiryResponse_h
#define VTPGiftCardBalanceInquiryResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseHost.h"
#import "VTPValutecRewardsResponse.h"

///
/// \class VTPGiftCardBalanceInquiryResponse
///
/// \brief The definition of the sale response
///
@interface VTPGiftCardBalanceInquiryResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCard, VTPFinancialResponseHost, VTPValutecRewardsResponse>

@end

#endif /* VTPGiftCardBalanceInquiryResponse_h */
