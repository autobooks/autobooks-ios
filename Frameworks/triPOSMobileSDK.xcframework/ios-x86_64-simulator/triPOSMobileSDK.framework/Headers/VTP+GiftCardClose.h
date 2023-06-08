//
//  VTP+GiftCardClose.h
//  triPOSMobileSDK
//
//  Created on 1/13/21.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTP_GiftCardClose_h
#define VTP_GiftCardClose_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPGiftCardCloseRequest.h"
#import "VTPGiftCardCloseResponse.h"

///
/// \category VTP(GiftCardClose)
///
/// \brief The extension class for handling gift card close requests
///
/// This class defines the methods and callbacks for processing gift card close transactions.
///
@interface VTP(GiftCardClose)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPGiftCardCloseApiCompletionHandler)(VTPGiftCardCloseResponse *response);

///
/// \brief Process a gift card close request
///
/// This method processes a gift card close request.
///
/// \param request The gift card close request.
///
/// \param completionHandler A VTPGiftCardCloseApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processGiftCardCloseRequest:(VTPGiftCardCloseRequest *)request completionHandler:(VTPGiftCardCloseApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end


#endif /* VTP_GiftCardClose_h */
