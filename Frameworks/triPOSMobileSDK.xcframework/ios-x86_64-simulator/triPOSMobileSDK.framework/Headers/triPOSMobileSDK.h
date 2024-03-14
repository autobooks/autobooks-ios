///
/// \file  triPOSMobileSDK.h
///

///
/// \mainpage Worldpay Integrated Payments triPOS® Mobile SDK
///
/// \section overview Overview
///
/// The Worldpay triPOS® Mobile SDK Framework is designed to allow iOS applications rapid integration for EMV support, point-of-interaction device support, and the Worldpay Integrated Payments Express platform. While the framework has been certified for EMV and to the Express platform, the application to which it is being integrated must also complete testing with Worldpay Integrated Payments and the Express platform to ensure all necessary fields are populated with the correct data and receipts are generated with the required information.
///
/// \section requirements Requirements
///
/// \subsection requirementsAppleMFi Apple MFi Program
///
/// For each manufacturer whose accessory is supported in the application, that manufacturer must add the application to their MFi PPID (Made for iOS product plan ID). Without this, the App Store submission will be rejected. In other words, for each accessory protocol used (see @ref projectSettingsExternalAccessories), the application must be added to that manufacturers MFi PPID.<br /><br /><strong>NOTE: MFi PPID's only apply to 30-pin/Lightning or Bluetooth connected accessories. It does not apply to audio jack, TCP/IP, nor Bluetooth Low Power connected accessories.</strong>
///
/// \subsection requirementsiOSDeveloper iOS developer
///
/// <ul>
///
/// <li>You must have an Intel-based Mac running Mac OS X El Capitan or later.</li>
///
/// <li>You must be <a href='https://developer.apple.com/programs/register/'>registered</a> as an Apple Developer. For more information on the iOS Developer Program, go to <a href='https://developer.apple.com/support/ios'>https://developer.apple.com/support/ios</a>.</li>
///
/// <li>You must have <a href='https://itunes.apple.com/us/app/xcode/id497799835?mt=12'>Xcode</a> installed.</li>
///
/// </ul>
///
/// \subsection requirementsiOSVersion iOS version
///
/// The Worldpay triPOS® Mobile SDK Framework was developed for and tested using the following iOS's:
///
/// <ul>
///
/// <li>iOS 15</li>
///
/// <li>iOS 16</li>
///
/// <li>iOS 17</li>
///
/// </ul>
///
/// \subsection requirementsFramework Framework
///
/// <ul>
///
/// <li>The iOS device being used requires a data connection. The data connection does not have to be always available, but it does have to be available at the time a transaction is processed. This connection may be Wi-Fi, mobile data, or any other data connection available that allows an HTTPS connection to the Express host.</li>
///
/// <li>You must have credentials assigned by Worldpay Integrated Payments to use this framework. For development and certification, you may sign up for a free test account by <a href='https://developerengine.fisglobal.com/apis/tripos/tripos-mobile'>clicking here</a> or visiting <a href='https://developerengine.fisglobal.com/'>www.developerengine.fisglobal.com</a>. For production use, contact your Worldpay Integrated Payments sales representative.</li>
///
/// </ul>
///
/// \section gettingStarted Getting started
///
/// \subsection addFramework Adding the framework to your project
///
/// <ol>
///
/// <li>Copy triPOSMobileSDK.xcframework to your local project folder.</li>
///
/// <li>Open the project settings and select the application target.</li>
///
/// <li>Open the 'General' tab.</li>
///
/// <li>Scroll down to 'Embedded Binaries' and click the '+' symbol under the list.</li>
///
/// <li>Click 'Add Other'.</li>
///
/// <li>Browse to the location where the Worldpay triPOS® Mobile SDK Framework was copied in the first step.</li>
///
/// <li>Select the triPOSMobileSDK.xcframework folder.</li>
///
/// <li>Click 'Open'.</li>
///
/// <li>Scroll down to 'Linked Frameworks and Libraries' and click the '+' symbol under the list.</li>
///
/// <li>Find and select ExternalAccessory.framework.</li>
///
/// <li>Click 'Add'.</li>
///
/// </ol>
///
/// \subsubsection projectSettingsExternalAccessories External accessories
///
/// To use the supported external devices, the appropriate protocols must be added to the project settings.
///
/// <ol>
///
/// <li>Open the project settings and select the application target.</li>
///
/// <li>Open the 'Info' tab.
///
/// <li>In the 'Custom iOS Target Properties' section, add the 'Supported external accessory protocols' setting.</li>
///
/// <li>Add each of the protocols listed below for the necessary devices:</li>
///
/// <ul>
///
/// <li>Ingenico</li>
/// <ul>
/// <li>com.ingenico.easypayemv.spm-transaction</li>
/// <li>com.ingenico.easypayemv.spm-networkaccess</li>
/// <li>com.ingenico.easypayemv.spm-sppchannel</li>
/// <li>com.ingenico.easypayemv.spm-pppchannel</li>
/// <li>com.ingenico.easypayemv.spm-configuration</li>
/// <li>com.landicorp.USBdatapath</li>
/// </ul>
///
/// </ul>
///
/// </ol>
///
///
/// \subsection addDeviceFirmwareFiles Adding device firmware files for Ingenico devices
///
/// Each version of the Worldpay triPOS® Mobile SDK Framework, if used with any Ingenico payment devices, requires that the payment device be updated to the correct firmware.  For each Ingenico device that is supported, the firmware file (with extension *.OGZ) must be added to the target iOS app product in the project.  The correct firmware file(s) to add can be found in a subfolder with the same name as the supported device in the "Firmware Files" folder.  
///
/// \subsection CustomIdleImage Custom idle images for Ingenico Tetra devices
///
///  A jpeg\jpg, png or gif image can be used as an idle image. The image file needs to be included in the target iOS app and the file name needs to be specified in the Application configuration during initialization. triPOS® Mobile SDK would look for an idle image and if not found picks the idlePrompt. If neither the idle image nor the prompt is provided, the default triPOS logo would be displayed. This is supported only on the Tetra devices (Lane 3000 and Link 2500) and not supported on Telium devices (iSmp4 and iPP350).
///
///  \subsection BinWhiteListing BIN whitelisting
///
///  A optional BIN whitelisting file can be included with the target iOS App. The file name needs to be specified in the application configuration during initialization.
///
/// \subsection BBPosChipper3XBTPairing  BBPos Chipper 3X BT Pairing
///
/// When a user first attemps to connect to a BBPos Chipper 3X BT device via the triPOS® Mobile SDK Framework, they will be prompted to enter a 6 digit code.  This code is located on the back of the BBPPos Chipper 3X BT device and is labeled BT Passkey.  After the code is correctly entered, the BBPos Chipper 3X BT device will be paired to the iOS device.
///
/// \subsection Ingenico Moby/5500 Pairing
/// <ul>
///
/// <li>Bluetooth Pairing</li>
/// <ul>
/// <li>During the first attempt to connect a Moby/5500 to the triPOS® Mobile SDK Framework, when prompted for Bluetooth pairing, select Pair. When prompted to confirm pairing, select Ok. The Moby/5500 is now paired with the iOS device.</li>
/// </ul>
///
/// </ul>
///
/// <ul>
/// 
/// <li>USB Pairing</li>
/// <ul>
/// <li>To connect a Moby/5500 to the triPOS® Mobile SDK Framework using USB, an Ingenico Moby USB to Lightning cable must be used. No pairing is required, simply connect the appropriate ends of the cable to each device and initialize the SDK.</li>
/// </ul>
///
/// </ul>
///
/// \subsection useFramework Using the framework
///
/// The Worldpay triPOS® Mobile SDK Framework is used by importing it (@import triPOSMobileSDK;) then accessing the SDK functionality through the sharedVtp singleton. The SDK must be initialized before performing any functions and if those functions require the device, the application must wait for the device to become connected.<br /><br /><strong style="color:red;">NOTE: If necessary, the triPOS® Mobile SDK will update device firmware and settings. If a firmware update is required, the first initialization may take 10 or more minutes depending on the connection type.</strong>
///
/// \section submittingToTestFlightOrAppStore Submitting to TestFlight or App Store
///
/// <ul>
///
/// <li>In order to submit your app to TestFlight or the App Store you must first strip unneeded architectures from your project.</li>
///
/// <li>See: <a href="../How to remove unneeded architectures from XCode projects.doc">How to remove unneeded architectures from XCode projects</a></li>
///
/// </ul>
///
/// \section certificatons Certifications
///
/// \subsection certificationInfo EMV Certifications
///
/// For each payment device supported in the application, Worldpay triPOS® Mobile SDK Framework must be certified for use with the selected payment processor.
///
/// <ul>
///     <li>Ingenico RBA and Ingenico RBA TCP/IP
///         <ul>
///             <li>FIS/Worldpay</li>
///             <li>Fiserv/First Data - QuickChip only</li>
///        </ul>
///     </li>
///     <li>Ingenico UPP and Ingenico UPP TCP/IP
///         <ul>
///             <li>FIS/Worldpay</li>
///             <li>Fiserv/First Data </li>
///             <li>TSYS</li>
///         </ul>
///     </li>
///     <li>BBPos
///         <ul>
///             <li>FIS/Worldpay - QuickChip only</li>
///         </ul>
///     </li>
///       <li>Ingenico Moby Bluetooth and Ingenico Moby USB
///         <ul>
///             <li>FIS/Worldpay</li>
///         </ul>
///     </li>
/// </ul>
///
/// \section support Support
///
/// Please contact <a href="mailto:dldipartnersupport@fisglobal.com?body=Please complete the following:%0D%0A%0D%0AYour name:%20%0D%0ACompany name:%20%0D%0APhone number:%20%0D%0AE-mail if different from sending e-mail:%20%0D%0A%0D%0ADescription of the problem:%20">triPOS® Mobile SDK support</a>.
///
/// \section license SDK License Agreement
///
/// <a href="triPOS%C2%AE%20Interface%20Software%20License%20-%20v1.2022.pdf">triPOS® Interface Software License - v1.2022.pdf</a>.
///
/// \section triPOS® Mobile SDK Integration Guide
/// <a href="triPOS%C2%AE%20Mobile%20iOS%20SDK%20Integration%20Guide.pdf">triPOS® Mobile iOS SDK Integration Guide.pdf</a>.
///
/// \section releaseNotes Release Notes
///
/// <a href="../changelog.txt">changelog.txt</a>
///

