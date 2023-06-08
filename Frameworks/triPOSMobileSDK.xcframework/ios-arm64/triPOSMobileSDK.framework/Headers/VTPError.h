///
/// \file VTPError.h
///

#ifndef VTPError_h
#define VTPError_h

///
/// \brief The VTP (triPOS Mobile SDK) error domain.
///
extern NSString * const VTPErrorDomain;

///
/// \brief Block definition for the error handler for device methods.
///
/// \param error The error that occurred.
///
typedef void (^VTPErrorHandler)(NSError *error);

typedef enum _VTPErrorCode
{
    /// Success
    VTPErrorCodeSuccess,
    
    /// Parameter is nil
    VTPErrorCodeParameterIsNil,
    /// Parameter is invalid
    VTPErrorCodeParameterIsInvalid,
    /// Configuration is invalid
    VTPErrorCodeConfigurationIsInvalid,
    
    /// Device setup failed
    VTPErrorCodeDeviceSetupFailed,
    /// Device is not connected
    VTPErrorCodeDeviceNotConnected,
    /// Device is not initialized
    VTPErrorCodeDeviceNotInitialized,
    /// Device does not support card input
    VTPErrorCodeDeviceDoesNotSupportCardInput,
    /// Device does not support PIN input
    VTPErrorCodeDeviceDoesNotSupportPinInput,
    /// Device does not support EMV
    VTPErrorCodeDeviceDoesNotSupportEmv,
    /// Device does not support keyed input
    VTPErrorCodeDeviceDoesNotSupportKeyedInput,
    
    /// Unknown flow stepper error
    VTPErrorCodeFlowStepperUnknowError,
    /// Flow stepper terminated early
    VTPErrorCodeFlowStepperTerminatedEarly,
    
    /// Card input unknown error
    VTPErrorCodeCardInputUnknown,
    /// Card input type not accepted
    VTPErrorCodeCardInputTypeNotAccepted,
    
    /// Invalid payment type
    VTPErrorCodeInvalidPaymentType,
    
    /// User did not confirm amount
    VTPErrorCodeUserDidNotConfirmAmount,
    
    /// Swiped card is chip capable
    VTPErrorCodeSwipedCardIsChipCapable,
    
    /// Transaction was approved offline by the card, but the SDK could not complete the force. Typically associated with a GENAC1 approval.
    VTPErrorTransactionApprovedOfflineButCouldNotBeCompleted,
    
    /// Database was nil or not open
    VTPErrorCodeDatabaseNotOpen,
    
    /// Query for a stored transaction was not found
    VTPErrorCodeTransactionNotFound,
    
    /// Something went wrong and the database returned an error
    VTPErrorCodeDatabaseError,
    
    /// Contactless MSD card input is not accepted
    VTPErrorCodeUnacceptedContactlessMsdDetected,
    
    /// Configuration settings not compatible with one another.
    VTPErrorCodeIncompatibleConfigurationSettings,
    
    /// Express is not available
    VTPErrorCodeExpressIsNotAvailable,
    
    /// Transaction is already in progress
    VTPErrorCodeTransactionInProgress,
    
    /// SDK is already initialized
    VTPErrorCodeSdkAlreadyInitialized,
    
    /// Pre-read not valid for this transaction type
    VTPErrorCodePrereadNotValidForSelectedTransactionType,
    
    /// Debit only card was read but debit is not enabled
    VTPErrorCodeDebitOnlyCardAndDebitNotEnabled,
    
    /// Invalid food stamp amount. Food stamp amount cannot be greater than the transaction amount
    VTPErrorCodeInvalidFoodStampAmount,

    /// None of the healthcare blocks value can be negative.
    VTPErrorCodeHealthcareFieldIsNegativeValue,
    
    /// Only 4 healthcare fields can have non zero value at the same time.
    VTPErrorCodeOnlyFourHealthcareFieldsAllowed,
    
    /// Healthcare total cannot be less than the sum of the healthcare fields
    VTPErrorCodeInvalidTotalHealthcareAmount,
    
    ///  Error retrieving device token from host
    VTPErrorCodeGettingHostDeviceToken,
    
    /// Unknown error
    VTPErrorCodeUnknown = INT_MAX
}   VTPErrorCode;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface VTPError : NSObject

+(NSError *)makeError:(VTPErrorCode)code;

+(NSError *)makeError:(VTPErrorCode)code identifier:(NSString *) identifier;

+(NSError *)makeErrorWithDescription:(VTPErrorCode)code description:(NSString *)description;

+(NSError *)makeErrorWithDescription:(VTPErrorCode)code description:(NSString *)description identifier:(NSString *)identifier;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPError_h */
