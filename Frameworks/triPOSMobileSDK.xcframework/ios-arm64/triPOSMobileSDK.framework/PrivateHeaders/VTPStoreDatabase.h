///
/// \file VTPStoreDatabase.h
///

#ifndef VTPStoreDatabase_h
#define VTPStoreDatabase_h

#import "VTPStoreTransactionData.h"

@protocol VTPStoreDatabase

@required

-(BOOL)openWithName:(NSString *)name error:(NSError **)error;

-(BOOL)close:(NSError **)error;

-(BOOL)storeTransaction:(VTPStoreTransactionData *)transactionData error:(NSError **)error;

-(BOOL)updateTransaction:(VTPStoreTransactionData *)transactionData error:(NSError **)error;

-(BOOL)deleteTransaction:(NSString *)tpId error:(NSError **)error;

-(VTPStoreTransactionData *)getTransaction:(NSString *)tpId error:(NSError **)error;

-(NSArray<VTPStoreTransactionData *> *)getTransactions:(NSError **)error;

-(NSArray<VTPStoreTransactionData *> *)getTransactionsWithState:(VTPStoreTransactionState)state error:(NSError **)error;

@end

#endif /* VTPStoreDatabase_h */
