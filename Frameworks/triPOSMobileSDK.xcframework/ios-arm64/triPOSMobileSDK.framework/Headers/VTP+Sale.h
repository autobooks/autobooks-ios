///
/// \file VTP+Sale.h
///

#ifndef VTP_Sale_h
#define VTP_Sale_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPSaleRequest.h"
#import "VTPSaleResponse.h"

///
/// \category VTP(Sale)
///
/// \brief The extension class for handling sale requests
///
/// This class defines the methods and callbacks for processing sale transactions.
///
@interface VTP(Sale)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPSaleApiCompletionHandler)(VTPSaleResponse *response);

///
/// \brief Process a sale request
///
/// This method processes a sale request.
///
/// \param request The sale request.
///
/// \param completionHandler A VTPSaleApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processSaleRequest:(VTPSaleRequest *)request completionHandler:(VTPSaleApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_Sale_h */
