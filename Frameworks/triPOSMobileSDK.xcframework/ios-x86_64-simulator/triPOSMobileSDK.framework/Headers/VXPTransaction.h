///
/// \file VXPTransaction.h
///

#ifndef VXPTransaction_h
#define VXPTransaction_h

#import "VXPBase.h"
#import "VXPMarketCode.h"
#import "VXPReversalType.h"
#import "VXPGiftProgramType.h"
#import "VXPTransactionStatusCode.h"
    
///
/// \class VXPTransaction
///
/// \brief Transaction class
///
/// The transaction class specifies information about the transaction.
///
@interface VXPTransaction : VXPBase

///
/// \brief Gets or sets the transaction ID
///
/// This property gets or sets the unique transaction identifier.
///
@property (retain, nonatomic) NSString *TransactionID;

///
/// \brief Gets or sets the merchant supplied transaction ID
///
/// This property gets or sets the merchant supplied transaction ID from the host/processor.
///
@property (retain, nonatomic) NSString *MerchantSuppliedTransactionID;


///
/// \brief Gets or sets the clerk number
///
/// The property gets or sets the dentifier for the clerk performing the transaction.
///
@property (retain, nonatomic) NSString *ClerkNumber;

///
/// \brief Gets or sets the shift ID
///
/// This property gets or sets the identifier for the shift during which the transaction in performed.
///
@property (retain, nonatomic) NSString *ShiftID;

///
/// \brief Gets or sets the transaction amount
///
/// This property gets or sets the dollar amount of the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *TransactionAmount;

///
/// \brief Gets or sets the original authorized amount
///
/// This property gets or sets the original dollar amount authorized.
///
@property (retain, nonatomic) NSDecimalNumber *OriginalAuthorizedAmount;

///
/// \brief Gets or sets the total authorized amount
///
/// This property gets or sets the total dollar amount authorized.
///
@property (retain, nonatomic) NSDecimalNumber *TotalAuthorizedAmount;

///
/// \brief Gets or sets the sales tax amount
///
/// This property gets or sets the sales tax dollar amount.
///
@property (retain, nonatomic) NSDecimalNumber *SalesTaxAmount;

///
/// \brief Gets or sets the tip amount
///
/// This property gets or sets the tip dollar amount.
///
@property (retain, nonatomic) NSDecimalNumber *TipAmount;

///
/// \brief Gets or sets the convenience fee amount
///
/// This propety gets or sets the convenience fee dollar amount (Worldpay only).
///
@property (retain, nonatomic) NSDecimalNumber *ConvenienceFeeAmount;

///
/// \brief Gets or sets the surcharge fee amount
///
/// This propety gets or sets the surcharge fee dollar amount.
///
@property (retain, nonatomic) NSDecimalNumber *SurchargeAmount;

///
/// \brief Gets or sets the approval approval number
///
/// This property gets or sets the issuer assigned approval number.
///
@property (retain, nonatomic) NSString *ApprovalNumber;

///
/// \brief Gets or sets the reference number
///
/// This property gets or sets the user assigned reference number.
///
@property (retain, nonatomic) NSString *ReferenceNumber;

///
/// \brief Gets or sets the ticket number
///
/// This property gets or sets the ticket number. Used for direct marketing, mail/telephone order, and e-commerce transactions. Required when the card number is manually keyed.
///
@property (retain, nonatomic) NSString *TicketNumber;

///
/// \brief Gets or sets the reversal type
///
/// This property gets or sets the type of reversal.
///
@property (nonatomic) VXPReversalType ReversalType;

///
/// \brief Gets or sets the market code
///
/// This property gets or sets the industy of the merchant. Set this value to VXPMarketCodeDefault to use the market code from the merchant profile.
///
@property (nonatomic) VXPMarketCode MarketCode;

///
/// \brief Gets or sets the acquirer data
///
/// This property gets or sets the data returned by the acquirer.
///
@property (retain, nonatomic) NSString *AcquirerData;

///
/// \brief Gets or sets the cashback dollar amount
///
/// This property gets or sets the cashback dollar amount.
///
@property (retain, nonatomic) NSDecimalNumber *CashBackAmount;

///
/// \brief Gets or sets the bill payment flag
///
/// This property gets or sets whether this is a bill payment transaction or not.
///
@property (nonatomic) VXPBooleanType BillPaymentFlag;

///
/// \brief Gets or sets the duplicate check disable flag
///
/// This property gets or sets duplicate checking for this transaction.
///
@property (nonatomic) VXPBooleanType DuplicateCheckDisableFlag;

