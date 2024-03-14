//
//  VTP+HostedPaymentsSale.h
//  triPOSMobileSDK
//
//  Created on 31/01/2023.
//  Copyright © 2023 Worldpay from FIS. All rights reserved.
//

#ifndef VTP_HostedPaymentsSale_h
#define VTP_HostedPaymentsSale_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPSaleRequest.h"
#import "VTPHostedPaymentsSaleResponse.h"

///
/// \category VTP(HostedPaymentsSale)
///
/// \brief The extension class for handling hosted payments sale requests
///
/// This class defines the methods and callbacks for processing hosted payments sale transactions.
///
@interface VTP(HostedPaymentsSale)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPHostedPaymentsSaleApiCompletionHandler)(VTPHostedPaymentsSaleResponse *response);

///
/// \brief Process a hosted payments sale request
///
/// This method processes a hosted payments sale request.
///
/// \param request The hosted payments sale request.
///
/// \param completionHandler A VTPHostedPaymentsSaleApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processHostedPaymentsSaleRequest:(VTPSaleRequest *)request completionHandler:(VTPHostedPaymentsSaleApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_HostedPaymentsSale_h */

