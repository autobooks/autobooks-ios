//
//  VPDKeyboardAlphaInput.h
//  triPOSMobileSDK
//
//  Created on 4/10/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//

#ifndef VPDKeyboardAlphaInput_h
#define VPDKeyboardAlphaInput_h

#import "VPDDevice.h"
#import "VPDKeyboardAlphaInputPromptId.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// \param input The keyboard input.
///
/// \sa enableKeyboardInput, enableKeyboardInputWithOptions
///
typedef void (^VPDKeyboardAlphaInputCompletionHandler)(NSString *alphaInput);

///
/// \protocol VPDKeyboardNumericInput
///
/// \brief POI yes/no input protocol
///
/// The VPDKeyboardNumericInput protocol defines methods a POI yes/no input must implement.
///
@protocol VPDKeyboardAlphaInput <VPDDevice>

@required

/// \brief Enable keyboard alpha input with a prompt ID
///
/// This method enables alpha numeric input with a prompt ID.
///
/// \param promptId The ID for the prompt displayed on the device for keyboard alpha input.
///
/// \param completionHandler A VPDKeyboardAlphaInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableKeyboardAlphaInputWithPromptId:(VPDKeyboardAlphaInputPromptId)promptId completionHandler:(VPDKeyboardAlphaInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

@end


#endif /* VPDKeyboardAlphaInput_h */
