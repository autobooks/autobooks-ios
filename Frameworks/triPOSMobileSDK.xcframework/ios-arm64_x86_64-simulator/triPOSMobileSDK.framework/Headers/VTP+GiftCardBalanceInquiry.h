///
/// \file VTP+GiftCardBalanceInquiry.h
///

#ifndef VTP_GiftCardBalanceInquiry_h
#define VTP_GiftCardBalanceInquiry_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPGiftCardBalanceInquiryRequest.h"
#import "VTPGiftCardBalanceInquiryResponse.h"

///
/// \category VTP(GiftCardBalanceInquiry)
///
/// \brief The extension class for handling sale requests
///
/// This class defines the methods and callbacks for processing gift card activate transactions.
///
@interface VTP(GiftCardBalanceInquiry)

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPGiftCardBalanceInquiryApiCompletionHandler)(VTPGiftCardBalanceInquiryResponse *response);

///
/// \brief Process a sale request
///
/// This method processes a sale request.
///
/// \param request The sale request.
///
/// \param completionHandler A VTPGiftCardBalanceInquiryApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processGiftCardBalanceInquiryRequest:(VTPGiftCardBalanceInquiryRequest *)request completionHandler:(VTPGiftCardBalanceInquiryApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

@end

#endif /* VTP_GiftCardBalanceInquiry_h */
