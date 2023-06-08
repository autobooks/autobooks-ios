///
/// \file VXPResponseCode.h
///

#ifndef VXPResponseCode_h
#define VXPResponseCode_h

///
/// \enum VXPResponseCode
///
typedef enum _VXPResponseCode
{
    /// This field is not used
    VXPResponseCodeNotSet = VXPEnumNotSet,
    /// Approved
    VXPResponseCodeApproved = 0,
    /// Partially approved
    VXPResponseCodePartialApproval = 5,
    /// Purchase amount approved, cashback amount declined
    VXPResponseCodeApprovedExceptCashback = 6,
    /// Declined
    VXPResponseCodeDecline = 20,
    /// Expired card
    VXPResponseCodeExpiredCard = 21,
    /// Duplicate approved
    VXPResponseCodeDuplicateApproved = 22,
    /// Duplicate
    VXPResponseCodeDuplicate = 23,
    /// Pick up card
    VXPResponseCodePickUpCard = 24,
    /// Referral, call issuer
    VXPResponseCodeReferralCallIssuer = 25,
    /// Balance is not available
    VXPResponseCodeBalanceNotAvailable = 30,
    /// Not defined
    VXPResponseCodeNotDefined = 90,
    /// Invalid data
    VXPResponseCodeInvalidData = 101,
    /// Invalid account
    VXPResponseCodeInvalidAccount = 102,
    /// Invalid request
    VXPResponseCodeInvalidRequest = 103,
    /// Authorization failed
    VXPResponseCodeAuthorizationFailed = 104,
    /// Not allowed
    VXPResponseCodeNotAllowed = 105,
    /// Out of balance
    VXPResponseCodeOutOfBalance = 120,
    /// Communication error
    VXPResponseCodeCommunicationError = 1001,
    /// Host error
    VXPResponseCodeHostError = 1002,
    /// Error
    VXPResponseCodeError = 1009,
    
    /// Hosted Payments cancelled
    VXPResponseCodeHostedPaymentsCancelled = 10000,
    /// Online approval, GENAC2 decline, reversal failed
    VXPResponseCodeGenac2DeclineReversalFailed
}   VXPResponseCode;

#endif /* VXPResponseCode_h */
