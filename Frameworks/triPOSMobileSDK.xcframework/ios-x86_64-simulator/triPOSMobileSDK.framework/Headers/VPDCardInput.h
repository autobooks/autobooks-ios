///
/// \file VPDCardInput.h
///

#ifndef VPDCardInput_h
#define VPDCardInput_h

#import "VPDDevice.h"
#import "VPDCardInputCapability.h"
#import "VTPCardData.h"
#import "VTPContactlessMagneticStripeCardData.h"
#import "VTPEncryptedContactlessMagneticStripeCardData.h"
#import "VTPEncryptedKeyedCardData.h"
#import "VTPEncryptedSwipedCardData.h"
#import "VTPKeyedCardData.h"
#import "VTPSwipedCardData.h"
#import "VTPIccCardData.h"
#import "VTPEncryptedContactlessIccCardData.h"
#import "VTPEncryptedIccCardData.h"
#import "VTPTransactionType.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// Block definition for completionHandler parameter of the enable methods.
///
/// \param response The card data retrieved from the device.
///
/// \sa enableCardInput, enableCardInputWithPrompt
///
typedef void (^VPDCardInputCompletionHandler)(VTPCardData *cardData);

///
/// \brief Block definition for promptUserForCardHandler parameter of the enable methods
///
/// Block definition for promptUserForCardHandler parameter of the enable methods.
///
/// \param NA.
///
/// \sa enableCardInput, enableCardInputWithPrompt
///
typedef void (^VPDCardInputPromptUserForCardHandler)(void);

///
/// \brief Block definition for selectApplicationHandler parameter of the enable methods.
///
/// This is needed when cashback is enabled
///
/// \param applications List of applications retrieved from the card.
///
///
/// \return Index of selected application.
///
/// \sa enableCardInput, enableCardInputWithPrompt
///
typedef void (^VPDCardInputSelectApplicationHandler)(NSArray* applications);

///
/// \brief Block definition for selectQuickChipCashbackHandler parameter of the enableCardInput method.
///
/// This is called when the terminal, during a QuickChip transaction, is requesting
/// whether to add a cashback amount.
///
/// \param tags Tags that are required to determine if cashback should be allowed.
///
/// \return void.
///
/// \sa enableCardInput, enableCardInputWithPrompt
///
typedef void (^VPDQuickChipCardInputSelectCashbackHandler)(VTCTlvCollection tags);

///
/// \brief Block definition for externalAidSelectionHandler parameter of the enableCardInput method.
///
/// This is called to allow the calling function to filter the AID list returned.
///
/// \param applicationIdentifiers Array of AIDs that are mutually supported by the card and the device.
///
/// \return void.
///
/// \sa enableCardInput
///
typedef void (^VPDExternalAidSelectionHandler)(NSArray<NSString*>* applicationIdentifiers);

///
/// \protocol VPDCardInput
///
/// \brief POI card reader protocol
///
/// The VPDCardInput protocol defines methods a POI card reader must implement.
///
@protocol VPDCardInput <VPDDevice>

@required

///
/// \brief Gets the input capabilities of this POI device
///
/// This property gets the input capabilities of this POI device.
///
@property (readonly, nonatomic) VPDCardInputCapability cardInputCapability;

