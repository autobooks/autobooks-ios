//
//  VTP+GiftCardUnload.h
//  triPOSMobileSDK
//
//  Created on 1/2/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTP_GiftCardUnload_h
#define VTP_GiftCardUnload_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPGiftCardUnloadRequest.h"
#import "VTPGiftCardUnloadResponse.h"

///
/// \category VTP(GiftCardUnload)
///
/// \brief The extension class for handling gift card unload requests
///
/// This class defines the methods and callbacks for processing gift card unload transactions.
///
@interface VTP(GiftCardUnload)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPGiftCardUnloadApiCompletionHandler)(VTPGiftCardUnloadResponse *response);

///
/// \brief Process a gift card unload request
///
/// This method processes a gift card unload request.
///
/// \param request The gift card unload request.
///
/// \param completionHandler A VTPGiftCardUnloadApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processGiftCardUnloadRequest:(VTPGiftCardUnloadRequest *)request completionHandler:(VTPGiftCardUnloadApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end


#endif /* VTP_GiftCardUnload_h */
