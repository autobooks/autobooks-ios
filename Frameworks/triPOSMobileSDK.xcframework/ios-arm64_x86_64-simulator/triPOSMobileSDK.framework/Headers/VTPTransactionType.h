///
/// \file VTPTransactionType.h
///

#ifndef VTPTransactionType_h
#define VTPTransactionType_h

///
/// \enum VTPTransactionType
///
typedef enum _VTPTransactionType
{
    /// Unknown
    VTPTransactionTypeUnknown,
    /// Sale
    VTPTransactionTypeSale,
    /// Refund
    VTPTransactionTypeRefund,
    /// Authorization only
    VTPTransactionTypeAuthorizationOnly,
    /// Force
    VTPTransactionTypeForce,
    /// Full reversal
    VTPTransactionTypeFullReversal,
    /// Gift card activate
    VTPTransactionTypeGiftCardActivate,
    /// Gift card balance inquiry
    VTPTransactionTypeGiftCardBalanceInquiry,
    /// Gift card balance transfer
    VTPTransactionTypeGiftCardBalanceTransfer,
    /// Gift card Close
    VTPTransactionTypeGiftCardClose,
    /// Gift card reload
    VTPTransactionTypeGiftCardReload,
    /// Gift card unload
    VTPTransactionTypeGiftCardUnload,
    // EBT Voucher
    VTPTransactionTypeEbtVoucher,
    /// EBT card balance inquiry
    VTPTransactionTypeEbtCardBalanceInquiry
}   VTPTransactionType;

#endif /* VTPTransactionType_h */
