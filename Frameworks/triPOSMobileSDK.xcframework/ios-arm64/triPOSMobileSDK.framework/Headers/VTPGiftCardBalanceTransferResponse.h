//
//  VTPGiftCardBalanceTransferResponse.h
//  triPOSMobileSDK
//
//  Created on 2/2/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPGiftCardBalanceTransferResponse_h
#define VTPGiftCardBalanceTransferResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseHost.h"
#import "VTPValutecRewardsResponse.h"

///
/// \class VTPGiftCardBalanceTransferResponse
///
/// \brief The definition of the gift card balance transfer response
///
@interface VTPGiftCardBalanceTransferResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCard, VTPFinancialResponseHost, VTPValutecRewardsResponse>

@end

#endif /* VTPGiftCardBalanceTransferResponse_h */
