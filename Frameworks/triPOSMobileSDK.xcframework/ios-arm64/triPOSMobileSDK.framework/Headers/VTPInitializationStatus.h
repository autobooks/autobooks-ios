//
//  VTPInitializationStatus.h
//  triPOSMobileSDK
//
//  Created on 8/26/22.
//  Copyright © 2022 Worldpay from FIS. All rights reserved.
//

#ifndef VTPInitializationStatus_h
#define VTPInitializationStatus_h


///
/// \enum VTPDeviceType
///
/// The current SDK initialization status
///
typedef enum _VTPInitializationStatus
{
    /// Updating device firmware
    VTPInitializationStatusUpdatingFirmware,
    
    /// Updating files to device (Forms, Custom Prompts etc.)
    VTPInitializationStatusUpdatingFiles,
    
    /// Updating P2PE files
    VTPInitializationStatusConfiguringP2pe,
    
    /// Updating EMV contact and contactless files
    VTPInitializationStatusConfiguringEmv,
    
    /// Updating device configuration
    VTPInitializationStatusConfiguring,
    
    /// Update local time on device clock
    VTPInitializationStatusSettingClock,
    
    /// Performing device reboot
    VTPInitializationStatusRebootingDevice
}   VTPInitializationStatus;

#endif /* VTPInitializationStatus_h */
