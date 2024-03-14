///
///  \file VTP+ManuallyForward.h
///

#ifndef VTP_ManuallyForward_h
#define VTP_ManuallyForward_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPManuallyForwardResponse.h"
#import "VTPManuallyForwardRequest.h"

///
/// \category VTP(ManuallyForward)
///
/// \brief The extension class for handling manually forwarding transactions
///
/// This class defines the methods and callbacks for manually forwarding transactions.
///
@interface VTP(ManuallyForward)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPManuallyForwardApiCompletionHandler)(VTPManuallyForwardResponse *response);

///
/// \brief Manually forward a request
///
/// This method forwards a stored transaction.
///
/// \param request The Manually Forward Transaction request.
///
/// \param completionHandler A VTPManuallyForwardApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)forwardTransaction:(VTPManuallyForwardRequest *)request completionHandler:(VTPManuallyForwardApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_ManuallyForward_h */