///
/// \brief Enable card input with default options
///
/// This method enables card input with default options which includes all card input types and the default prompt for the device.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param promptUserForCardHandler A VPDCardInputPromptUserForCardHandler for devices with no screens to prompt user to enter card
///
/// \param selectApplicationHandler A VPDCardInputSelectApplicationHandler used to allow user to select from list of EMV applications on card.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInput:(VPDCardInputCompletionHandler)completionHandler promptUserForCardHandler:(VPDCardInputPromptUserForCardHandler)promptUserForCardHandler applicationSelectionHandler:(VPDCardInputSelectApplicationHandler) selectApplicationHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable card input with options including handlers for use with with no-PIN pad devices.
///
/// This method enables card input with the specified options.
///
/// \param prompt The prompt displayed on the device for card input.<br /><br /><strong>NOTE:</strong> Not all readers support displaying a prompt.<br /><br />
///
/// \param allowKeyed Keyed input is allowed.<br /><br /><strong>NOTE:</strong> Not all POI devices support keyed card input.<br /><br />
///
/// \param promptForKeyedSecurityCode Indicates if there is a security code prompt during keyed card input.
///
/// \param allowIcc ICC input is allowed.
///
/// \param allowContactless Contactless input is allowed.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param promptUserForCardHandler A VPDCardInputPromptUserForCardHandler for devices with no screens to prompt user to enter card
///
/// \param selectApplicationHandler A VPDCardInputSelectApplicationHandler used to allow user to select from list of EMV applications on card.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInputWithPrompt:(NSString *)prompt allowKeyed:(BOOL)allowKeyed promptForKeyedSecurityCode:(BOOL)promptForKeyedSecurityCode allowIcc:(BOOL)allowIcc allowContactless:(BOOL)allowContactless quickChipEnabled:(BOOL)quickChipEnabled completionHandler:(VPDCardInputCompletionHandler)completionHandler promptUserForCardHandler:(VPDCardInputPromptUserForCardHandler)promptUserForCardHandler applicationSelectionHandler:(VPDCardInputSelectApplicationHandler) selectApplicationHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable card input with options including Quickchip Enabled and Placeholder amount
///
/// This method enables card input with the specified options typically for chip card input.
///
/// \param prompt The prompt displayed on the device for card input.<br /><br /><strong>NOTE:</strong> Not all readers support displaying a prompt.<br /><br />
///
/// \param allowKeyed Keyed input is allowed.<br /><br /><strong>NOTE:</strong> Not all POI devices support keyed card input.<br /><br />
///
/// \param promptForKeyedSecurityCode Indicates if there is a security code prompt during keyed card input.
///
/// \param allowIcc ICC input is allowed.
///
/// \param allowContactless Contactless input is allowed.
///
/// \param quickChipEnabled Quickchip is enabled.
///
/// \param transactionType The transaction type for this card input request.
///
/// \param inputTimeout The amount of time in seconds to wait for a card read before timing out.
///
/// \param purchaseAmount The purchase amount for this card input request.
///
/// \param otherAmount The other amount for this card input request.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param promptUserForCardHandler A VPDCardInputPromptUserForCardHandler for devices with no screens to prompt user to enter card
///
/// \param selectApplicationHandler A VPDCardInputSelectApplicationHandler used to allow user to select from list of EMV applications on card.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInputWithPrompt:(NSString *)prompt allowKeyed:(BOOL)allowKeyed promptForKeyedSecurityCode:(BOOL)promptForKeyedSecurityCode allowIcc:(BOOL)allowIcc allowContactless:(BOOL)allowContactless quickChipEnabled:(BOOL)quickChipEnabled inputTimeout:(NSInteger) inputTimeout transactionType:(VTPTransactionType)transactionType purchaseAmount:(NSDecimalNumber *)purchaseAmount otherAmount:(NSDecimalNumber *)otherAmount placeHolderAmount:(NSDecimalNumber *)placeHolderAmount completionHandler:(VPDCardInputCompletionHandler)completionHandler promptUserForCardHandler:(VPDCardInputPromptUserForCardHandler)promptUserForCardHandler applicationSelectionHandler:(VPDCardInputSelectApplicationHandler) selectApplicationHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable card input with QuickChip cashback support
///
/// This method enables card input with the specified options typically for chip card input.
///
/// \param prompt The prompt displayed on the device for card input.<br /><br /><strong>NOTE:</strong> Not all readers support displaying a prompt.<br /><br />
///
/// \param allowKeyed Keyed input is allowed.<br /><br /><strong>NOTE:</strong> Not all POI devices support keyed card input.<br /><br />
///
/// \param promptForKeyedSecurityCode Indicates if there is a security code prompt during keyed card input.
///
/// \param allowIcc ICC input is allowed.
///
/// \param allowContactless Contactless input is allowed.
///
/// \param quickChipEnabled Quickchip is enabled.
///
/// \param transactionType The transaction type for this card input request.
///
/// \param inputTimeout The amount of time in seconds to wait for a card read before timing out.
///
/// \param purchaseAmount The purchase amount for this card input request.
///
/// \param otherAmount The other amount for this card input request.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param promptUserForCardHandler A VPDCardInputPromptUserForCardHandler for devices with no screens to prompt user to enter card
///
/// \param selectApplicationHandler A VPDCardInputSelectApplicationHandler used to allow user to select from list of EMV applications on card.
///
/// \param selectQuickChipCashbackHandler A VPDQuickChipCardInputSelectCashbackHandler used determine if cashback is desired during a QC transaction.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInputWithPrompt:(NSString *)prompt allowKeyed:(BOOL)allowKeyed promptForKeyedSecurityCode:(BOOL)promptForKeyedSecurityCode allowIcc:(BOOL)allowIcc allowContactless:(BOOL)allowContactless quickChipEnabled:(BOOL)quickChipEnabled inputTimeout:(NSInteger) inputTimeout transactionType:(VTPTransactionType)transactionType purchaseAmount:(NSDecimalNumber *)purchaseAmount otherAmount:(NSDecimalNumber *)otherAmount placeHolderAmount:(NSDecimalNumber *)placeHolderAmount completionHandler:(VPDCardInputCompletionHandler)completionHandler promptUserForCardHandler:(VPDCardInputPromptUserForCardHandler)promptUserForCardHandler applicationSelectionHandler:(VPDCardInputSelectApplicationHandler) selectApplicationHandler selectQuickChipCashbackHandler:(VPDQuickChipCardInputSelectCashbackHandler) selectQuickChipCashbackHandler errorHandler:(VPDErrorHandler)errorHandler;


