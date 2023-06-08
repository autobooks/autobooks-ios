///
/// VPDDevice.h
///

#ifndef VPDDevice_h
#define VPDDevice_h

#import "VPDError.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

//
// forward delcarations to avoid circular include files
//
@protocol VPDDelegate;
@protocol VPDCardInput;
@protocol VPDBeep;
@protocol VPDChoiceInput;
@protocol VPDDisplay;
@protocol VPDEmv;
@protocol VPDKeyboardNumericInput;
@protocol VPDPinInput;
@protocol VPDYesNoInput;
@protocol VPDBarcodeInput;

#endif

///
/// \protocol VPDDevice
///
/// \brief Definition of the base device functionality
///
/// The VPD protocol defines the basic methods a point-of-interaction (POI) device must implement.
///
@protocol VPDDevice

@required

///
/// \brief Gets the description of device connected
///
/// Gets the text description of the connected device. This property is not set if a device is not connected.
///
@property (retain, nonatomic, readonly) NSString *deviceDescription;

///
/// \brief Gets the model of device connected
///
/// Gets the model of the connected device. This property is not set if a device is not connected.
///
@property (retain, nonatomic, readonly) NSString *deviceModel;

/// \brief Gets the device serial number
///
/// Gets the serial number of the connected device. This property may be nil if the connected device does not supply its serial number. This property is not set if a device is not connected.
///
@property (retain, atomic, readonly) NSString *deviceSerialNumber;

@optional
/// \brief Gets the device firmware version
///
/// Gets the firmware version of the connected device.  This is an optional property
///
@property (retain, atomic, readonly) NSString *deviceFirmwareVersion;

/// \brief Gets the device configuration version
///
/// Gets the configuration version of the connected device.  This is an optional property
///
@property (retain, atomic, readonly) NSString *deviceConfigurationVersion;

/// \brief Gets the device Battery Percentage
///
/// Gets the battery percentage of the connected device when it was first connected for the current session.  This is an optional property
///
@property (retain, atomic, readonly) NSString *deviceBatteryPercentage;

/// \brief Gets the device Battery Level (voltage)
///
/// Gets the battery level (voltage) of the connected device when it was first connected for the current session.  This is an optional property
///
@property (retain, atomic, readonly) NSString *deviceBatteryLevel;

@required
///
/// \brief Gets the EMV kernel version/type of device connected
///
/// Gets the EMV kernel version/type of the connected device. This property is not set if a device is not connected.
///
@property (retain, nonatomic, readonly) NSString *emvKernelVersion;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \brief Adds a receiver to the list of delegates
///
/// This method adds a receiver to the list of delegates. There may be multiple receivers for each protocol selector.
///
/// \param delegate The receiver's delegate.
///
-(void)addDelegate:(id<VPDDelegate>)delegate;

///
/// \brief Removes a receiver from the list of delegates
///
/// This method removes a receiver from the list of delegates.
///
/// \param delegate The receiver's delegate. This must be the same reference previously added.
///
-(void)removeDelegate:(id <VPDDelegate>)delegate;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

///
/// \brief Gets if the device connected
///
/// Although the delegate may implement the deviceDidConnect and deviceDidDisconnect methods to receive connection and disconnection events, this property provides the connection state of the device.
///
/// \return YES if the device is connected, NO otherwise.
///
@property (atomic, readonly) BOOL isConnected;

///
/// \brief Gets if the device initialized
///
/// This property provides the initialization state of the device.
///
/// \return YES if the device is initialized, NO otherwise.
///
@property (atomic, readonly) BOOL isInitialized;

///
/// \brief Reset the device and go to idle.
///
/// This method cancels any current activity occuring on the device and puts the device back to idle.
///
/// \param error Pointer to NSError object. If the enable fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if the device is initialized, NO otherwise.
///
-(BOOL)reset:(NSError **)error;

///
/// \brief Definition for a device capable of beeping
///
/// Definition for a device capable of beeping.
///
typedef NSObject<VPDBeep> * VPDBeepDevice;

///
/// \brief Get the current device as a beep device
///
/// This method attempts to get the current device as a beep device.
///
/// \return A VPDBeepDevice object if the device supports choice input, otherwise nil.
///
-(VPDBeepDevice)getAsBeepDevice;

