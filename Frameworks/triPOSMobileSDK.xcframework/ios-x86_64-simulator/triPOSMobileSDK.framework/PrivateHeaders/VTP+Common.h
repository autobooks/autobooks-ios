///
/// \file VTP+Common.h
///

#ifndef VTP_Common_h
#define VTP_Common_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTP.h"
#import "VTPFlowData.h"
#import "VTPFinancialFlowData.h"
#import "VTPCardFlowData.h"
#import "VTPStoreAndForwardFlowData.h"

@interface VTP(Common)

-(void)setFinancialResponse:(NSObject <VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData, VTPFinancialFlowData> *)flowData;

-(NSString *)getCardLogo:(VXPResponse *)expressResponse;

-(NSString *)getMaskedAccountNumber:(NSObject<VTPFlowData> *)flowData;

-(NSString *)getCardExpirationYear:(NSObject<VTPFlowData> *)flowData;

-(NSString *)getCardExpirationMonth:(NSObject<VTPFlowData> *)flowData;

-(NSString *)getReferenceNumber:(NSObject<VTPFlowData, VTPFinancialFlowData> *)flowData;

-(NSDate *)getTransactionDateAndTime:(VXPResponse *)expressResponse;

-(void)setResponseAmounts:(NSObject <VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData> *)flowData;

-(void)setStoreAndForwardApprovedAmount:(NSObject<VTPFinancialResponseAmounts> *)financialAmountsResponse financialFlowData:(NSObject<VTPFinancialFlowData> *)financialFlowData;

-(void)setResponseCard:(NSObject <VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData> *)flowData;

-(NSString *)getCardHolderName:(NSObject<VTPFlowData> *)flowData;

-(void)setResponseCardVerification:(NSObject<VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData> *)flowData;

-(void)setResponseEmv:(NSObject<VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData> *)flowData;

-(void)setResponseHost:(NSObject<VTPFinancialResponseBase> *)response expressResponse:(VXPResponse *)expressResponse;

-(void)setResponseStoreAndForward:(NSObject<VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData> *)flowData;

-(BOOL) canTransactionProceed:(VTPErrorHandler)errorHandler;

-(BOOL) canTransactionProceed:(VTPErrorHandler)errorHandler transactionIdentifier:(NSString *) transactionIdentifier;

-(BOOL) isPrereadCardDataPresentForIneligibleTransactionType:(VTPErrorHandler)errorHandler;

-(BOOL) isPrereadCardDataPresentForIneligibleTransactionType:(VTPErrorHandler)errorHandler transactionIdentifier:(NSString *) transactionIdentifier;

-(void) setValutecRewardsResponse:(NSObject <VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData, VTPFinancialFlowData> *)flowData;

-(void) setPinlessPosConversionIndicatorToResponse:(NSObject <VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData, VTPFinancialFlowData> *)flowData;

-(void) setResponseDcc:(NSObject <VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData, VTPFinancialFlowData> *)flowData;

-(void) setResponseSurcharge:(NSObject <VTPFinancialResponseBase> *)response flowData:(NSObject<VTPFlowData, VTPFinancialFlowData> *)flowData;

-(BOOL) isTipAmountValid:(VTPErrorHandler)errorHandler
               tipAmount:(NSDecimalNumber *)tipAmount;

-(BOOL) isConvenienceFeeAmountValid:(VTPErrorHandler)errorHandler
               convenienceFeeAmount:(NSDecimalNumber *)convenienceFeeAmount;

-(BOOL) isSurchargeFeeAmountValid:(VTPErrorHandler)errorHandler
               surchargeFeeAmount:(NSDecimalNumber *)surchargeFeeAmount;

-(BOOL) isHealthCareAmountValid:(VTPErrorHandler)errorHandler
                   visionAmount:(NSDecimalNumber *)visionAmount
             prescriptionAmount:(NSDecimalNumber *)prescriptionAmount
                   dentalAmount:(NSDecimalNumber *)dentalAmount
                   clinicAmount:(NSDecimalNumber *)clinicAmount
          totalHealthcareAmount:(NSDecimalNumber *)totalHealthcareAmount;

-(BOOL) isTransactionAmountGreaterThanFoodStampsAmount:(VTPErrorHandler)errorHandler
                                     transactionAmount:(NSDecimalNumber *) transactionAmount
                                      foodStampsAmount:(NSDecimalNumber *) foodStampsAmount;

+(NSString *)formatCurrencyCode: (NSString *) currencyCode;
+(NSString *)formatConversionRate: (NSString *) conversionRate;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTP_Common_h */
