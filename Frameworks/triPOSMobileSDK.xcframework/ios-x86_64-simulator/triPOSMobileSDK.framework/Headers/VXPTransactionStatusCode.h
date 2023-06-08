///
/// \file VXPTransactionStatusCode.h
///

#ifndef VXPTransactionStatusCode_h
#define VXPTransactionStatusCode_h

///
/// \enum VXPTransactionStatusCode
///
typedef enum _VXPTransactionStatusCode
{
    /// This field is not used
    VXPTransactionStatusCodeNotSet = VXPEnumNotSet,
    /// In process
    VXPTransactionStatusCodeInProcess = 0,
    /// Approved
    VXPTransactionStatusCodeApproved,
    /// Declined
    VXPTransactionStatusCodeDeclined,
    /// Duplicate
    VXPTransactionStatusCodeDuplicate,
    /// Voided
    VXPTransactionStatusCodeVoided,
    /// Authorized
    VXPTransactionStatusCodeAuthorized,
    /// Authorization complete
    VXPTransactionStatusCodeAuthComplete,
    /// Reversed
    VXPTransactionStatusCodeReversed,
    /// Success
    VXPTransactionStatusCodeSuccess,
    /// Returned
    VXPTransactionStatusCodeReturned,
    /// Pending
    VXPTransactionStatusCodePending,
    /// Queued
    VXPTransactionStatusCodeQueued,
    /// Unknown
    VXPTransactionStatusCodeUnknown,
    /// Error
    VXPTransactionStatusCodeError,
    /// Originated
    VXPTransactionStatusCodeOriginated,
    /// Settled
    VXPTransactionStatusCodeSettled,
    /// Partially approved
    VXPTransactionStatusCodePartialApproved,
    /// Rejected
    VXPTransactionStatusCodeRejected,
}   VXPTransactionStatusCode;

#endif /* VXPTransactionStatusCode_h */
