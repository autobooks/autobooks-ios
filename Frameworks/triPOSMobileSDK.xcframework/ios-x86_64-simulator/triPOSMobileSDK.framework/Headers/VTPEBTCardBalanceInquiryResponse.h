///
/// \file VTPEBTCardBalanceInquiryResponse.h
///

#ifndef VTPEBTCardBalanceInquiryResponse_h
#define VTPEBTCardBalanceInquiryResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseHost.h"

///
/// \class VTPEBTCardBalanceInquiryResponse
///
/// \brief The definition of the sale response
///
@interface VTPEBTCardBalanceInquiryResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCard, VTPFinancialResponseHost>

@end

#endif /* VTPEBTCardBalanceInquiryResponse_h */
