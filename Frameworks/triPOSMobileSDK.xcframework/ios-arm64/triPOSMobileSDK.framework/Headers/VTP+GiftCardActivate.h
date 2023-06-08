///
/// \file VTP+GiftCardActivate.h
///

#ifndef VTP_GiftCardActivate_h
#define VTP_GiftCardActivate_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPGiftCardActivateRequest.h"
#import "VTPGiftCardActivateResponse.h"

///
/// \category VTP(GiftCardActivate)
///
/// \brief The extension class for handling sale requests
///
/// This class defines the methods and callbacks for processing gift card activate transactions.
///
@interface VTP(GiftCardActivate)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPGiftCardActivateApiCompletionHandler)(VTPGiftCardActivateResponse *response);

///
/// \brief Process a sale request
///
/// This method processes a sale request.
///
/// \param request The sale request.
///
/// \param completionHandler A VTPGiftCardActivateApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processGiftCardActivateRequest:(VTPGiftCardActivateRequest *)request completionHandler:(VTPGiftCardActivateApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_GiftCardActivate_h */
