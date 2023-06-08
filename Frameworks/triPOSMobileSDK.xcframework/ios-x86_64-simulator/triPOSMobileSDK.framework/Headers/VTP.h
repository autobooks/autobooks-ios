///
/// \file  VTP.h
///

#import "VPD.h"
#import "VTPConfiguration.h"
#import "VTPDelegate.h"
#import "VTPError.h"
#import "VTPDeviceInteractionDelegate.h"
#import "VTPBluetoothDevice.h"

///
/// \class VTP
///
/// \brief The main SDK interface class
///
/// This class defines the main interface methods and properties for the SDK.
///
@interface VTP : NSObject

///
/// \brief Block definition for completionHandler parameter of the preread card method.
///
/// \param readSuccesful YES if the card read was succesful.
///
typedef void (^VTPCardReadCompletionHandler)(BOOL readSuccesful);


///
/// \brief Initialize an instance of the triPOS Mobile SDK
///
/// Initialize an instance of the triPOS Mobile SDK with the provided configuration.
///
/// \param configuration The configuration for this instance of the triPOS Mobile SDK.
///
/// \param error Pointer to NSError object. If the initialization fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if successful, NO otherwise.
///
/// <br /><br /><strong>NOTE:</strong> This method has been deprecated.
///
/// \sa initializeWithConfiguration
///
-(BOOL)inititializeWithConfiguration:(VTPConfiguration *)configuration error:(NSError **)error __deprecated;

///
/// \brief Initialize an instance of the triPOS Mobile SDK
///
/// Initialize an instance of the triPOS Mobile SDK with the provided configuration.
///
/// \param configuration The configuration for this instance of the triPOS Mobile SDK.
///
/// \param error Pointer to NSError object. If the initialization fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)initializeWithConfiguration:(VTPConfiguration *)configuration error:(NSError **)error;


///
/// \brief Scans for available Bluetooth devices of the selected type
///
/// Scans for available Bluetooth devices of the selected type.
/// Results will be returned in the onReturnBluetoothScanResults VTPDelegate protocol method.
///
/// <br /><br /><strong>NOTE:</strong> Some device types (for example Ingenico RBA) are Bluetooth classic and others (BBPos) are BLE.
///       For Bluetooth classic devices, onReturnBluetoothScanResults only returns those devices already paired
///       and connected to the iOS device.  For BLE, since it does not require
///       pairing, onReturnBluetoothScanResults returns all available devices of the configured type.
///
/// \param configuration The configuration for this instance of the triPOS Mobile SDK.
///
/// \param error Pointer to NSError object. If unable to start scan, error information is returned in this object.
///
/// \return YES if scan started, NO if unable to start scan.
///
/// \sa VTPDelegate::onReturnBluetoothScanResults
///
-(BOOL)scanForDevicesWithConfiguration:(VTPConfiguration *)configuration error:(NSError **)error;

///
/// \brief Deinitialize the triPOS Mobile SDK
///
/// Deinitialize the triPOS mobile SDK and disconnect any devices.
///
/// \param error Pointer to NSError object. If the deinitialization fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)deinitialize:(NSError **)error;

///
/// \brief Gets a value indicating if the SDK initialized or not
///
/// Gets a value indicating if the SDK initialized or not.
///
/// \sa isConnectedToDevice
///
@property (atomic, readonly) BOOL isInitialized;

///
///
/// \brief Gets a value indicating if the device is initialized and connected or not
///
/// Gets a value indicating if the device is initialized and connected or not.
///
/// \sa isInitialized
///
@property (atomic, readonly) BOOL isConnectedToDevice;

///
/// \brief Gets the singleton instance of the device.
///
/// This property contains the singleton instance of the connected device. If the device is not initialized or connected, this property is nil.
///
@property (retain, nonatomic, readonly) NSObject<VPDDevice> *device;

///
/// \brief Gets the VTP configuration.
///
/// This property may be used to change certain configuration properties after initialization. For example, isCashbackAllowed may be, but changing deviceType is ignored. In addition, no configuration change will be honored while a transaction is in process. 
///
@property (retain, nonatomic) VTPConfiguration *configuration;

///
/// \brief Add a receiver to the list of delegates
///
/// Adds a receiver to the list of delegates. There may be multiple receivers for each protocol selector.
///
/// \param delegate The receiver's delegate.
///
-(void)addDelegate:(id<VTPDelegate>)delegate;

///
/// \brief Remove a receiver from the list of delegates
///
/// Remove a receiver from the list of delegates.
///
/// \param delegate The receiver's delegate. This must be the same delegate reference previously added.
///
-(void)removeDelegate:(id <VTPDelegate>)delegate;

///
/// \brief Stop a currently running flow
///
/// Stop a currently running flow (e.g. sale, refund, authorization...).
///
/// \return YES if a flow is currently running and can be stopped, NO otherwise.
///
-(BOOL)stopCurrentFlow;

///
/// \brief Read a card without transaction information.
///
/// This method allows the user to pre-swipe, pre-insert, or pre-tap their card, and then to enter in transaction information after the card has been read.
///
/// \param completionHandler A VTPCardReadCompletionHandler used to return whether or not the card read was succesful.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)prereadCardWithCompletionHandler:(VTPCardReadCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

///
/// \brief Read a card without transaction information with transaction type info.
///
/// This method allows the user to pre-swipe, pre-insert, or pre-tap their card, and then to enter in transaction information after the card has been read.
///
/// <br /><br /><strong>NOTE:</strong> This method can be used with transaction type Sale to allow pre-read cashback.
///
/// \param transactionType The transaction type for which the card data obtained in the pre-read will be used.  Supports only two
/// transaction types - VTPTransactionTypeUnknown and VTPTransactionTypeSale.  All other transaction types will be treated as
/// VTPTransactionTypeUnknown.
///
/// \param completionHandler A VTPCardReadCompletionHandler used to return whether or not the card read was succesful.
///
/// \param errorHandler A VTPErrorHandler used to return any errors.
///
-(void)prereadCardWithTransactionType:(VTPTransactionType) transactionType completionHandler:(VTPCardReadCompletionHandler)completionHandler errorHandler:(VTPErrorHandler)errorHandler;

///
/// \brief Cancel a preread/preswipe.
///
/// This method cancels a preswipe.
-(void) cancelPreread;

///
/// \brief Sets a receiver for device interacton
///
/// Sets a receiver for device interaction to handle cardholder decisions.
///
/// \param delegate The receiver's delegate.
///
-(void)setDeviceInteractionDelegate:(id <VTPDeviceInteractionDelegate>)delegate;
-(void)validateToRestrictStoringOfHealthcareTransactions:(BOOL)isStoringAllowed andIsHealthcareSupported:(BOOL)isHealthcareSupported;

///
/// \brief Enable or disable enhanced device debug logs
///
/// Enable or disable enhanced device debug logs. When enabled device log level set to debug and set to info when false
///
/// <br /><br /><strong>NOTE:</strong>  Enabling enhanced device logging WILL quickly increase the size of the logs. Enhanced device logging should only be used when necessary and for short periods of time when diagnosing issues.
///
///\param enable set devce log level to debug
///
-(void)enableEnhancedDeviceLogs:(BOOL)enable;

@end
