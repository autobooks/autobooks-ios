///
/// \file VTP+GiftCardReload.h
///

#ifndef VTP_GiftCardReload_h
#define VTP_GiftCardReload_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPGiftCardReloadRequest.h"
#import "VTPGiftCardReloadResponse.h"

///
/// \category VTP(GiftCardReload)
///
/// \brief The extension class for handling sale requests
///
/// This class defines the methods and callbacks for processing gift card activate transactions.
///
@interface VTP(GiftCardReload)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPGiftCardReloadApiCompletionHandler)(VTPGiftCardReloadResponse *response);

///
/// \brief Process a sale request
///
/// This method processes a sale request.
///
/// \param request The sale request.
///
/// \param completionHandler A VTPGiftCardReloadApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processGiftCardReloadRequest:(VTPGiftCardReloadRequest *)request completionHandler:(VTPGiftCardReloadApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_GiftCardReload_h */
