//
//  VTPGiftCardCloseRequest.h
//  triPOSMobileSDK
//
//  Created on 1/13/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPGiftCardCloseRequest_h
#define VTPGiftCardCloseRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPAddressRequest.h"
#import "VTPGiftProgramRequest.h"

///
/// \class VTPGiftCardUnloadRequest
///
/// \brief The definition for a gift card unload request
///
@interface VTPGiftCardCloseRequest : NSObject <VTPFinancialRequestBase, VTPAddressRequest, VTPGiftProgramRequest>

@end

#endif /* VTPGiftCardCloseRequest_h */
