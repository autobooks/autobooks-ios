///
///  \file VTPStoreTransactionRecord.h
///

#ifndef VTPStoreTransactionRecord_h
#define VTPStoreTransactionRecord_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPStoreTransactionState.h"
#import "VTPTransactionType.h"

@interface VTPStoreTransactionRecord : NSObject

@property (retain, nonatomic) NSString *tpId;

@property (nonatomic) VTPStoreTransactionState state;

@property (retain, nonatomic) NSString *transactionId;

@property (retain, nonatomic) NSString *totalAmount;

@property (nonatomic) VTPTransactionType transactionType;

@property (nonatomic) NSObject *response;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPStoreTransactionRecord_h */
