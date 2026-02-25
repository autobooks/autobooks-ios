//
//  VTPDeviceConnectionInfo.h
//  triPOSMobileSDK
//
//  Created on 2/13/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//
#import <Foundation/Foundation.h>

#import "VTPDeviceType.h"
#import "VTPDeviceTcpIpConfiguration.h"

#ifndef VTPDeviceConnectionInfo_h
#define VTPDeviceConnectionInfo_h

@interface VTPDeviceConnectionInfo : NSObject

///
/// \brief The type of the device in the device pool
///
/// Gets or sets the device type of the device in the device pool
///
@property (nonatomic) VTPDeviceType deviceType;

///
/// \brief The bluetooth identifier of the device in the device pool
///
/// Gets or sets the bluetooth identifier of the device to be connected
///
@property (retain, nonatomic) NSString *identifier;

///
/// \brief TCP\IP configuration of the device in the device pool
///
/// Gets or sets the TCP\IP configuration of the device in the device pool
///
@property (retain, nonatomic) VTPDeviceTcpIpConfiguration *tcpIpConfiguration;

///
/// \brief Description or an identifier of the device in the device poolß
///
/// Gets or sets the description of the device in the device pool
///
@property (retain, nonatomic) NSString *deviceDescription;

///
/// \brief Gets or sets the idle prompt
///
/// This prompt is displayed on the device when idle. This value may be nil in which case, the default idle screen is displayed.
///
@property (retain, nonatomic) NSString *idlePrompt;

/// \brief Gets or sets the idle image name
///
/// Gets or sets the name of the idle image to be loaded and displayed on the device. The value can be nil and the idle prompt will be used instead of the image
///
@property (retain, nonatomic) NSString *idleImageName;

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

#endif /* VTPDeviceConnectionInfo_h */
