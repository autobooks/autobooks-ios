///
/// \file VTP+EBTCardBalanceInquiry.h
///

#ifndef VTP_EBTCardBalanceInquiry_h
#define VTP_EBTCardBalanceInquiry_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPEBTCardBalanceInquiryRequest.h"
#import "VTPEBTCardBalanceInquiryResponse.h"

///
/// \category VTP(EBTCardBalanceInquiry)
///
/// \brief The extension class for handling sale requests
///
/// This class defines the methods and callbacks for processing EBT card activate transactions.
///
@interface VTP(EBTCardBalanceInquiry)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPEBTCardBalanceInquiryApiCompletionHandler)(VTPEBTCardBalanceInquiryResponse *response);

///
/// \brief Process a sale request
///
/// This method processes a sale request.
///
/// \param request The sale request.
///
/// \param completionHandler A VTPEBTCardBalanceInquiryApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processEBTCardBalanceInquiryRequest:(VTPEBTCardBalanceInquiryRequest *)request completionHandler:(VTPEBTCardBalanceInquiryApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_EBTCardBalanceInquiry_h */
