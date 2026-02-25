///
/// \file VTPEBTCardBalanceInquiryResponse.h
///

#ifndef VTPEBTCardBalanceInquiryResponse_h
#define VTPEBTCardBalanceInquiryResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseHost.h"
#import "VTPFinancialResponseEmv.h"

///
/// \class VTPEBTCardBalanceInquiryResponse
///
/// \brief The definition of the sale response
///
@interface VTPEBTCardBalanceInquiryResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCard, VTPFinancialResponseHost, VTPFinancialResponseEmv>

@end

#endif /* VTPEBTCardBalanceInquiryResponse_h */
