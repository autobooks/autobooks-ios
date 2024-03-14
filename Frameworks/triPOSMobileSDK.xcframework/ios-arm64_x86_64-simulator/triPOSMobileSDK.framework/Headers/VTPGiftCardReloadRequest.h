///
/// \file VTPGiftCardReloadRequest.h
///

#ifndef VTPGiftCardReloadRequest_h
#define VTPGiftCardReloadRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPAddressRequest.h"
#import "VTPGiftProgramRequest.h"

///
/// \class VTPGiftCardReloadRequest
///
/// \brief The definition for a refund request
///
@interface VTPGiftCardReloadRequest : NSObject <VTPFinancialRequestBase, VTPFinancialRequestAmounts, VTPAddressRequest, VTPGiftProgramRequest>

@end

#endif /* VTPGiftCardReloadRequest_h */
