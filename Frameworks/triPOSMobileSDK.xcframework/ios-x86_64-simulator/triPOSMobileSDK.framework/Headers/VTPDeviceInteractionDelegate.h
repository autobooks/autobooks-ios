///
/// \file VTPDeviceInteractionDelegate.h
///

#ifndef VTPDeviceInteractionDelegate_h
#define VTPDeviceInteractionDelegate_h

#import "VTPSelectionType.h"
#import "VTPNumericInputType.h"
#import "VPDChoiceInput.h"
#import "VPDYesNoInput.h"
#import "VPDKeyboardNumericInput.h"

///
/// \protocol VTPDeviceInteractionDelegate
///
/// \brief Protocol for UI Display and User Input request notifications for no-PIN pad and no-display devices.
///
/// The VTPDeviceInteractionDelegate protocol defines the methods a receiver may implement for receiving UI display
///  and user input request notifications from devices with no PIN pad and/or no-display.
///
@protocol VTPDeviceInteractionDelegate<NSObject>

///
/// \brief Provides the the delegate the list of choices for user to select from.
///
/// This protocol method is called to provide the delegate a list of choices to select from.
///
/// \param choices An array with the list of available choices.
///
/// \param selectionType The type of list being presented.
///
/// \param completionHandler The completion handler the delegate should call with the index of the selected choice after selection is done.
///
-(void) onSelectionWith:(NSArray *) choices for:(VTPSelectionType) selectionType completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

///
/// \brief Provides the delegate a transaction amount for amount confirmation.
///
/// This protocol method is called to provide the delegate the final transaction amount for confirmation.
///
/// \param amount Transaction amount requiring confirmation.
///
/// \param selectionType The type of list being presented.
///
/// \param completionHandler The completion handler the delegate should call with the amount confirmation result - YES or NO.
///
-(void) onAmountConfirmation:(NSDecimalNumber *) amount completionHandler:(VPDYesNoInputCompletionHandler)completionHandler;

///
/// \brief Requests the delegate for numeric input.
///
/// This protocol method requests from the delegate a numeric input.
///
/// \param numericInputType Numeric input type (e.g. Tip/Gratuity).
///
/// \param completionHandler The completion handler the delegate should call with numeric input amount (as NSString).
///
-(void)onNumericInput:(VTPNumericInputType) numericInputType completionHandler:(VPDKeyboardNumericInputCompletionHandler) completionHandler;

///
/// \brief Requests the delegate to display specific text to the user.
///
/// This protocol method called to inform the delegate of text that should be displayed to the user.  All text that is returned in
/// in this method is text that is typically displayed direclty on the terminal itself
///
/// \param text Text that should be displayed to the user.
///
-(void)onDisplayText:(NSString *) text;

///
/// \brief For EMV provides the the delegate the list of AIDs for user to select from.
///
/// This protocol method is called to provide the delegate a list of AIDs to select from.
///
/// \param applications An array with the list of available applications on the card to select from.
///
/// \param completionHandler The completion handler the delegate should call with the index of the selected AID after selection is done.
///
-(void)onSelectApplication:(NSArray *) applications completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

///
/// \brief Informs the delegate that the card should be removed.
///
/// This protocol method informs the delegate that the card should be removed from the reader.
///
-(void)onRemoveCard;

@optional

//
/// \brief Provides the delegate a text prompt showing an amount and type for confirmation.
///
/// This protocol method is called to provide the delegate the final transaction amount and convenience fee amount for confirmation.
///
/// \param prompt The prompt to display to the user.
///
/// \param completionHandler The completion handler the delegate should call with the amount confirmation result - YES or NO.
///
-(void) onAmountConfirmationWithPrompt:(NSString*)prompt completionHandler:(VPDYesNoInputCompletionHandler)completionHandler;


@end

#endif /* VTPDeviceInteractionDelegate_h */
