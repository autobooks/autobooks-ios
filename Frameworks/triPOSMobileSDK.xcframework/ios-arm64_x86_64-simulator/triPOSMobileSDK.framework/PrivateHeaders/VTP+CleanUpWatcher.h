///
/// \file VTP+CleanUpWatcher.h
///

#ifndef VTP_CleanUpWatcher_h
#define VTP_CleanUpWatcher_h

#import "VTP.h"
#import "triPOSMobileSDK.h"
#import "VTP+StoreAndForward.h"

@interface VTP(CleanUpWatcher)

+(void)startCleanUpWatcher;

+(void)startCleanUpWatcherIfNotAlreadyStarted;

+(void)startCleanUpWatcherWithInterval:(NSTimeInterval)interval;

+(void)stopCleanUpWatcher;

+(void)cleanUpDatabase;

+(void)checkStoredTransactionsWithState:(VTPStoreTransactionState)state vtp:(VTP *)vtp;

+(void)cleanUpTransactions:(NSArray<VTPStoreTransactionData *> *)transactions vtp:(VTP *)vtp;

@end

#endif /* VTP_CleanUpWatcher_h */
