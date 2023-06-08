///
/// \file VTPEmvConfiguration.h
///

#ifndef VTPEmvConfiguration_h
#define VTPEmvConfiguration_h

#import "VTPEmvRid.h"
#import "VTPCaPublicKey.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \class VTPEmvConfiguration
///
/// \brief The EMV configuration class
///
/// This class defines the methods and properties for the EMV configuration.
///
@interface VTPEmvConfiguration : NSObject

///
/// \brief Gets or sets the terminal capability
///
/// This property gets or sets the terminal capability. See EMV book 4, annex A2.
///
@property (retain, nonatomic) NSString *terminalCapability;

///
/// \brief Gets or sets the additional terminal capability
///
/// This property gets or sets the additional terminal capability. See EMV book 4, annex A3.
///
@property (retain, nonatomic) NSString  *additionalTerminalCapability;

///
/// \brief Gets or sets the EMV registered application arovider identifier's (RID) used
///
/// This property gets or sets the EMV registered application provider identifier's (RID) used.
///
@property (retain, nonatomic) NSArray<VTPEmvRid *> *rids;

///
/// \brief Gets of sets the certification authority (CA) public keys
///
/// The property gets or sets certification authority (CA) public keys.
///
/// \sa mode
///
@property (retain, nonatomic) NSArray<VTPCaPublicKey *> *caPublicKeys;

///
/// \brief Enables or disables Quick Chip.
///
/// This property enables or disables Quick Chip.
///
/// \sa mode
///
@property (assign, nonatomic) BOOL quickChipEnabled;

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

///
/// \brief Initializes the EMV Configuration based on a specific property list file.
///
/// \param configFileName Name of property list file to use (without the file extension)
///
/// \return VTPEmvConfiguration object.
///
-(instancetype)initWithConfigurationFile:(NSString*) configFileName;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEmvConfiguration_h */
