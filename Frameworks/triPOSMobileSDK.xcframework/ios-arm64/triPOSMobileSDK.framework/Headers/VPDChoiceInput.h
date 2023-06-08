///
/// \file VPDChoiceInput.h
///

#ifndef VPDChoiceInput_h
#define VPDChoiceInput_h

#import "VPDDevice.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// \param choice The index of the choice selected.
///
/// \sa enableChoiceInput, enableChoiceInputWithChoices
///
typedef void (^VPDChoiceInputCompletionHandler)(NSInteger choice);

///
/// \protocol VPDChoiceInput
///
/// \brief POI choice input protocol
///
/// The VPDChoiceInput protocol defines methods a POI display input must implement.
///
@protocol VPDChoiceInput <VPDDevice>

@required

///
/// \brief Gets the number or choices allowed
///
/// This property gets the number of choices allowed for the connected device.
///
@property (nonatomic, readonly) NSInteger numberOfChoicesAllowed;

///
/// \brief Enable choice input with default options
///
/// This method enables choice input with default options.
///
/// \param choices The array of choices.
///
/// \param completionHandler A VPDChoiceInputCompletionHandler used to return the yes/no input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableChoiceInputWithChoices:(NSArray<NSString *> *)choices completionHandler:(VPDChoiceInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

///
/// \brief Enable yes/no input with options
///
/// This method enables yes/no input with the specified options.
///
/// \param choices The array of choices.
///
/// \param prompt The prompt displayed on the device for yes/no input.
///
/// \param completionHandler A VPDChoiceInputCompletionHandler used to return the card input.
///
/// \param errorHandler A VPDErrorHandler used to return any errors.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)enableChoiceInputWithChoices:(NSArray<NSString *> *)choices prompt:(NSString *)prompt completionHandler:(VPDChoiceInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

@end

#endif /* VPDChoiceInput_h */
