///
/// \file VTPStatus.h
///

#ifndef VTPStatus_h
#define VTPStatus_h

///
/// \enum VTPStatus
///
/// The current status of the SDK.
///
typedef enum _VTPStatus
{
    /// None, SDK is idle
    VTPStatusNone,
    /// SDK is initializing
    VTPStatusInitializing,
    /// SDK is deinitializing
    VTPStatusDeinitializing,
    
    /// SDK is running a sale
    VTPStatusRunningSale,
    /// SDK is running a refund
    VTPStatusRunningRefund,
    /// SDK is running an authorization
    VTPStatusRunningAuthorization,
    /// SDK is running an gift card activate
    VTPStatusRunningGiftCardActivate,
    /// SDK is running an gift card balance inquiry
    VTPStatusRunningGiftCardBalanceInquiry,
    /// SDK is running a gift card balance transfer
    VTPStatusRunningGiftCardBalanceTransfer,
    /// SDK is running an gift card close
    VTPStatusRunningGiftCardClose,
    /// SDK is running an gift card reload
    VTPStatusRunningGiftCardReload,
    /// SDK is running an gift card unload
    VTPStatusRunningGiftCardUnload,
    /// SDK is running an EBT voucher request
    VTPStatusRunningEbtVoucherRequest,
    /// SDK is running an EBT card balance inquiry
    VTPStatusRunningEbtCardBalanceInquiry,
    
    /// Card input is being requested
    VTPStatusGettingCardInput,
    /// Card input is being processed
    VTPStatusProcessingCardInput,
    /// Payment type is being requested
    VTPStatusGettingPaymentType,
    /// Convenience fee amount confirmation is being requested
    VTPStatusGettingConvenienceFeeAmountConfirmation,
    /// Want tip is being requested
    VTPStatusGettingWantTip,
    /// Tip selection is being requested
    VTPStatusGettingTipSelection,
    /// Tip entry is being requested
    VTPStatusGettingTipEntry,
    /// Want cashback is being requested
    VTPStatusGettingWantCashback,
    /// Cashback selection is being requested
    VTPStatusGettingCashbackSelection,
    /// Cashback entry is being requested
    VTPStatusGettingCashbackEntry,
    /// Postal code is being requested
    VTPStatusGettingPostalCode,
    /// Total amount confirmation is being requested
    VTPStatusGettingTotalAmountConfirmation,
    /// PIN is being requested
    VTPStatusGettingPin,
    /// Continuing EMV transaction
    VTPStatusGettingContinuingEmvTransaction,
    /// Sending to host
    VTPStatusSendingToHost,
    /// Finalizing EMV transaction
    VTPStatusGettingFinalizingEmvTransaction,
    /// Finalizing flow
    VTPStatusFinalizing,
}   VTPStatus;

#endif /* VTPStatus_h */
