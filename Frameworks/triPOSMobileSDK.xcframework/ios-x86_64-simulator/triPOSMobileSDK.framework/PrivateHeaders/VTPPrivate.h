///
/// \file VTPPrivate.h
///

#ifndef VTPPrivate_h
#define VTPPrivate_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTP.h"
#import "VTPConfiguration.h"
#import "VTPFlow.h"
#import "VTPStatus.h"
#import "VTPStoreDatabase.h"
#import "VTPCardPrereadFlowData.h"

#import "VTPSaleFlowData.h"
#import "VTPRefundFlowData.h"
#import "VTPAuthorizationFlowData.h"
#import "VTPForwardTransactionFlowData.h"
#import "VTPGiftCardActivateFlowData.h"
#import "VTPEBTCardBalanceInquiryFlowData.h"
#import "VTPGiftCardReloadFlowData.h"
#import "VTPGiftCardUnloadFlowData.h"
#import "VTPVoucherFlowData.h"
#import "VTPGiftCardBalanceInquiryFlowData.h"
#import "VTPGiftCardUnloadFlowData.h"
#import "VTPGiftCardCloseFlowData.h"
#import "VTPGiftCardBalanceTransferFlowData.h"

@interface VTP()

@property (retain, nonatomic) NSObject<VTPFlow> *runningFlow;

@property (retain, nonatomic) NSObject<VTPStoreDatabase> *storeDatabase;

@property (retain, nonatomic) VTPCardPrereadFlowData *cardFlowData;

@property (nonatomic, strong) NSTimer * prereadDataTimer;

@property (atomic, assign) BOOL isTransactionInProgress;

@property (atomic, assign) BOOL isPrereadInProgress;

-(void)sendStatusChange:(VTPStatus)status;

-(void)sendSelectionWith:(NSArray *) choices for:(VTPSelectionType) selectionType completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

-(void)sendAmountConfirmation:(NSDecimalNumber *) amount withPrompt:(NSString*) prompt andCompletionHandler:(VPDYesNoInputCompletionHandler)completionHandler;

-(void)sendNumericInput:(VTPNumericInputType) numericInputType completionHandler:(VPDKeyboardNumericInputCompletionHandler) completionHandler;

-(void)sendDisplayText:(NSString *) text;

-(void)sendSelectionApplication:(NSArray *) applications completionHandler:(VPDChoiceInputCompletionHandler)completionHandler;

-(void)sendRemoveCard;

-(void)sendBatteryLow;

-(void)setSaleFlowData:(VTPSaleFlowData *)value;

-(void)setRefundFlowData:(VTPRefundFlowData *)value;

-(void)setAuthorizationFlowData:(VTPAuthorizationFlowData *)value;

-(void)setManuallyForwardFlowData:(VTPForwardTransactionFlowData *)value;

-(void)setGiftCardActivateFlowData:(VTPGiftCardActivateFlowData *)value;

-(void)setGiftCardBalanceInquiryFlowData:(VTPGiftCardBalanceInquiryFlowData *)value;

-(void)setEBTCardBalanceInquiryFlowData:(VTPEBTCardBalanceInquiryFlowData *)value;

-(void)setGiftCardCloseFlowData:(VTPGiftCardCloseFlowData *)value;

-(void)setGiftCardReloadFlowData:(VTPGiftCardReloadFlowData *)value;

-(void)setGiftCardUnloadFlowData:(VTPGiftCardUnloadFlowData *)value;

-(void)setEBTVoucherFlowData:(VTPVoucherFlowData *)value;

-(void)setGiftCardBalanceTransferFlowData: (VTPGiftCardBalanceTransferFlowData *)value;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPPrivate_h */
