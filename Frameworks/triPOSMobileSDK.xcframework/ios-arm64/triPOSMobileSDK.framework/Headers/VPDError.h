///
/// \file VPDError.h
///

#import <Foundation/Foundation.h>

#ifndef VPDError_h
#define VPDError_h

///
/// The VPD (device) error domain
///
extern NSString * const VPDErrorDomain;

///
/// \brief Block definition for the error handler for device methods.
///
/// \param error The error that occurred.
///
typedef void (^VPDErrorHandler)(NSError *error);

///
/// \enum VPDErrorCode
///
typedef enum _VPDErrorCode
{
    /// Success
    VPDErrorCodeSuccess = 0,
    /// Not connected
    VPDErrorCodeNotConnected,
    /// Not initialized
    VPDErrorCodeNotInitialized,
    /// Parameter is nil
    VPDErrorCodeParameterIsNil,
    /// Parameter is nil for Moby
    VPDErrorCodeParameterIsNilForMoby,
    /// Completion handler is nil
    VPDErrorCodeCompletionHandlerIsNil,
    /// Cancelled by user
    VPDErrorCodeCancelledByUser,
    /// Timeout
    VPDErrorCodeTimeout,

    /// Unknown configuration read error
    VPDErrorCodeConfigurationReadUnknown = 20,
    /// Unknown configuration write error
    VPDErrorCodeConfigurationWriteUnknown,
    /// Unknown configuration write error for Moby
    VPDErrorCodeConfigurationWriteUnknownForMoby,
    /// Unknown file write error
    VPDErrorCodeFileWriteUnknown,
    /// Unknown file write error for Moby
    VPDErrorCodeFileWriteUnknownForMoby,
    /// Unsupported device
    VPDErrorCodeUnsupportedDevice,
    
    /// Unknown card input error
    VPDErrorCodeCardInputUnknown = 30,
    /// Card input type not accepted
    VPDErrorCodeCardInputTypeNotAccepted,
    ///Card read error
    VPDErrorCodeCardReadError,
    ///Swipe card read error. Situation where card return fallback chip when chip card swipe first time
    VPDErrorWaitingforFallbackChip,
    VPDErrorPleaseSeePhoneForDetails,
    
    /// Unknown choice input error
    VPDErrorCodeChoiceInputUnknown = 40,
    /// Input choices is nil
    VPDErrorCodeChoiceInputChoicesIsNil,
    /// Input choices is empty
    VPDErrorCodeChoiceInputChoicesIsEmpty,
    
    /// Unknown keyboard input error
    VPDErrorCodeKeyboardInputUnknown = 50,
    /// Unknown keyboard input prompt ID
    VPDErrorCodeKeyboardInputUnknownPromptId,
    
    /// Unknown PIN input error
    VPDErrorCodePinInputUnknown = 60,
    
    /// EMV, unknown error
    VPDErrorCodeEmvUnknown = 70,
    /// EMV, use magnetic stripe
    VPDErrorCodeEmvUseMagneticStripe,
    /// EMV, card blocked
    VPDErrorCodeEmvCardBlocked,
    /// EMV, chip error
    VPDErrorCodeEmvChipError,
    /// EMV, chip reader error
    VPDErrorCodeEmvChipReaderError,
    /// EMV, card not supported
    VPDErrorCodeEmvCardNotSupported,
    /// EMV, card removed
    VPDErrorCodeEmvCardRemoved,
    /// EMV, card declined with error. Situation where card is declined even though we received ARQC.  Most likely due to CDA failing
    VPDErrorCodeEmvCardDeclinedOfflineWithError,
    /// EMV, chip reader error fallback. Situation where card return fallback when first time card inserted.
    VPDErrorCodeEmvChipReaderErrorFallback,
    /// EMV, MSD contactless card read error. Situation where MSD contactless card not supported.
    VPDErrorCodeEMVUnacceptedContactlessMsdDetected,
    /// Unknown barcode error
    VPDErrorCodeBarcodeUnknown = 80,
    /// Barcode set error
    VPDErrorCodeBarcodeSetError,
    /// Barcode get error
    VPDErrorCodeBarcodeGetError,
    /// Barcode invalid configuration value
    VPDErrorCodeBarcodeInvalidConfigurationValue,
    
    /// Call to cancel/reset device failed
    VPDErrorCodeCancelTransactionOnDeviceFailed,
    
    /// Bluetooth connectivity Error
    VPDErrorCodeBluetoothConnectivity,
    
    /// Firmware update error
    VPDErrorCodeFirmwareUpdateFailed,
    
    /// Firmware update error for Moby
    VPDErrorCodeFirmwareUpdateFailedForMoby,
    
    /// Device token request error
    VPDErrorCodeDeviceTokenRequestError = 100,
    
    /// Device token is expired
    VPDErrorCodeDeviceTokenIsExpired,
    
    /// Printer error
    VPDErrorCodePrinter,
    
    /// Print out of paper error
    VPDErrorCodeOutOfPaper,

    /// Print request error
    VPDErrorCodePrintRequest,

    /// No printer found error
    VPDErrorCodeNoPrinterFound,

    /// Print limit exceeded error
    VPDErrorCodePrintLimitExceeded,

    /// Unknown error
    VPDErrorCodeUnknown = INT_MAX
}   VPDErrorCode;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface VPDError : NSObject

+(NSError *)makeError:(VPDErrorCode)code;

+(NSError *)makeErrorWithDescription:(VPDErrorCode)code description:(NSString *)description;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDError_h */
