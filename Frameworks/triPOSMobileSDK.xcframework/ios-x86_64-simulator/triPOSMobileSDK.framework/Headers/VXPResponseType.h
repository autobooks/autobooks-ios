///
/// \file VXPResponseType.h
///

#ifndef VXPResponseType_h
#define VXPResponseType_h

///
/// \enum VXPResponseType
/// Types of Express messages
///
typedef enum _VXPResponseType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    /// Unknown type
    VXPResponseTypeUnknown       = -1,
    
    /// First valid type value
    _VXPResponseTypeMin          = 0,
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
    
    /// Generic response
    VXPResponseTypeGeneric = _VXPResponseTypeMin,
    /// AccountTokenActivate response
    VXPResponseTypeAccountTokenActivate,
    /// AccountTokenCreate response
    VXPResponseTypeAccountTokenCreate,
    /// BatchClose response
    VXPResponseTypeBatchClose,
    /// BatchItemQuery response
    VXPResponseTypeBatchItemQuery,
    /// BatchTotalsQuery response
    VXPResponseTypeBatchTotalsQuery,
    /// CreditCardAVSOnly response
    VXPResponseTypeCreditCardAvsOnly,
    /// CreditCardAdjustment response
    VXPResponseTypeCreditCardAdjustment,
    /// CreditCardAuthorization response
    VXPResponseTypeCreditCardAuthorization,
    /// CreditCardIncrementalAuthorization response
    VXPResponseTypeCreditCardIncrementalAuthorization,
    /// CreditCardAuthorizationCompletion response
    VXPResponseTypeCreditCardAuthorizationCompletion,
    /// CreditCardCredit response
    VXPResponseTypeCreditCardCredit,
    /// CreditCardForce response
    VXPResponseTypeCreditCardForce,
    /// CreditCardReturn response
    VXPResponseTypeCreditCardReturn,
    /// CreditCardReversal response
    VXPResponseTypeCreditCardReversal,
    /// CreditCardSale response
    VXPResponseTypeCreditCardSale,
    /// CreditCardVoid response
    VXPResponseTypeCreditCardVoid,
    /// DebitCardReturn response
    VXPResponseTypeDebitCardReturn,
    /// DebitCardReversal response
    VXPResponseTypeDebitCardReversal,
    /// DebitCardSale response
    VXPResponseTypeDebitCardSale,
    /// CheckSale response
    VXPResponseTypeCheckSale,
    /// CheckCredit response
    VXPResponseTypeCheckCredit,
    /// CheckVerification response
    VXPResponseTypeCheckVerification,
    /// CheckReturn response
    VXPResponseTypeCheckReturn,
    /// CheckVoid response
    VXPResponseTypeCheckVoid,
    /// CheckReversal response
    VXPResponseTypeCheckReversal,
    /// HealthCheck response
    VXPResponseTypeHealthCheck,
    /// TimeCheck response
    VXPResponseTypeTimeCheck,
    /// TransactionSetup response
    VXPResponseTypeTransactionSetup,
    /// BINQuery response
    VXPResponseTypeBinQuery,
    /// CreditCardBalanceInquiry response
    VXPResponseTypeCreditCardBalanceInquiry,
    /// TransactionSetupExpire response
    VXPResponseTypeTransactionSetupExpire,
    /// TransactionQuery response
    VXPResponseTypeTransactionQuery,
    /// PaymentAccountCreate response
    VXPResponseTypePaymentAccountCreate,
    /// PaymentAccountUpdate response
    VXPResponseTypePaymentAccountUpdate,
    /// PaymentAccountDelete response
    VXPResponseTypePaymentAccountDelete,
    /// PaymentAccountQuery response
    VXPResponseTypePaymentAccountQuery,
    /// PaymentAccountAutoUpdate response
    VXPResponseTypePaymentAccountAutoUpdate,
    /// PaymentAccountCreateWithTransID response
    VXPResponseTypePaymentAccountCreateWithTransId,
    /// PaymentAccountQueryRecordCount response
    VXPResponseTypePaymentAccountQueryRecordCount,
    /// PaymentAccountQueryTokenReport response
    VXPResponseTypePaymentAccountQueryTokenReport,
    /// EnhancedBINQuery response
    VXPResponseTypeEnhancedBinQuery,
    /// TokenCreate response
    VXPResponseTypeTokenCreate,
    /// TokenCreateWithTransID response
    VXPResponseTypeTokenCreateWithTransId,
    /// GiftCardSale response
    VXPResponseTypeGiftCardSale,
    /// GiftCardCredit response
    VXPResponseTypeGiftCardCredit,
    /// GiftCardReversal response
    VXPResponseTypeGiftCardReversal,
    /// GiftCardActivate response
    VXPResponseTypeGiftCardActivate,
    /// GiftCardBalanceInquiry response
    VXPResponseTypeGiftCardBalanceInquiry,
    /// GiftCardBalanceTransfer response
    VXPResponseTypeGiftCardBalanceTransfer,
    /// GiftCardClose response
    VXPResponseTypeGiftCardClose,
    /// GiftCardReturn response
    VXPResponseTypeGiftCardReturn,
    /// GiftCardReload response
    VXPResponseTypeGiftCardReload,
    /// GiftCardUnload response
    VXPResponseTypeGiftCardUnload,
    /// EBT sale
    VXPResponseTypeEbtSale,
    /// EBT credit
    VXPResponseTypeEbtCredit,
    /// EBT voucher
    VXPResponseTypeEbtVoucher,
    /// EBT balance inquiry
    VXPResponseTypeEbtBalanceInquiry,
    /// EBT reversal
    VXPResponseTypeEbtReversal,
    /// Payment card reader token
    VXPResponseTypePaymentCardReaderToken,

    /// Hosted Payments response
    VXPResponseTypeHostedPayments = 10000,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    /// Last valid type value
    _VXPResponseTypeMax,
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
}   VXPResponseType;

#endif /* VXPResponseType_h */
