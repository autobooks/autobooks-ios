///
/// \file VXPRequestType.h
///

#ifndef VXPRequestType_h
#define VXPRequestType_h

///
/// \enum VXPRequestType
/// Types of Express messages
///
typedef enum _VXPRequestType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    /// Unknown type
    VXPRequestTypeUnknown       = -1,
    
    /// First valid type value
    _VXPRequestTypeMin          = 0,
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
    
    /// AccountTokenActivate request
    VXPRequestTypeAccountTokenActivate = _VXPRequestTypeMin,
    /// AccountTokenCreate request
    VXPRequestTypeAccountTokenCreate,
    /// BatchClose request
    VXPRequestTypeBatchClose,
    /// BatchItemQuery request
    VXPRequestTypeBatchItemQuery,
    /// BatchTotalsQuery request
    VXPRequestTypeBatchTotalsQuery,
    /// CreditCardAVSOnly request
    VXPRequestTypeCreditCardAvsOnly,
    /// CreditCardAdjustment request
    VXPRequestTypeCreditCardAdjustment,
    /// CreditCardAuthorization request
    VXPRequestTypeCreditCardAuthorization,
    /// CreditCardIncrementalAuthorization request
    VXPRequestTypeCreditCardIncrementalAuthorization,
    /// CreditCardAuthorizationCompletion request
    VXPRequestTypeCreditCardAuthorizationCompletion,
    /// CreditCardCredit request
    VXPRequestTypeCreditCardCredit,
    /// CreditCardForce request
    VXPRequestTypeCreditCardForce,
    /// CreditCardReturn request
    VXPRequestTypeCreditCardReturn,
    /// CreditCardReversal request
    VXPRequestTypeCreditCardReversal,
    /// CreditCardSale request
    VXPRequestTypeCreditCardSale,
    /// CreditCardVoid request
    VXPRequestTypeCreditCardVoid,
    /// DebitCardReturn request
    VXPRequestTypeDebitCardReturn,
    /// DebitCardReversal request
    VXPRequestTypeDebitCardReversal,
    /// DebitCardSale request
    VXPRequestTypeDebitCardSale,
    /// CheckSale request
    VXPRequestTypeCheckSale,
    /// CheckCredit request
    VXPRequestTypeCheckCredit,
    /// CheckVerification request
    VXPRequestTypeCheckVerification,
    /// CheckReturn request
    VXPRequestTypeCheckReturn,
    /// CheckVoid request
    VXPRequestTypeCheckVoid,
    /// CheckReversal request
    VXPRequestTypeCheckReversal,
    /// HealthCheck request
    VXPRequestTypeHealthCheck,
    /// TimeCheck request
    VXPRequestTypeTimeCheck,
    /// TransactionSetup request
    VXPRequestTypeTransactionSetup,
    /// BINQuery request
    VXPRequestTypeBinQuery,
    /// CreditCardBalanceInquiry request
    VXPRequestTypeCreditCardBalanceInquiry,
    /// TransactionSetupExpire request
    VXPRequestTypeTransactionSetupExpire,
    /// TransactionQuery request
    VXPRequestTypeTransactionQuery,
    /// PaymentAccountCreate request
    VXPRequestTypePaymentAccountCreate,
    /// PaymentAccountUpdate request
    VXPRequestTypePaymentAccountUpdate,
    /// PaymentAccountDelete request
    VXPRequestTypePaymentAccountDelete,
    /// PaymentAccountQuery request
    VXPRequestTypePaymentAccountQuery,
    /// PaymentAccountAutoUpdate request
    VXPRequestTypePaymentAccountAutoUpdate,
    /// PaymentAccountCreateWithTransID request
    VXPRequestTypePaymentAccountCreateWithTransId,
    /// PaymentAccountQueryRecordCount request
    VXPRequestTypePaymentAccountQueryRecordCount,
    /// PaymentAccountQueryTokenReport request
    VXPRequestTypePaymentAccountQueryTokenReport,
    /// EnhancedBINQuery request
    VXPRequestTypeEnhancedBinQuery,
    /// TokenCreate request
    VXPRequestTypeTokenCreate,
    /// TokenCreateWithTransID request
    VXPRequestTypeTokenCreateWithTransId,
    /// GiftCardSale request
    VXPRequestTypeGiftCardSale,
    /// GiftCardCredit request
    VXPRequestTypeGiftCardCredit,
    /// GiftCardReversal request
    VXPRequestTypeGiftCardReversal,
    /// GiftCardActivate request
    VXPRequestTypeGiftCardActivate,
    /// GiftCardBalanceInquiry request
    VXPRequestTypeGiftCardBalanceInquiry,
    /// GiftCardBalanceTransfer request
       VXPRequestTypeGiftCardBalanceTransfer,
    /// GiftCardClose request
    VXPRequestTypeGiftCardClose,
    /// GiftCardReturn request
    VXPRequestTypeGiftCardReturn,
    /// GiftCardReload request
    VXPRequestTypeGiftCardReload,
    /// GiftCardUnload request
    VXPRequestTypeGiftCardUnload,
    /// EBT sale
    VXPRequestTypeEbtSale,
    /// EBT credit
    VXPRequestTypeEbtCredit,
    /// EBT voucher
    VXPRequestTypeEbtVoucher,
    /// EBT balance inquiry
    VXPRequestTypeEbtBalanceInquiry,
    /// EBT reversal
    VXPRequestTypeEbtReversal,
    /// Payment card reader token
    VXPRequestTypePaymentCardReaderToken,

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    /// Last valid type value
    _VXPRequestTypeMax,
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
}   VXPRequestType;

#endif /* VXPRequestType_h */
