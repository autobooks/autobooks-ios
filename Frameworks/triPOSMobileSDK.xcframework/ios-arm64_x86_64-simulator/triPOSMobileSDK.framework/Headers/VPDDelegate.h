///
/// \file VPDDelegate.h
///

#ifndef VPDDeviceDelegate_h
#define VPDDeviceDelegate_h

#import "VPDDevice.h"
#import "VPDTokenType.h"
#import "VTPBluetoothDevice.h"
#import "VPDPairingConfirmationCallback.h"
#import "VTPInitializationStatus.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \protocol VPDDelegate
///
/// \brief Protocol for the device notifications
///
/// The VPDDelegate protocol defines the methods a receiver may implement for device notifications.
///
@protocol VPDDelegate

@optional

///
/// \brief Device connected
///
/// Tells the delegate a recognized device has been connected.
///
/// \param device An NSObject representing a device that implements at minimum the VPDDevice protocol.
///
/// \param description The description of the device connected.
///
/// \param serialNumber The serial number of the device connected. This value may be nil if the connected device does not supply this value. In some cases, this value may not be available immediately upon connection.
///
-(void)deviceDidConnect:(NSObject<VPDDevice> *)device description:(NSString *)description model:(NSString *)model serialNumber:(NSString *)serialNumber;

///
/// \brief Device connected
///
/// Tells the delegate a recognized device has been connected.
///
/// \param device An NSObject representing a device that implements at minimum the VPDDevice protocol.
///
/// \param description The description of the device connected.
///
/// \param serialNumber The serial number of the device connected. This value may be nil if the connected device does not supply this value. In some cases, this value may not be available immediately upon connection.
///
/// \param firmwareVersion The firmware vesion of the connected device.
///
/// \param configurationVersion The configuration version of the connected device.
///
///
-(void)deviceDidConnect:(NSObject<VPDDevice> *)device description:(NSString *)description model:(NSString *)model serialNumber:(NSString *)serialNumber firmwareVersion:(NSString*) firwareVersion configurationVersion:(NSString*) configurationVersion;


///
/// \brief Device disconnected
///
/// Tells the delegate the device has been disconnected.
///
/// \param device An NSObject representing a device that implements at minimum the VPDDevice protocol.
///
-(void)deviceDidDisconnect:(NSObject<VPDDevice> *)device;

///
/// \brief Device generated an error
///
/// Tells the delegate the device generated an error. This notification is only generated for errors occuring outside specific functionality supplied by the device.
///
/// \param device An NSObject representing a device that implements at minimum the VPDDevice protocol.
///
/// \param error The error.
///
-(void)deviceDidError:(NSObject<VPDDevice> *)device error:(NSError *)error;

///
/// \brief Device initialized
///
/// Tells the delegate the device initialized. This notification is only generated for errors occuring outside specific functionality supplied by the device.
///
/// \param device An NSObject representing a device that implements at minimum the VPDDevice protocol.
///
/// \param error The error.
///
-(void)deviceDidInitialize:(NSObject<VPDDevice> *)device;

///
/// \brief Device initialization in progress.
///
/// Updated the delegate on the progress of device initialization.
///
/// \param currentProgress Percent complete of device initialization.
///
/// \param device An NSObject representing a device that implements at minimum the VPDDevice protocol.
///
/// \param error The error.
///
-(void) deviceInitializationInProgress:(double) currentProgress device:(NSObject<VPDDevice> *)device currentStep:(NSString*) currentStep;


///
/// \brief Device initialization in progress.
///
/// Updated the device on the progress of device initialization
///
/// \param currentProgress Percentage completion of the current initialization status
///
/// \param description Current status description
///
/// \param model Device model
///
/// \param serialNumber serial number of the device
///
/// \param Current initialization status
-(void) deviceInitializationInProgress:(double) currentProgress description:(NSString *)description model:(NSString *)model serialNumber:(NSString *)serialNumber initializationStatus:(VTPInitializationStatus) initializationStatus;


///
/// \brief Heartbeat failed to connect to the device after 10 attempts.
///
/// Informs the device that the heartbeat failed to connect after 10 attempts.
///
/// \param description Description
///
-(void) heartbeatDidTimeout:(NSString*)description;

//
///
/// \brief Block definition for the token request completion handler.
///
/// Block definition for the token request completion handler.
///
/// \param token The token from the provider.
///
/// \sa deviceDoesNeedTokenFromTokenProvider
///
typedef void (^VPDTokenCompletionHandler)(id token);

///
/// \brief Block definition for the token request error handler.
///
/// Block definition for the token request error handler.
///
/// \param token The error from the token request.
///
/// \sa deviceDoesNeedTokenFromTokenProvider
///
typedef void (^VPDTokenErrorHandler)(NSError *error);

///
/// \brief Device needs a token from the token provider.
///
/// The device use this delegate method to request a needed token from the host.
///
/// \param tokenType Tye type of token to request.
///
/// \param error Contains information about any error that occurred.
/// 
/// \return YES if the request was handled, NO otherwise.
///
-(BOOL)deviceDoesNeedTokenFromTokenProvider:(VPDTokenType)tokenType completionHandler:(VPDTokenCompletionHandler)completionHandler errorHandler:(VPDTokenErrorHandler)errorHandler;

///
/// \brief Returns list of scanned devices.
///
/// Returns a list of the available devices of the specified device type in the configuration.
///
/// \param devices List of identifiers of available devices.
///
-(void) onReturnBluetoothScanResults:(NSArray<VTPBluetoothDevice*>*) devices;

///
/// \brief Moby device pairing confiramtion
///
/// This method returns device pairing confirmation callback
///
///
-(void) onReturnPairingConfirmation:(NSArray*) ledSequence deviceName:(NSString*) deviceName callback:(id<VPDPairingConfirmationCallback>) pairingCallBack;

/// \brief Device generated a warning
///
/// Tells the delegate the device generated a warning.
///
/// \param warning  The warning
-(void) sendWarning: (NSString *) warning;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDDeviceDelegate_h */
