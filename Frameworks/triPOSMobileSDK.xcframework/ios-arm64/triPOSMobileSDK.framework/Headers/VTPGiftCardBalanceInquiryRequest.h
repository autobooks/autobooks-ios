///
/// \file VTPGiftCardBalanceInquiryRequest.h
///

#ifndef VTPGiftCardBalanceInquiryRequest_h
#define VTPGiftCardBalanceInquiryRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPAddressRequest.h"
#import "VTPGiftProgramRequest.h"

///
/// \class VTPGiftCardBalanceInquiryRequest
///
/// \brief The definition for a refund request
///
@interface VTPGiftCardBalanceInquiryRequest : NSObject <VTPFinancialRequestBase, VTPAddressRequest, VTPGiftProgramRequest>

@end

#endif /* VTPGiftCardBalanceInquiryRequest_h */
