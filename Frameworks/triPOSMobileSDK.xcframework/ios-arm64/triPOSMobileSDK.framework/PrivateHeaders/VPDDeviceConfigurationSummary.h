//
//  VPDDeviceConfigurationSummary.h
//  triPOSMobileSDK
//
//  Created on 2/29/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//

#ifndef VPDDeviceConfigurationSummary_h
#define VPDDeviceConfigurationSummary_h

#import "VTPAidPreference.h"
#import "VTPDeviceLanguage.h"


@interface VPDDeviceConfigurationSummary : NSObject


///
/// \brief Gets or sets the idle prompt
///
/// This property is prompt displayed on the device when idle. This value may be nil.
///
@property (retain, nonatomic) NSString *idlePrompt;

///
/// \brief Gets or sets the idle image name
///
/// This property is  image displayed on the device when idle. This value may be nil.
///
@property (retain, nonatomic) NSString *idleImageName;

///
/// \brief Gets or sets if contactless entry is allowed
///
/// This property gets or sets if contactless entry is allowed.
///
@property (nonatomic) BOOL isContactlessEntryAllowed;


///
/// \brief Gets or sets if EMV is supported.
///
/// This property gets or sets if EMV is supported.
///
@property (nonatomic) BOOL isEmvAllowed;

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
/// \brief Gets or sets if Quick Chip is supported.
///
/// This property gets or sets if Quick Chip is supported.
///
@property (nonatomic) BOOL quickChipEnabled;


///
/// \brief Sets the preferred default AID selection.
///
/// This property sets the preferred default AID selection. The default value prompts the card holder if multiple AID's exist on the card. Other values prefer the US Common Debit AID or the global AID.
///
@property (assign, nonatomic) VTPAidPreference aidPreference;

///
/// \brief Specifies if we are connecting certification/test.
///
/// This property lets us know if we are running in a production environment.  If it is NO we are running in a production environment.
///
@property (assign, nonatomic) BOOL testCertification;

///
/// \brief Gets or sets if contactless Emv Pin Bypass is allowed.
///
/// This property gets or sets if contactless EMV Pin Bypass is allowed.
///
@property (assign, nonatomic) BOOL isContactlessEmvPinBypassAllowed;

///
/// \brief Gets or sets if cashback is allowed.
///
/// This property gets or sets if cashback is allowed.
///
@property (assign, nonatomic) BOOL isCashbackAllowed;

///
/// \brief Gets or sets if custom aid selection is enabled.
///
/// This property gets or sets if custom aid is enabled.
///
@property (nonatomic) BOOL isCustomAidSelectionEnabled;

///
/// \brief Gets or sets the device contactless card detection time
///
/// This property gets or sets the device contactless card detection time in seconds. This value should be 0 or more.
///
@property (nonatomic) double contactlessDetectionTime;

///
/// \brief Gets or sets the triPOS SDK version
///
/// This property gets or sets the version of hte triPOS SDK
///
@property (retain, nonatomic) NSString *triPOSVersion;

///
/// \brief Gets or sets the checksum for the EMV contact configuration file
///
/// This property gets or sets the check sum of the EMV contact configuration file
///
@property (retain, nonatomic) NSString *emvConfigFileCheckSum;

///
/// \brief Gets or sets the checksum for the EMV contactless configuration file
///
/// This property gets or sets the check sum of the EMV contactless configuration file
///
@property (retain, nonatomic) NSString *emvContactlessConfigFileCheckSum;

///
/// \brief Gets or sets the checksum for the Tags.xml file
///
/// This property gets or sets the check sum of the Tags.xml file
///
@property (retain, nonatomic) NSString *tagsFileCheckSum;

///
/// \brief Gets or sets the idle image name
///
/// This property is  image displayed on the device when idle. This value may be nil.
///
@property (nonatomic) VTPDeviceLanguage defaultDeviceLanguage;

///
/// \brief Gets or sets the BIN whitelist file name
///
/// This property gets or sets the BIN whitelist file name if provided through configuration.
///
@property (retain, nonatomic) NSString *binWhitelistFileName;

///
/// \brief Gets or sets if enable Wi-Fi roaming.
///
/// This property gets or sets the enable/disable Wi-Fi roaming configuration
///
@property (assign, nonatomic) BOOL enableWiFiRoaming;

@end

#endif /* VPDDeviceConfigurationSummary_h */
