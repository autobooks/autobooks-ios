///
/// \file VPDNull.h
///

#ifndef VPDNull_h
#define VPDNull_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDDevicePrivate.h"

@interface VPDNull : VPDDevicePrivate <VPDDevicePrivate>

///
/// \brief Checks if the device is connected and calls the error handler if not
///
/// This method checks of the device is connected and calls the handler if not.
///
/// \return YES if not connected, NO otherwise.
///
-(BOOL)errorIfNotConnected:(VPDErrorHandler)errorHandler;

///
/// \brief Checks if the device is initialized and calls the error handler if not
///
/// This method checks of the device is initialized and calls the handler if not.
///
/// \return YES if not initialized, NO otherwise.
///
-(BOOL)errorIfNotInitialized:(VPDErrorHandler)errorHandler;

@property (nonatomic, readonly) VPDInitializationParameters* initializationParameters;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDNull_h */
