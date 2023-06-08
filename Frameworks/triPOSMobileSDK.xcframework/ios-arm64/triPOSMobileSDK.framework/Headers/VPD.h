///
/// \file VPD.h
///

#import <Foundation/Foundation.h>

#import "VPDDevice.h"
#import "VPDDelegate.h"
#import "VPDType.h"

#import "VPDCardInput.h"
#import "VTPCardData.h"
#import "VTPEncryptedKeyedCardData.h"
#import "VTPEncryptedSwipedCardData.h"
#import "VTPKeyedCardData.h"
#import "VTPSwipedCardData.h"

#import "VPDBeep.h"
#import "VPDChoiceInput.h"
#import "VPDDisplay.h"
#import "VPDKeyboardNumericInput.h"
#import "VPDPinInput.h"
#import "VPDYesNoInput.h"
#import "VPDBarcodeInput.h"


///
/// \class VPD
///
/// \brief The device class
///
/// This class defines methods and properties for the device.
///
@interface VPD : NSObject

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \brief Creates and returns a device of the given type.
///
/// Creates and returns a device of the given type.
///
/// \param The type.
///
/// \return An initialized device if the type is supported, otherwise nil.
///
+(NSObject<VPDDevice> *)deviceWithType:(VPDType)type;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end
