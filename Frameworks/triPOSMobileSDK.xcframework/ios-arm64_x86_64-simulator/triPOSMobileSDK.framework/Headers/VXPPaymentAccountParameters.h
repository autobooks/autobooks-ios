///
/// \file VXPPaymentAccountParameters.h
///

#ifndef VXPPaymentAccountParameters_h
#define VXPPaymentAccountParameters_h

#import "VXPBase.h"
#import "VXPPaymentAccount.h"
#import "VXPPASSUpdaterStatus.h"

//@class VXPPaymentAccountQueryRecordCountItem;

///
/// \class VXPPaymentAccountParameters
/// \brief Payment account class
///
/// This class is used in transactions utilizing our Payment Account Secure Storage (PASS) service.
///
@interface VXPPaymentAccountParameters : VXPBase
        
///
/// \brief Payment account ID.
///
/// Unique GUID that identifies the payment account. The Express platform generates this.
///
@property (retain, nonatomic) NSString *PaymentAccountID;

///
/// \brief Payment account type.
///
/// The type of payment account.
///
@property (nonatomic) VXPPaymentAccountType PaymentAccountType;

///
/// \brief Payment account reference number.
///
/// User generated reference number used to identify a payment account.
///
@property (retain, nonatomic) NSString *PaymentAccountReferenceNumber;

///
/// \brief Payment brand.
///
/// Card type for the query. Must match exactly and can be Visa, MasterCard, Discover, Amex, or Diners Club.
///
@property (retain, nonatomic) NSString *PaymentBrand;

///
/// \brief Expiration month begin.
///
/// Beginning expiration month for the query.
///
@property (retain, nonatomic) NSString *ExpirationMonthBegin;

///
/// \brief Expiration month end.
///
/// Ending expiration month for the query.
///
@property (retain, nonatomic) NSString *ExpirationMonthEnd;

///
/// \brief Expiration year begin.
///
/// Beginning expiration year for the query.
///
@property (retain, nonatomic) NSString *ExpirationYearBegin;

///
/// \brief Expiration year end.
///
/// Ending expiration year for the query.
///
@property (retain, nonatomic) NSString *ExpirationYearEnd;

///
/// \brief Transaction setup ID.
///
/// Unique GUID that identifies the transaction setup ID. The Express platform generates this.
///
@property (retain, nonatomic) NSString *TransactionSetupID;

///
/// \brief PASS updater batch status.
///
/// Specifies whether or not the PASS record will be included in the next PASS updater batch.
///
@property (nonatomic) VXPPASSUpdaterBatchStatus PASSUpdaterBatchStatus;

///
/// \brief PASS updater date/time begin.
///
/// Beginning date and time for the query formatted YYYY-MM-dd HH:MM:SS.FFF.
///
@property (retain, nonatomic) NSString *PASSUpdaterDateTimeBegin;

///
/// \brief PASS updater date/time end.
///
/// Ending date and time for the query formatted YYYY-MM-dd HH:MM:SS.FFF.
///
@property (retain, nonatomic) NSString *PASSUpdaterDateTimeEnd;

///
/// \brief PASS updater date/time begin (CONVENIENCE).
///
/// Beginning date and time for the query.
/// This property gets/sets PASSUpdaterDateTimeBegin using the value in the NSDate object.
/// This property is for convenience and not part of the Express message.
///
/// \sa ExpressTransactionDate, ExpressTransactionTime
///
@property (retain, nonatomic, readonly) NSDate *PASSUpdaterDateTimeBeginEx;

///
/// \brief PASS updater date/time end (CONVENIENCE).
///
/// Ending date and time for the query.
/// This property gets/sets PASSUpdaterDateTimeEnd using the value in the NSDate object.
/// This property is for convenience and not part of the Express message.
///
/// \sa ExpressTransactionDate, ExpressTransactionTime
///
@property (retain, nonatomic, readonly) NSDate *PASSUpdaterDateTimeEndEx;

///
/// \brief PASS updater status.
///
/// Specifies the match status of the PASS record.
///
@property (nonatomic) VXPPASSUpdaterStatus PASSUpdaterStatus;

@end

///
/// \class VXPPaymentAccountQueryRecordCountItem
/// \brief Payment account query record count class
///
/// This class is a utility class that defines individual items in the QueryData field returned in a PaymentAccountQueryRecordCount response.
/// This class is not part of the Express message specification.
///
@interface VXPPaymentAccountQueryRecordCountItem : VXPBase

///
/// \brief Record count.
///
/// Record count.
///
@property (retain, nonatomic) NSNumber *RecordCount;

///
/// \brief Page count.
///
/// Page count.
///
@property (retain, nonatomic) NSNumber *PageCount;

@end

///
/// \class VXPPaymentAccountTokenReportItem
/// \brief Payment account token report item class
///
/// This class is a utility class that defines individual items in the QueryData field returned in a PaymentAccountQueryTokenReport response.
/// This class is not part of the Express message specification.
///
@interface VXPPaymentAccountTokenReportItem : VXPBase

///
/// \brief Payment account ID.
///
/// Unique GUID that identifies the payment account. The Express platform generates this.
///
@property (retain, nonatomic) NSString *T;

///
/// \brief Payment account reference number.
///
/// User generated reference number used to identify a payment account.
///
@property (retain, nonatomic) NSString *R;

@end

///
/// \class VXPPaymentAccountQueryItem
/// \brief Payment account guery item class
///
/// This class is a utility class that defines individual items in the QueryData field returned in a PaymentAccountQuery response.
/// This class is not part of the Express message specification.
///
@interface VXPPaymentAccountQueryItem : VXPBase

///
/// \brief Payment account ID.
///
/// Unique GUID that identifies the payment account. The Express platform generates this.
///
@property (retain, nonatomic) NSString *PaymentAccountID;

///
/// \brief Payment account type.
///
/// The type of payment account.
///
@property (nonatomic) VXPPaymentAccountType PaymentAccountType;

///
/// \brief Truncated account number.
///
/// Truncated account number associated with this payment account.
///
@property (retain, nonatomic) NSString *TruncatedCardNumber;

///
/// \brief Expiration month.
///
/// Expiration month for the account associated with this payment account.
///
@property (retain, nonatomic) NSString *ExpirationMonth;

///
/// \brief Expiration year.
///
/// Expiration year for the account associated with this payment account.
///
@property (retain, nonatomic) NSString *ExpirationYear;

///
/// \brief Payment account reference number.
///
/// User generated reference number used to identify a payment account.
///
@property (retain, nonatomic) NSString *PaymentAccountReferenceNumber;

///
/// \brief Payment brand.
///
/// Card type for the query. Must match exactly and can be Visa, MasterCard, Discover, Amex, or Diners Club.
///
@property (retain, nonatomic) NSString *PaymentBrand;

///
/// \brief PASS updater batch status.
///
/// Specifies whether or not the PASS record will be included in the next PASS updater batch.
///
@property (nonatomic) VXPPASSUpdaterBatchStatus PASSUpdaterBatchStatus;

///
/// \brief PASS updater status.
///
/// Specifies the match status of the PASS record.
///
@property (nonatomic) VXPPASSUpdaterStatus PASSUpdaterStatus;

@end

#endif /* VXPPaymentAccountParameters_h */
