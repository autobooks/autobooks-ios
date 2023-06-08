///
/// \file VPDKeyboardNumericInput.h
///

#ifndef VPDKeyboardNumericInput_h
#define VPDKeyboardNumericInput_h

#import "VPDDevice.h"
#import "VPDKeyboardNumericInputPromptId.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// \param input The keyboard input.
///
/// \sa enableKeyboardInput, enableKeyboardInputWithOptions
///
typedef void (^VPDKeyboardNumericInputCompletionHandler)(NSString *numericInput);

///
/// \protocol VPDKeyboardNumericInput
///
/// \brief POI yes/no input protocol
///
/// The VPDKeyboardNumericInput protocol defines methods a POI yes/no input must implement.
///
@protocol VPDKeyboardNumericInput <VPDDevice>

@required

/// \brief Enable keyboard numeric input with a prompt ID
///
/// This method enables keyboard numeric input with a prompt ID.
///
/// \param promptId The ID for the prompt displayed on the device for keyboard numeric input.
///
/// \param completionHandler A VPDKeyboardNumericInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableKeyboardNumericInputWithPromptId:(VPDKeyboardNumericInputPromptId)promptId completionHandler:(VPDKeyboardNumericInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

@end

#endif /* VPDKeyboardNumericInput_h */
