//
//  VTPDeviceSetupResult.h
//  triPOSMobileSDK
//
//  Created on 3/19/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTPDeviceConnectionInfo.h"

#ifndef VTPDeviceSetupResult_h
#define VTPDeviceSetupResult_h

@interface VTPDeviceSetupResult : VTPDeviceConnectionInfo

///
/// \brief status of device configuration
///
/// Indicates if the device from the device pool was successfully configured
///
@property (nonatomic) BOOL didConfigureSuccessfully;

///
/// \brief details of error in case of failure to configure successfully
///
/// The error details in case of
///
@property (nonatomic, retain) NSError* error;

-(instancetype)initWith:(VTPDeviceConnectionInfo *) connectionInfo;

@end


#endif /* VTPDeviceSetupResult_h */
