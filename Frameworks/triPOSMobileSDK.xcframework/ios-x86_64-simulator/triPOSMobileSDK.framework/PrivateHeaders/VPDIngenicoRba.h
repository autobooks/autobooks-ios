///
/// \file VPDIngenicoRba.h
///

#ifndef VPDIngenicoRba_h
#define VPDIngenicoRba_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDBarcodeInput.h"
#import "VPDDevicePrivate.h"
#import "VPDVersionNumber.h"
#import "VTCTlvUtility.h"
#import "VPDCardInput.h"

@interface VPDIngenicoRba : VPDDevicePrivate <VPDDevicePrivate>
{
    BOOL isRbaSdkConnected;
    
}

@property (retain, nonatomic) NSString *idleForm;

@property (retain, nonatomic) NSString * cardDataEncryptionMethod;

@property (nonatomic) BOOL ignoreConnectDisconnectNotifications;

@property (nonatomic) BOOL heartbeatCheckInProgress;

@property (copy, nonatomic) VPDBarcodeInputCompletionHandler barcodeCompletionHandler;

@property (copy, nonatomic) VPDErrorHandler barcodeErrorHandler;

@property (nonatomic, strong) VPDQuickChipCardInputSelectCashbackHandler selectQuickChipCashbackHandler;

///
/// \brief Checks if the device is connected and calls the error handler if not
///
/// This method checks of the device is connected and calls the handler if not.
///
/// \return YES if not connected, NO otherwise.
///
-(BOOL)errorIfNotConnected:(VPDErrorHandler)errorHandler;

///
/// \brief Checks if the device is initialized and calls the error handler if not
///
/// This method checks of the device is initialized and calls the handler if not.
///
/// \return YES if not initialized, NO otherwise.
///
-(BOOL)errorIfNotInitialized:(VPDErrorHandler)errorHandler;

-(BOOL)startRbaTcpIpConnection:(NSString *)ipAddress port:(NSUInteger)port error:(NSError **)error;

typedef void (^VPDIngenicoRbaMessageHandler)(NSInteger messageId);

typedef void (^VPDIngenicoRbaEmvResponseWithTagsCompletionHandler)(NSInteger messageId, VTCTlvCollection tags);

@property (copy, nonatomic) VPDIngenicoRbaMessageHandler messageHandler;
@property (copy, nonatomic) VPDIngenicoRbaMessageHandler messageHandlerFor33_05Message;

@property (strong, nonatomic) VTCTlvCollection tagsWith33_02EmvTransactionPreparationResponseMessage;
@property (strong, nonatomic) VTCTlvCollection tagsWith33_03EmvTransactionAuthorizatinRequestMessage;
@property (strong, nonatomic) VTCTlvCollection tagsWith33_05EmvTransactionAuthorizationConfirmationMessage;
@property (atomic) BOOL emvFlowStepSetPaymentTypeReached;
@property (atomic) BOOL emvFlowStepSetCompletionStatusReached;

typedef enum _VPDIngenicoRbaWhatIsEnabled
{
    VPDIngenicoRbaWhatIsEnabledNothing,
    VPDIngenicoRbaWhatIsEnabledCardInput,
    VPDIngenicoRbaWhatIsEnabledChoiceInput,
    VPDIngenicoRbaWhatIsEnabledYesNoInput,
    VPDIngenicoRbaWhatIsEnabledPinInput,
    VPDIngenicoRbaWhatIsEnabledKeyboardNumericInput,
}   VPDIngenicoRbaWhatIsEnabled;

@property (nonatomic) VPDIngenicoRbaWhatIsEnabled whatIsEnabled;

@property (nonatomic) BOOL quickChipEnabled;

@property (atomic) BOOL authorizationResponseMessageWasSent;
@property (atomic) BOOL authorizationConfirmationMessageWasReceived;
@property (atomic) BOOL authorizationRequestMessageWasReceived;

@property (atomic, strong) NSDecimalNumber*  placeHolderAmount;

-(void)setUserInputTimer:(NSInteger) inputTimeout errorHandler:(VPDErrorHandler)errorHandler;

-(void)setNonUserInputTimer:(VPDErrorHandler)errorHandler;

-(void)startInputTimer;

-(void)stopInputTimer;

-(void)setupHeartbeatTimer:(VPDErrorHandler)errorHandler;
@property (atomic, strong) NSArray<NSString*> * availableAids;
@property (nonatomic, strong) VPDInitializationParameters * initializationParameters; 
@property (atomic) BOOL fileWriteInProgress;
@property (atomic) VTPInitializationStatus initializationStatus;
@property (atomic, strong) NSString * initializationProgressDescription;
@property (nonatomic) double lastFileUploadProgress;
@property (atomic, strong) NSString * bluetoothIdentifier;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDIngenicoRba_h */
