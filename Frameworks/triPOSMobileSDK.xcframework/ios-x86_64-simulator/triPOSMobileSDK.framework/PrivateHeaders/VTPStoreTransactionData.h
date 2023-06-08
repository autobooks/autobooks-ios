////
//// \file VTPStoreTransactionData.h
///

#ifndef VTPStoreTransactionData_h
#define VTPStoreTransactionData_h

#import <Realm/Realm.h>

#import "VTPStoreTransactionState.h"
#import "VTPTransactionType.h"

@interface VTPStoreTransactionData : RLMObject

@property (retain, nonatomic) NSString *tpId;

@property (nonatomic) VTPStoreTransactionState state;

@property (retain, nonatomic) NSDate *createTime;

@property (retain, nonatomic) NSDate *updateTime;

@property (retain, nonatomic) NSString *transactionId;

@property (retain, nonatomic) NSString *totalAmount;

@property (nonatomic) VTPTransactionType transactionType;

@property (retain, nonatomic) NSString *jsonData;

-(instancetype)initWithTpId:(NSString *)tpId totalAmount:(NSDecimalNumber *)totalAmount transactionType:(VTPTransactionType)transactionType jsonData:(NSString *)jsonData;

+(VTPStoreTransactionData *)storeTransactionDataWithTpId:(NSString *)tpId totalAmount:(NSDecimalNumber *)totalAmount transactionType:(VTPTransactionType)transactionType jsonData:(NSString *)jsonData;

@end

RLM_ARRAY_TYPE(VTPStoreTransactionData)

#endif /* VTPStoreTransactionData_h */
