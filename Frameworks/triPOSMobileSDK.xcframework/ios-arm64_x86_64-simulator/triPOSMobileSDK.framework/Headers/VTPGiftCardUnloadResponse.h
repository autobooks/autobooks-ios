//
//  VTPGiftCardUnloadResponse.h
//  triPOSMobileSDK
//
//  Created on 1/2/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPGiftCardUnloadResponse_h
#define VTPGiftCardUnloadResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseHost.h"

///
/// \class VTPGiftCardUnloadResponse
///
/// \brief The definition of the gift card unload response
///
@interface VTPGiftCardUnloadResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCard, VTPFinancialResponseHost>

@end


#endif /* VTPGiftCardUnloadResponse_h */
