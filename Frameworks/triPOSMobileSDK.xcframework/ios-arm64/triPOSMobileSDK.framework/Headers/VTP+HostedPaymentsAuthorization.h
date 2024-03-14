///
/// \file VTP+HostedPaymentsAuthorization.h
///

#ifndef VTP_HostedPaymentsAuthorization_h
#define VTP_HostedPaymentsAuthorization_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPAuthorizationRequest.h"
#import "VTPHostedPaymentsAuthorizationResponse.h"

///
/// \category VTP(HostedPaymentsAuthorization)
///
/// \brief The extension class for handling hosted payments authorization requests
///
/// This class defines the methods and callbacks for processing hosted payments authorization transactions.
///
@interface VTP(HostedPaymentsAuthorization)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPHostedPaymentsAuthorizationApiCompletionHandler)(VTPHostedPaymentsAuthorizationResponse *response);

///
/// \brief Process a hosted payments Authorization request
///
/// This method processes a hosted payments Authorization request.
///
/// \param request The hosted payments Authorization request.
///
/// \param completionHandler A VTPHostedPaymentsAuthorizationApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processHostedPaymentsAuthorizationRequest:(VTPAuthorizationRequest *)request completionHandler:(VTPHostedPaymentsAuthorizationApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_HostedPaymentsAuthorization_h */

