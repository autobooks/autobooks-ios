////
//// \file VTPStoreTransactionJsonData.h
///

#ifndef VTPStoreTransactionJsonData_h
#define VTPStoreTransactionJsonData_h

#import "VTPStoreTransactionState.h"
#import "VTPPaymentType.h"
#import "VTPTransactionStatus.h"
#import "VTPTransactionType.h"
#import "VTPCardData.h"
#import "VTPCardEntryMode.h"
#import "VTPCardHolderPresentCode.h"
#import "VTPCurrencyCode.h"
#import "VTPMarketCode.h"
#import "VTPTerminalType.h"
#import "VTPApplicationMode.h"
#import "VPDCardInputCapability.h"
#import "VTPFlowData.h"
#import "VXP.h"

@interface VTPStoreTransactionJsonData : NSObject

// VTPFinancialFlowData
@property (nonatomic) VTPPaymentType paymentType;

@property (nonatomic) NSString *cashbackAmount;

@property (nonatomic) NSString *tipAmount;

@property (retain, nonatomic) NSString *postalCode;

@property (retain, nonatomic) NSString *expressResponse;

// VTPCardFlowData
@property (retain, nonatomic) VTPCardData *cardData;

@property (nonatomic) VTPCardEntryMode cardEntryMode;

// VTPFinancialRequestBase
@property (nonatomic) VTPCardHolderPresentCode cardholderPresentCode;

@property (retain, nonatomic) NSString *clerkNumber;

@property (retain, nonatomic) NSString *laneNumber;

@property (retain, nonatomic) NSString *referenceNumber;

@property (retain, nonatomic) NSString *shiftID;

@property (retain, nonatomic) NSString *ticketNumber;

@property (retain, nonatomic) NSString *billingEmail;

// VTPFinancialRequestAmounts
@property (retain, nonatomic) NSString *salesTaxAmount;

@property (retain, nonatomic) NSString *transactionAmount;

// VTPFinancialRequestConvenienceFeeAmount
@property (retain, nonatomic) NSString *convenienceFeeAmount;

// VTPTransactionConfiguration
@property (nonatomic) VTPCurrencyCode currencyCode;

@property (nonatomic) VTPMarketCode marketCode;

@property (nonatomic) BOOL arePartialApprovalsAllowed;

@property (nonatomic) BOOL areDuplicateTransactionsAllowed;

// VTPDeviceConfiguration
@property (nonatomic) VTPTerminalType terminalType;

@property (retain, nonatomic) NSString *terminalId;

// VTPApplicationConfiguration
@property (nonatomic) VTPApplicationMode mode;

@property (nonatomic) VPDCardInputCapability cardInputCapability;

-(instancetype)initWithJsonString:(NSString *)jsonString;

-(instancetype)initWithFlowData:(NSObject<VTPFlowData> *)flowData;

+(VTPStoreTransactionJsonData *)storeTransactionJsonDataWithFlowData:(NSObject<VTPFlowData> *)flowData;

-(NSString *)toJsonString;

@end

#endif /* VTPStoreTransactionJsonData_h */
