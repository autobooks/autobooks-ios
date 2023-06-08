//
//  VTPEbtVoucherRequest.h
//  triPOSMobileSDK
//
//  Copyright © 2018 Worldpay, LLC. and/or its affiliates. All rights reserved.
//

#ifndef VTPEbtVoucherRequest_h
#define VTPEbtVoucherRequest_h

#import <Foundation/Foundation.h>

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPEbtRequestVoucher.h"
#import "VTPAddressRequest.h"

@interface VTPEbtVoucherRequest : NSObject <VTPFinancialRequestBase, VTPFinancialRequestAmounts, VTPEbtRequestVoucher, VTPAddressRequest>

@end

#endif /* VTPEbtVoucherRequest_h */
