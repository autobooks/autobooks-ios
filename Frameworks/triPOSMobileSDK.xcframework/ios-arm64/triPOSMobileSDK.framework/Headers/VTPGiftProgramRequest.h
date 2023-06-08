//
//  VTPGiftProgramRequest.h
//  triPOSMobileSDK
//
//  Created on 5/7/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPGiftProgramRequest_h
#define VTPGiftProgramRequest_h

#import "VTPGiftProgramType.h"

///
/// \protocol VTPGiftBalanceTransferRequest
///
/// \brief The protocol for Gift card balance transfer request
///
@protocol VTPGiftProgramRequest

///
/// \brief Gets or sets the gift card program type
///
/// Gets or sets the gift card program type
///
@property (nonatomic) VTPGiftProgramType giftProgramType;



@end

#endif /* VTPGiftProgramRequest_h */