///
/// \brief Definition for a device capable of doing card input
///
/// Definition for a device capable of doing card input.
///
typedef NSObject<VPDCardInput> * VPDCardInputDevice;

///
/// \brief Get the current device as a card input device
///
/// This method attempts to get the current device as a card input device.
///
/// \return A VPDCardInputDevice object if the device supports card input, otherwise nil.
///
-(VPDCardInputDevice)getAsCardInputDevice;

///
/// \brief Definition for a device capable of doing choice input
///
/// Definition for a device capable of doing choice input.
///
typedef NSObject<VPDChoiceInput> * VPDChoiceInputDevice;

///
/// \brief Get the current device as a choice input device
///
/// This method attempts to get the current device as a choice input device.
///
/// \return A VPDChoiceInputDevice object if the device supports choice input, otherwise nil.
///
-(VPDChoiceInputDevice)getAsChoiceInputDevice;

///
/// \brief Definition for a device capable of displaying text
///
/// Definition for a device capable of displaying text.
///
typedef NSObject<VPDDisplay> * VPDDisplayDevice;

///
/// \brief Get the current device as a display device
///
/// This method attempts to get the current device as a display device.
///
/// \return A VPDDisplayDevice object if the device supports display, otherwise nil.
///
-(VPDDisplayDevice)getAsDisplayDevice;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \brief Definition for a device capable of doing EMV
///
/// Definition for a device capable of doing EMV.
///
typedef NSObject<VPDEmv> * VPDEmvDevice;

///
/// \brief Get the current device as an EMV device
///
/// This method attempts to get the current device as an EMV device.<br /><br /><strong style="color:red;">WARNING: If the device is capable of doing EMV, a VPDEmvDevice only provdes basic functionality and in no way is considered to EMV certified by any card brand by itself. If this functionality is used outside of the certified EMV functionality provided by the triPOS® Mobile SDK (e.g. sale, authorization, and refund), the application will not be considered EMV certified by any card brand.</strong>
///
/// \return A VPDEmvDevice object if the device supports EMV, otherwise nil.
///
-(VPDEmvDevice)getAsEmvDevice;




#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

///
/// \brief Definition for a device capable of doing keyboard numeric input
///
/// Definition for a device capable of doing keyboard numeric input.
///
typedef NSObject<VPDKeyboardNumericInput> * VPDKeyboardNumericInputDevice;

///
/// \brief Get the current device as a keyboard numeric input device
///
/// This method attempts to get the current device as a keyboard numeric input device.
///
/// \return A VPDKeyboardNumericInputDevice object if the device supports keyboard numeric input, otherwise nil.
///
-(VPDKeyboardNumericInputDevice)getAsKeyboardNumericInputDevice;

///
/// \brief Definition for a device capable of doing PIN input
///
/// Definition for a device capable of doing PIN input.
///
typedef NSObject<VPDPinInput> * VPDPinInputDevice;

///
/// \brief Get the current device as a PIN input device
///
/// This method attempts to get the current device as a PIN input device.
///
/// \return A VPDPinInputDevice object if the device supports PIN input, otherwise nil.
///
-(VPDPinInputDevice)getAsPinInputDevice;

///
/// \brief Definition for a device capable of doing yes/no input
///
/// Definition for a device capable of doing yes/no input.
///
typedef NSObject<VPDYesNoInput> *VPDYesNoInputDevice;

///
/// \brief Get the current device as a yes/no input device
///
/// This method attempts to get the current device as a yes/no input device.
///
/// \return A VPDYesNoInputDevice object if the device supports yes/no input, otherwise nil.
///
-(VPDYesNoInputDevice)getAsYesNoInputDevice;

///
/// \brief Definition for a device capable of doing barcode input
///
/// Definition for a device capable of doing barcode input.
///
typedef NSObject<VPDBarcodeInput> *VPDBarcodeInputDevice;

///
/// \brief Get the current device as a barcode input device
///
/// This method attempts to get the current device as a barcode input device.
///
/// \return A VPDBarcodeInputDevice object if the device supports barcode input, otherwise nil.
///
-(VPDBarcodeInputDevice)getAsBarcodeInputDevice;

@end

#endif /* VPDDevice_h */
