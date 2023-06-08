//
//  VTP+GiftCardBalanceTransfer.h
//  triPOSMobileSDK
//
//  Created on 2/3/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTP_GiftCardBalanceTransfer_h
#define VTP_GiftCardBalanceTransfer_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPGiftCardBalanceTransferRequest.h"
#import "VTPGiftCardBalanceTransferResponse.h"

@interface VTP(GiftCardBalanceTransfer)


///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPGiftCardBalanceTransferApiCompletionHandler)(VTPGiftCardBalanceTransferResponse *response);

///
/// \brief Process a gift card balance transfer request
///
/// This method processes a gift card balance transfer request
///
/// \param request The gift card balance transfer request.
///
/// \param completionHandler A VTPGiftCardBalanceTransferApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processGiftCardBalanceTransferRequest:(VTPGiftCardBalanceTransferRequest *)request completionHandler:(VTPGiftCardBalanceTransferApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;


@end


#endif /* VTP_GiftCardBalanceTransfer_h */
