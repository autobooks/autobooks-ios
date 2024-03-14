//
//  VTPGiftCardBalanceTransferRequest.h
//  triPOSMobileSDK
//
//  Created on 2/2/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPGiftCardBalanceTransferRequest_h
#define VTPGiftCardBalanceTransferRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPAddressRequest.h"
#import "VTPGiftBalanceTransferRequest.h"
#import "VTPGiftProgramRequest.h"

@interface VTPGiftCardBalanceTransferRequest : NSObject<VTPFinancialRequestBase, VTPAddressRequest, VTPGiftBalanceTransferRequest, VTPGiftProgramRequest>

@end


#endif /* VTPGiftCardBalanceTransferRequest_h */
