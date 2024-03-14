///
/// \file VTPGiftCardUnloadRequest.h
///

#ifndef VTPGiftCardUnloadRequest_h
#define VTPGiftCardUnloadRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPAddressRequest.h"

///
/// \class VTPGiftCardUnloadRequest
///
/// \brief The definition for a gift card unload request
///
@interface VTPGiftCardUnloadRequest : NSObject <VTPFinancialRequestBase, VTPAddressRequest>

@end

#endif /* VTPGiftCardUnloadRequest_h */
