///
/// \file VTP+Authorization.h
///

#ifndef VTP_Authorization_h
#define VTP_Authorization_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPAuthorizationRequest.h"
#import "VTPAuthorizationResponse.h"

///
/// \category VTP(Authorization)
///
/// \brief The extension class for handling authorization requests
///
/// This class defines the methods and callbacks for processing authorization transactions.
///
@interface VTP(Authorization)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPAuthorizationApiCompletionHandler)(VTPAuthorizationResponse *response);

///
/// \brief Process a Authorization request
///
/// This method processes a Authorization request.
///
/// \param request The Authorization request.
///
/// \param completionHandler A VTPAuthorizationApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processAuthorizationRequest:(VTPAuthorizationRequest *)request completionHandler:(VTPAuthorizationApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_Authorization_h */
