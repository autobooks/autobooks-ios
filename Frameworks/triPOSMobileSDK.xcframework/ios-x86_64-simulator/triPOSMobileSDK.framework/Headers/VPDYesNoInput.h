///
/// \file VPDYesNoInput.h
///

#ifndef VPDYesNoInput_h
#define VPDYesNoInput_h

#import "VPDDevice.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// \param yes YES if the user selected "YES", NO otherwise.
///
/// \sa enableYesNoInput, enableYesNoInputWithOptions
///
typedef void (^VPDYesNoInputCompletionHandler)(BOOL yes);

///
/// \protocol VPDYesNoInput
///
/// \brief POI yes/no input protocol
///
/// The VPDYesNoInput protocol defines methods a POI yes/no input must implement.
///
@protocol VPDYesNoInput <VPDDevice>

@required

///
/// \brief Enable yes/no input with default prompt
///
/// This method enables yes/no input with default options.
///
/// \param completionHandler A VPDYesNoInputCompletionHandler used to return the yes/no input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableYesNoInput:(VPDYesNoInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable yes/no input with prompt
///
/// This method enables yes/no input with the specified prompt.
///
/// \param prompt The prompt displayed on the device for yes/no input.
///
/// \param completionHandler A VPDYesNoInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableYesNoInputWithPrompt:(NSString *)prompt completionHandler:(VPDYesNoInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

@end

#endif /* VPDYesNoInput_h */