///
/// \brief Enable card input with external AID selection handler.
///
/// This method enables card input with the specified options typically for chip card input.
///
/// \param prompt The prompt displayed on the device for card input.<br /><br /><strong>NOTE:</strong> Not all readers support displaying a prompt.<br /><br />
///
/// \param allowKeyed Keyed input is allowed.<br /><br /><strong>NOTE:</strong> Not all POI devices support keyed card input.<br /><br />
///
/// \param promptForKeyedSecurityCode Indicates if there is a security code prompt during keyed card input.
///
/// \param allowIcc ICC input is allowed.
///
/// \param allowContactless Contactless input is allowed.
///
/// \param quickChipEnabled Quickchip is enabled.
///
/// \param transactionType The transaction type for this card input request.
///
/// \param inputTimeout The amount of time in seconds to wait for a card read before timing out.
///
/// \param purchaseAmount The purchase amount for this card input request.
///
/// \param otherAmount The other amount for this card input request.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param promptUserForCardHandler A VPDCardInputPromptUserForCardHandler for devices with no screens to prompt user to enter card
///
/// \param selectApplicationHandler A VPDCardInputSelectApplicationHandler used to allow user to select from list of EMV applications on card.
///
/// \param selectQuickChipCashbackHandler A VPDQuickChipCardInputSelectCashbackHandler used determine if cashback is desired during a QC transaction.
///
/// \param externalAidSelectionHandler A VPDExternalAidSelectionHandler to allow the user to filter the AID list on the card before presenting to user.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInputWithPrompt:(NSString *)prompt allowKeyed:(BOOL)allowKeyed promptForKeyedSecurityCode:(BOOL)promptForKeyedSecurityCode allowIcc:(BOOL)allowIcc allowContactless:(BOOL)allowContactless quickChipEnabled:(BOOL)quickChipEnabled inputTimeout:(NSInteger) inputTimeout transactionType:(VTPTransactionType)transactionType purchaseAmount:(NSDecimalNumber *)purchaseAmount otherAmount:(NSDecimalNumber *)otherAmount placeHolderAmount:(NSDecimalNumber *)placeHolderAmount completionHandler:(VPDCardInputCompletionHandler)completionHandler promptUserForCardHandler:(VPDCardInputPromptUserForCardHandler)promptUserForCardHandler applicationSelectionHandler:(VPDCardInputSelectApplicationHandler) selectApplicationHandler selectQuickChipCashbackHandler:(VPDQuickChipCardInputSelectCashbackHandler) selectQuickChipCashbackHandler externalAidSelectionHandler:(VPDExternalAidSelectionHandler) externalAidSelectionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Prompt to remove chip card
///
/// This method prompts to remove the chip card.
///
/// \param prompt The prompt to be displayed.
///
/// \param error A pointer to an NSError in which any errors are returned. This parameter may be nil.
///
/// \return YES if card is removed, NO otherwise.
///
-(BOOL)promptToRemoveCard:(NSString *)prompt error:(NSError **)error;