#import <Foundation/Foundation.h>

//! Project version number for triPOSMobileSDK.
FOUNDATION_EXPORT double triPOSMobileSDKVersionNumber;

//! Project version string for triPOSMobileSDK.
FOUNDATION_EXPORT const unsigned char triPOSMobileSDKVersionString[];

#import "triPOSMobileSDK+Ttp.h"
#import "VTP.h"
#import "VTP+Sale.h"
#import "VTP+Refund.h"
#import "VTP+Authorization.h"
#import "VTP+GiftCardActivate.h"
#import "VTP+GiftCardBalanceInquiry.h"
#import "VTP+GiftCardReload.h"
#import "VTP+GiftCardUnload.h"
#import "VTP+ManuallyForward.h"
#import "VTP+QueryStoreDatabase.h"
#import "VTP+EbtVoucher.h"
#import "VTP+EBTCardBalanceInquiry.h"
#import "VPD.h"
#import "VXP.h"
#import "VTP+GiftCardClose.h"
#import "VTP+GiftCardBalanceTransfer.h"
#import "VTP+HostedPaymentsSale.h"
#import "VTP+HostedPaymentsAuthorization.h"


@interface triPOSMobileSDK : NSObject

///
/// \brief The singleton instance of the triPOS Mobile SDK
///
/// Provides access to the singleton instance of the triPOS Mobile SDK.
///
+(id)sharedVtp;

///
/// \brief Gets the version of the triPOS Mobile SDK
///
/// Gets the version of the triPOS Mobile SDK.
///
+(NSString *)version;

+(NSArray<NSString *> *)logFileList;

@end
