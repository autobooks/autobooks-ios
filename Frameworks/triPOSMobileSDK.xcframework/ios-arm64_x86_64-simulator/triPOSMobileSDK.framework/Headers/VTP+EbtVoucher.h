///
/// \file VTP+EbtVoucher.h
///

#ifndef VTP_EbtVoucher_h
#define VTP_EbtVoucher_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPEbtVoucherRequest.h"
#import "VTPEbtVoucherResponse.h"

#import <Foundation/Foundation.h>

@interface VTP (EbtVoucher) 

///
/// \brief Block definition for completionHandler parameter of the process request method.
///
/// \param response The response to the request.
///
typedef void (^VTPEBTVoucherApiCompletionHandler)(VTPEbtVoucherResponse *response);

///
/// \brief Process a EBT Voucher request
///
/// This method processes an ebt voucher request.
///
/// \param request The EBT Voucher request.
///
/// \param completionHandler A VTPEBTVoucherApiCompletionHandler used to return the response.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)processEbtVoucherRequest:(VTPEbtVoucherRequest *)request completionHandler:(VTPEBTVoucherApiCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;




@end
#endif /* VTP_EbtVoucher_h */