///
/// \brief Enable card input with keyed entry only
///
/// This method enables card input with with keyed entry only.  Classes should only implement this method
/// if the device supports keyed entry.  
///
/// \param prompt The prompt displayed on the device for card input.<br /><br /><strong>NOTE:</strong> Not all readers support displaying a prompt.<br /><br />
///
///
/// \param purchaseAmount The purchase amount for this card input request.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardKeyedOnlyInputWithPrompt:(NSString *) prompt promptForKeyedSecurityCode:(BOOL)promptForKeyedSecurityCode purchaseAmount:(NSDecimalNumber *)purchaseAmount completionHandler:(VPDCardInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;


///
/// \brief Enable card input with default options
///
/// This method enables card input with default options which includes all card input types and the default prompt for the device.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInput:(VPDCardInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable card input with options (with no purchase  or transaction amount)
///
/// This method enables card input with the specified options.
///
/// \param prompt The prompt displayed on the device for card input.<br /><br /><strong>NOTE:</strong> Not all readers support displaying a prompt.<br /><br />
///
/// \param allowKeyed Keyed input is allowed.<br /><br /><strong>NOTE:</strong> Not all POI devices support keyed card input.<br /><br />
///
/// \param promptForKeyedSecurityCode Indicates if there is a security code prompt during keyed card input.
///
/// \param allowIcc ICC input is allowed.
///
/// \param allowContactless Contactless input is allowed.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInputWithPrompt:(NSString *)prompt allowKeyed:(BOOL)allowKeyed promptForKeyedSecurityCode:(BOOL)promptForKeyedSecurityCode allowIcc:(BOOL)allowIcc allowContactless:(BOOL)allowContactless completionHandler:(VPDCardInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable card input with options
///
/// This method enables card input with the specified options typically for chip card input.
///
/// \param prompt The prompt displayed on the device for card input.<br /><br /><strong>NOTE:</strong> Not all readers support displaying a prompt.<br /><br />
///
/// \param allowKeyed Keyed input is allowed.<br /><br /><strong>NOTE:</strong> Not all POI devices support keyed card input.<br /><br />
///
/// \param promptForKeyedSecurityCode Indicates if there is a security code prompt during keyed card input.
///
/// \param allowIcc ICC input is allowed.
///
/// \param allowContactless Contactless input is allowed.
///
/// \param transactionType The transaction type for this card input request.
///
/// \param purchaseAmount The purchase amount for this card input request.
///
/// \param otherAmount The other amount for this card input request.
///
/// \param completionHandler A VPDCardInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableCardInputWithPrompt:(NSString *)prompt allowKeyed:(BOOL)allowKeyed promptForKeyedSecurityCode:(BOOL)promptForKeyedSecurityCode allowIcc:(BOOL)allowIcc allowContactless:(BOOL)allowContactless transactionType:(VTPTransactionType)transactionType purchaseAmount:(NSDecimalNumber *)purchaseAmount otherAmount:(NSDecimalNumber *)otherAmount completionHandler:(VPDCardInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

@end

#endif /* VPDCardInput_h */
