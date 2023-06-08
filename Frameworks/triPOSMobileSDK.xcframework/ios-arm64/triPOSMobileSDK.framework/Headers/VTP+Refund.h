///
/// \file VTP+Refund.h
///

#ifndef VTP_Refund_h
#define VTP_Refund_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPRefundRequest.h"
#import "VTPRefundResponse.h"

///
/// \category VTP(Refund)
///
/// \brief The extension class for handling refund requests
///
/// This class defines the methods and callbacks for processing refund transactions.
///
@interface VTP(Refund)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPRefundApiCompletionHandler)(VTPRefundResponse *response);

///
/// \brief Process a refund request
///
/// This method processes a refund request.
///
/// \param request The refund request.
///
/// \param completionHandler A VTPRefundApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processRefundRequest:(VTPRefundRequest *)request completionHandler:(VTPRefundApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_Refund_h */
