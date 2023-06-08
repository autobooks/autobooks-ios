///
/// \file VPDAppleTapToPay.h
///

#ifndef VPDAppleTapToPay_h
#define VPDAppleTapToPay_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDDevicePrivate.h"

#import <triPOSMobileSDK/triPOSMobileSDK-Swift.h>

@interface VPDAppleTapToPay : VPDDevicePrivate <VPDDevicePrivate>
{
    BOOL isApplicationInBackground;
    
    PaymentCardReaderToken *paymentCardReaderToken API_AVAILABLE(ios(16));
    
    PaymentCardReaderBridge *paymentCardReaderBridge API_AVAILABLE(ios(16));
}

///
/// \brief Checks if the device is initialized and calls the error handler if not
///
/// This method checks of the device is initialized and calls the handler if not.
///
/// \return YES if not initialized, NO otherwise.
///
-(BOOL)errorIfNotInitialized:(VPDErrorHandler)errorHandler;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDAppleTapToPay_h */
