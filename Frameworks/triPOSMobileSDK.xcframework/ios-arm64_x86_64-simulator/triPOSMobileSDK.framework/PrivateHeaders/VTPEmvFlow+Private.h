//
//  VTPEmvFlow+Private.h
//  triPOSMobileSDK
//
//  Created on 3/26/19.
//  Copyright © 2019 Vantiv Inc. All rights reserved.
//

#import <triPOSMobileSDK/triPOSMobileSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface VTPEmvFlow ()
{
    @protected
    NSArray<NSNumber *> *_transactionTypesThatRequirePreHostProcessing;
    
    NSArray<NSNumber *> *_transactionTypesThatRequireOnlineProcessing;
    
    NSArray<NSNumber *> *_tagsRequiredForCertification;
    
    NSNumber *_applicationUsageControlTagNumber;
    
    NSNumber *_issuerCountryCodeTagNumber;
    
    NSNumber *_terminalCountryCodeTagNumber;
    
    NSArray<NSNumber *> *_tagsRequiredForReceiptPrinting;
    
    NSArray<NSNumber *> *_tagsRequiredForDeclineReceiptPrinting;
}
@end

NS_ASSUME_NONNULL_END
