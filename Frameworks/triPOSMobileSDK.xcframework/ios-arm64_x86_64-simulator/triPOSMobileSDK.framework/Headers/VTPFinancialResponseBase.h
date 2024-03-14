///
/// \file VTPFinancialResponseBase.h
///

#ifndef VTPFinancialResponseBase_h
#define VTPFinancialResponseBase_h

#import "VTPTransactionStatus.h"
#import "VTPPaymentType.h"
#import "VTPEbtType.h"

///
/// \protocol VTPFinancialResponseBase
///
/// \brief The protocol that defines the properties returned in all financial responses
///
@protocol VTPFinancialResponseBase

///
/// \brief Gets whether the transaction is approved or not.
///
/// This property gets whether the transaction is approved or not.
///
@property (nonatomic) VTPTransactionStatus transactionStatus;

///
/// \brief Gets whether the transaction was processed online or not
///
/// This property gets whether the transaction was processed online or not.
///
@property (nonatomic) BOOL wasProcessedOnline;

///
/// \brief Gets whether the PIN was verified
///
/// This property gets whether the PIN was verified. This includes both online and offline PIN.
///
@property (nonatomic) BOOL wasPinVerified;

///
/// \brief Gets whether a signature is required or not
///
/// This property gets whether a signature is required or not.
///
@property (nonatomic) BOOL isSignatureRequired;

///
/// \brief Gets the reference number
///
/// This property gets the reference number used for this transaction.
///
@property (retain, nonatomic) NSString *referenceNumber;

///
/// \brief Gets whether the Card Holder Verifiation Method (CVM) used for this transaction
///
/// This property gets whether the PIN was verified. This includes both online and offline PIN.
///
@property (retain, nonatomic) NSString *cardHolderVerificationMethod;

///
/// \brief Gets the authorization mode.
///
/// This property identifies the mode used to authorize (or decline) the transaction.
///
@property (retain, nonatomic) NSString *authorizationMode;

///
/// \brief Gets the payment type for the transaction
///
/// This property gets the payment type for the transaction.
///
@property (nonatomic) VTPPaymentType paymentType;

///
/// \brief Gets the EBT type for the transaction
///
/// This property gets the EBT type for the transaction.
///
@property (nonatomic) VTPEbtType ebtType;

///
/// \brief Gets the local date and time of the transaction
///
/// This property gets the local date and time of the transaction.
///
@property (retain, nonatomic) NSDate *transactionDateTime;

///
/// \brief Gets the merchant supplied transaction ID of the transaction
///
/// This property gets the merchant supplied transaction ID of the transaction.
///
@property (retain, nonatomic) NSString *merchantSuppliedTransactionID;

@end

#endif /* VTPFinancialResponseBase_h */
