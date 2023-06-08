///
/// \file VPDPinInput.h
///

#ifndef VPDPinInput_h
#define VPDPinInput_h

#import "VPDDevice.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// \param pinBlock The encrypted PIN block.
///
/// \sa enablePinInput, enablePinInputWithOptions
///
typedef void (^VPDPinInputCompletionHandler)(NSString *pinBlock, NSString *keySerialNumber);

///
/// \protocol VPDPinInput
///
/// \brief POI yes/no input protocol
///
/// The VPDPinInput protocol defines methods a POI yes/no input must implement.
///
@protocol VPDPinInput <VPDDevice>

@required

///
/// \brief Enable PIN input with default prompt
///
/// This method enables PIN input with default prompt.
///
/// \param accountNumber The account number for this PIN input.  For encrypted card input, this is the masked account number.
///
/// \param completionHandler A VPDPinInputCompletionHandler used to return the yes/no input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enablePinInputWithAccountNumber:(NSString *)accountNumber completionHandler:(VPDPinInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable PIN input with prompt
///
/// This method enables PIN input with the specified prompt.
///
/// \param accountNumber The account number for this PIN input.  For encrypted card input, this is the masked account number.
///
/// \param prompt The prompt displayed on the device for yes/no input.<br /><br /><strong>NOTE:</strong> Not all devices will use this parameter and instead will use a built-in prompt.<br /><br />
///
/// \param completionHandler A VPDPinInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enablePinInputWithAccountNumber:(NSString *)accountNumber prompt:(NSString *)prompt completionHandler:(VPDPinInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

@end

#endif /* VPDPinInput_h */
