///
/// \file VTP+AutoForwardWatcher.h
///

#ifndef VTP_AutoForwardWatcher_h
#define VTP_AutoForwardWatcher_h

#import "VTP.h"
#import "triPOSMobileSDK.h"
#import "VTP+StoreAndForward.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface VTP(AutoForwardWatcher)

+(void)startAutoForwardWatcher;

+(void)startAutoForwardWatcherIfNotAlreadyStarted;

+(void)stopAutoForwardWatcher;

+(void)startAutoForwardWatcherTimer:(NSTimeInterval)timeout;

+(void)stopAutoForwardWatcherTimer;

+(void)checkIsExpressAvailable;

+(void)autoForwardTransactions;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTP_AutoForwardWatcher_h */
