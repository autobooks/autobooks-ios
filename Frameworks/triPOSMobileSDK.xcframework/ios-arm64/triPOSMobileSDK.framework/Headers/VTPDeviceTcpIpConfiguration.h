///
/// \file VTPDeviceTcpIpConfiguration.h
///

#ifndef VTPDeviceTcpIpConfiguration_h
#define VTPDeviceTcpIpConfiguration_h

///
/// \class VTPDeviceTcpIpConfiguration
///
/// \brief The device TCP/IP configuration class
///
/// This class defines methods and properties for the device TCP/IP configuration.
//
@interface VTPDeviceTcpIpConfiguration : NSObject

///
/// \brief Gets or sets the device IP address
///
/// This property gets or sets the device IP address.
///
@property (retain, nonatomic) NSString *ipAddress;

///
/// \brief Gets or sets the device port
///
/// This property gets or sets the device port
///
@property (nonatomic) NSUInteger port;

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

#endif /* VTPDeviceTcpIpConfiguration_h */
