///
/// \file VTP+StoreAndForward.h
///

#ifndef VTP_StoreAndForward_h
#define VTP_StoreAndForward_h

#import "VTP.h"
#import "VTPStoreTransactionData.h"
#import "VTPStoreTransactionJsonData.h"
#import "VTPFinancialFlowData.h"

extern NSString * const storeDatabaseName;

@interface VTP(StoreAndForward)

-(BOOL)initializeStoreAndForward:(NSError **)error;

-(BOOL)isTransactionAllowedToBeStored:(NSObject<VTPFlowData> *)flowData;

-(BOOL)isTransactionAllowedToBeStoredManually:(NSObject<VTPFlowData> *)flowData;

-(BOOL)storeTransaction:(VTPStoreTransactionData *)storeTransactionData error:(NSError **)error;

-(VTPStoreTransactionData *)getTransaction:(NSString *)tpId error:(NSError **)error;

-(BOOL)updateTransaction:(VTPStoreTransactionData *)storeTransactionData error:(NSError **)error;

-(BOOL)deleteTransaction:(NSString *)tpId error:(NSError **)error;

-(BOOL)isStoredTransactionHealthcare:(NSObject<VTPFlowData> *)flowData AndFinancialFlowData:(NSObject<VTPFinancialFlowData> *) financialFlowData;

@end

#endif /* VTPStoreAndForward_h */
