///
/// \file VTPConfiguration.h
///

#ifndef VTPConfiguration_h
#define VTPConfiguration_h

#import <Foundation/Foundation.h>

#import "VTPApplicationConfiguration.h"
#import "VTPDeviceConfiguration.h"
#import "VTPEmvConfiguration.h"
#import "VTPHostConfiguration.h"
#import "VTPStoreAndForwardConfiguration.h"
#import "VTPTransactionConfiguration.h"

///
/// \class VTPConfiguration
///
/// \brief The main configuration class
///
/// This class defines methods and properties for the main configuration.
///
@interface VTPConfiguration : NSObject

///
/// \brief Gets or sets the application configuration
///
/// This property gets or sets the application configuration.
///
@property (retain, nonatomic) VTPApplicationConfiguration *applicationConfiguration;

///
/// \brief Gets or sets the device configuration
///
/// This property gets or sets the device configuration.
///
@property (retain, nonatomic) VTPDeviceConfiguration *deviceConfiguration;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \brief Gets or sets the EMV configuration
///
/// This property gets or sets the EMV configuration.
///
@property (retain, nonatomic) VTPEmvConfiguration *emvConfiguration;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

///
/// \brief Gets or sets the host configuration
///
/// This property gets or sets the host configuration.
///
@property (retain, nonatomic) VTPHostConfiguration *hostConfiguration;

///
/// \brief Gets or sets the store and forward configuration
///
/// This property gets or sets the store and forward configuration.
///
@property (retain, nonatomic) VTPStoreAndForwardConfiguration *storeAndForwardConfiguration;

///
/// \brief Gets or sets the transaction configuration
///
/// This property gets or sets the transaction configuration.
///
@property (retain, nonatomic) VTPTransactionConfiguration *transactionConfiguration;

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

#endif /* VTPConfiguration_h */