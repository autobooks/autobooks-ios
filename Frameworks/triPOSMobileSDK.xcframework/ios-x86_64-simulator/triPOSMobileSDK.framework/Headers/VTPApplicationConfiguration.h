///
/// \file VTPApplicationConfiguration.h
///

#ifndef VTPApplicationConfiguration_h
#define VTPApplicationConfiguration_h

#import <Foundation/Foundation.h>

#import "VTPApplicationMode.h"

///
/// \class VTPApplicationConfiguration
///
/// \brief The application configuration class
///
/// This class defines methods and properties for the application configuration class
///
@interface VTPApplicationConfiguration : NSObject

///
/// \brief Gets or sets the application mode
///
/// This property is used to set the application mode.
///
@property (nonatomic) VTPApplicationMode mode;

///
/// \brief Gets or sets the idle prompt
///
/// This prompt is displayed on the device when idle. This value may be nil in which case, the default idle screen is displayed.
///
@property (retain, nonatomic) NSString *idlePrompt;
///
/// \brief Gets or sets the whitelist file name
///
/// This file name is used to download a BIN range whitelist file, This value may be nil in which case, no file is downloaded to the POI device
///
@property (retain, nonatomic) NSString *binWhitelistFile;

/// \brief Gets or sets the idle image name
///
@property (retain, nonatomic) NSString *idleImageName;
///
/// \brief Gets or sets the merchant name
///
/// This value is displayed whenever the merchant name is required.
///
@property (retain, nonatomic) NSString *merchantName;

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

#endif /* VTPApplicationConfiguration_h */
