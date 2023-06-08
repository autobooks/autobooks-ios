///
/// \file VTPTransactionStatus.h
///

#ifndef VTPTransactionStatus_h
#define VTPTransactionStatus_h

///
/// \enum VTPTransactionStatus
///
typedef enum _VTPTransactionStatus
{
    /// Unknown
    VTPTransactionStatusUnknown,
    /// Approved
    VTPTransactionStatusApproved,
    /// Partially approved
    VTPTransactionStatusPartiallyApproved,
    /// Approved except cashback
    VTPTransactionStatusApprovedExceptCashback,
    /// Approved by merchant (store and forward)
    VTPTransactionStatusApprovedByMerchant,
    /// Call issuer
    VTPTransactionStatusCallIssuer,
    /// Declined
    VTPTransactionStatusDeclined,
    /// Needs to be reversed
    VTPTransactionStatusNeedsToBeReversed,
}   VTPTransactionStatus;

@interface VTPTransactionStatusUtility : NSObject

+(BOOL)isTransactionStatusApproved:(VTPTransactionStatus)transactionStatus;

@end

#endif /* VTPTransactionStatus_h */
