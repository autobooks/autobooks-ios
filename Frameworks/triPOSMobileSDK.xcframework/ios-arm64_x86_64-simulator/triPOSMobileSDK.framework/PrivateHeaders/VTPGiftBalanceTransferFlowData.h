//
//  VTPGiftBalanceTransferFlowData.h
//  triPOSMobileSDK
//
//  Created on 2/3/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPGiftBalanceTransferFlowData_h
#define VTPGiftBalanceTransferFlowData_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPFinancialRequestBase.h"
#import "VTPPaymentType.h"
#import "VTPEbtType.h"
#import "VTPTransactionStatus.h"
#import "VTPTransactionType.h"
#import "VXP.h"

@protocol VTPGiftBalanceTransferFlowData

@property (retain, nonatomic) NSString *sourceCardNumber1;

@property (retain, nonatomic) NSString *sourceCardNumber2;

@property (retain, nonatomic) NSString *sourceCardNumber3;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPGiftBalanceTransferFlowData_h */
