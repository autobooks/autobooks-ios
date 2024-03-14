///
/// \file VTPEBTCardBalanceInquiryRequest.h
///

#ifndef VTPEBTCardBalanceInquiryRequest_h
#define VTPEBTCardBalanceInquiryRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPAddressRequest.h"

///
/// \class VTPEBTCardBalanceInquiryRequest
///
/// \brief The definition for a refund request
///
@interface VTPEBTCardBalanceInquiryRequest : NSObject <VTPFinancialRequestBase, VTPAddressRequest>

@end

#endif /* VTPEBTCardBalanceInquiryRequest_h */
