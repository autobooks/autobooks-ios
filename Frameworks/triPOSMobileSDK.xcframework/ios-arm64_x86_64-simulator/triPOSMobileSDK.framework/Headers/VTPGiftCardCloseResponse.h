//
//  VTPGiftCardCloseResponse.h
//  triPOSMobileSDK
//
//  Created on 1/13/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPGiftCardCloseResponse_h
#define VTPGiftCardCloseResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseHost.h"
#import "VTPValutecRewardsResponse.h"
///
/// \class VTPGiftCardUnloadResponse
///
/// \brief The definition of the gift card unload response
///
@interface VTPGiftCardCloseResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCard, VTPFinancialResponseHost, VTPValutecRewardsResponse>

@end

#endif /* VTPGiftCardCloseResponse_h */
