///
/// \file VTPDeviceConfiguration.h
///

#import <Foundation/Foundation.h>

#import "VTPDeviceType.h"
#import "VTPTerminalType.h"
#import "VTPDeviceTcpIpConfiguration.h"

///
/// \class VTPDeviceConfiguration
///
/// \brief The device configuration class
///
/// This class defines methods and properties for the device configuration.
///
@interface VTPDeviceConfiguration : NSObject

///
/// \brief Gets or sets the device type
///
/// This property gets or sets the device type.
///
@property (nonatomic) VTPDeviceType deviceType;

///
/// \brief Gets or sets the TCP/IP device configuration
///
/// This property gets or sets the TCP/IP device configuration.<br /><br /><strong>NOTE:</strong> This property only affects devices that support TCP/IP.
///
/// \sa deviceType
///
@property (retain, nonatomic) VTPDeviceTcpIpConfiguration *tcpIpConfiguration;

///
/// \brief Gets or sets the terminal type
///
/// The property gets or sets the terminal type.
///
@property (nonatomic) VTPTerminalType terminalType;

///
/// \brief Gets or sets if keyed card entry allowed
///
/// This property gets or sets a value indicating if keyed card entry is allowed.
/// 
@property (nonatomic) BOOL isKeyedEntryAllowed;

///
/// \brief Gets or sets if contactless entry is allowed
///
/// This property gets or sets a value indicating if contactless entry is allowed.
///
@property (nonatomic) BOOL isContactlessEntryAllowed;

///
/// \brief Gets or sets the terminal ID
///
/// This property gets or sets the terminal ID.
///
@property (retain, nonatomic) NSString *terminalId;

///
/// \brief Gets the terminal ID with all but the last four digits masked
///
/// This property gets the terminal ID with all but the last four digits maske.
///
@property (retain, nonatomic, readonly) NSString* maskedTerminalId;

///
/// \brief Gets or sets the serial number of the terminal to connect to.
///
/// This property gets or sets the serial number of the terminal to connect to.  It is only supported for
/// BLE (Bluetooth Low-Energy) devices.
///
@property (retain, nonatomic) NSString *identifier;

///
/// \brief Gets or sets the device reboot time hour component
///
/// This property gets or sets the device reboot time hour component. This value should be 0-23.
///
@property (nonatomic) int rebootTimeHour;

///
/// \brief Gets or sets the device reboot time minutes component
///
/// This property gets or sets the device reboot time minutes component. This value should be 0-59.
///
@property (nonatomic) int rebootTimeMinutes;

///
/// \brief Gets or sets the device contactless card detection time
///
/// This property gets or sets the device contactless card detection time in seconds. Can be 0 or higher.
///
@property (nonatomic) double contactlessDetectionTime;

///
/// \brief Sets the hour of the day for which to restart the terminal
///
/// Sets the hour of the day for which to restart the terminal
///
-(void)setRebootTimeWithHour:(int)hour withMinutes:(int)minutes;

///
/// \brief Validates the reboot time
///
/// This method ensures that the reboot time supplied is within the expected bounds.
///
-(BOOL)validateRebootTime:(NSError **)error;

///
/// \brief Validates the configuration.
///
/// This method validates the configuration. While some items may have their values verified, others are only checked to ensure they are not nil and/or empty.
///
/// \param error Pointer to NSError object. If the enable fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)validateConfiguration:(NSError **)error;

@end
