///
/// \file VTPGiftCardActivateRequest.h
///

#ifndef VTPGiftCardActivateRequest_h
#define VTPGiftCardActivateRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPAddressRequest.h"
#import "VTPGiftProgramRequest.h"


///
/// \class VTPGiftCardActivateRequest
///
/// \brief The definition for a refund request
///
@interface VTPGiftCardActivateRequest : NSObject <VTPFinancialRequestBase, VTPFinancialRequestAmounts, VTPAddressRequest, VTPGiftProgramRequest>

@end

#endif /* VTPGiftCardActivateRequest_h */