///
/// \brief Gets or sets the duplicate override flag
///
/// This property gets or sets overriding duplicate transaction checking at the host for transactions that were previously returned as being a duplicate.
///
@property (nonatomic) VXPBooleanType DuplicateOverrideFlag;

///
/// \brief Gets or sets the recurring flag
///
/// This property gets or sets if this is part of a recurring series of transactions.
///
@property (nonatomic) VXPBooleanType RecurringFlag;

///
/// \brief Gets or sets the commercial card customer code
///
/// This property gets or sets the commercial card customer code.
///
@property (retain, nonatomic) NSString *CommercialCardCustomerCode;

///
/// \brief Gets or sets the processor name
///
/// This property gets or sets the name of the processor that processed the transaction.
///
@property (retain, nonatomic) NSString *ProcessorName;

///
/// \brief Gets or sets the transaction status
///
/// This property gets or sets the description of the status/state of the transaction.
///
@property (retain, nonatomic) NSString *TransactionStatus;

///
/// \brief Gets or sets the transaction status code
///
/// This property gets or sets the status/state of the transaction.
///
@property (nonatomic) VXPTransactionStatusCode TransactionStatusCode;

///
/// \brief Gets or sets the host transaction ID
///
/// This property gets or sets teh transaction ID from the host/processor.
///
@property (retain, nonatomic) NSString *HostTransactionID;

///
/// \brief Gets or sets the transaction setup ID
///
/// This property gets or sets the unique GUID generated by Express that identifies the tranaction setup ID.
///
@property (retain, nonatomic) NSString *TransactionSetupID;

///
/// \brief Gets or sets the merchant verification value
///
/// This property gets or sets the merchant verification value.
///
@property (retain, nonatomic) NSString *MerchantVerificationValue;

///
/// \brief Gets or sets teh partial approved flag
///
/// This property gets or sets whether the software supports partial approvals.
///
@property (nonatomic) VXPBooleanType PartialApprovedFlag;

///
/// \brief Gets or sets the approved amount
///
/// This property gets or sets the approved dollar amount.
///
@property (retain, nonatomic) NSDecimalNumber *ApprovedAmount;

///
/// \brief Gets or sets the commercial card response code
///
/// This property gets or sets the commercial card response code.
///
@property (retain, nonatomic) NSString *CommercialCardResponseCode;

///
/// \brief Gets or sets the balance amount
///
/// This property gets or sets the balance dollar amount. This amount may be negative.
///
@property (retain, nonatomic) NSDecimalNumber *BalanceAmount;

///
/// \brief Gets or sets teh balance currency code
///
/// This property gets or sets the currency code for the balance amount.
///
@property (retain, nonatomic) NSString *BalanceCurrencyCode;

///
/// \brief Gets or sets the currency code
///
/// This property gets or sets the currency code for the transaction amounts.
///
@property (retain, nonatomic) NSString *CurrencyCode;

///
/// \brief Gets or sets the network label
///
/// This property gets or sets the network label.
///
@property (retain, nonatomic) NSString *NetworkLabel;

///
/// \brief Gets or sets the deferred auth indicator
///
/// This property gets or sets whether the transaction is a stored transaction being forwarded for authentication.
///
@property (nonatomic) VXPBooleanType DeferredAuthIndicator;

///
/// \brief Gets or sets the gift program type
///
/// This property gets or sets the type of gift program. Default value is 0 - Gift
///
@property (nonatomic) VXPGiftProgramType GiftProgramType;

///
/// \brief Gets or sets the gift points balance
///
/// This property gets or sets the gift points balance.
///
@property (nonatomic) NSString *GiftPointsBalance;

///
/// \brief Gets or sets the gift rewards level
///
/// This property gets or sets the gift rewards level.
///
@property (nonatomic) NSString *GiftRewardLevel;

///
/// \brief Gets or sets the PINless POS conversion indicator.
///
/// This property gets or sets the PINless POS conversion indicator
///
@property (retain, nonatomic) NSString *PINlessPOSConversionIndicator;

///
/// \brief Gets or sets the foreign transaction amount.
///
/// This property gets or sets the foreign transaction amount
///
@property (retain, nonatomic) NSString *ForeignTransactionAmount;

///
/// \brief Gets or sets the foreign currency code.
///
/// This property gets or sets the foreign currency code
///
@property (retain, nonatomic) NSString *ForeignCurrencyCode;

///
/// \brief Gets or sets the conversion rate.
///
/// This property gets or sets the conversion rate
///
@property (retain, nonatomic) NSString *ConversionRate;

///
/// \brief Gets or sets the dcc requested confirmation.
///
/// This property gets or sets the dcc requested confirmation
///
@property (assign) NSNumber *DCCRequested;

@end

#endif /* VXPTransaction_h */
