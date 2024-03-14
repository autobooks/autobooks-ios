///
/// \file VXPParameters.h
///

#ifndef VXPParameters_h
#define VXPParameters_h

#import "VXPBase.h"
#import "VXPTerminal.h"

///
/// \class VXPParameters
/// \brief Parameters class
///
/// This class is used for reporting transactions.
///
@interface VXPParameters : VXPBase
        
///
/// \brief Transaction date/time begin
///
/// Date/time for the beginning of the transaction range formatted YYYY-MM-DD HH:MM:SS.FFF.
///
@property (retain, nonatomic) NSString *TransactionDateTimeBegin;

///
/// \brief Transaction date/time end
///
/// Date/time for the beginning of the transaction range formatted YYYY-MM-DD HH:MM:SS.FFF.
///
@property (retain, nonatomic) NSString *TransactionDateTimeEnd;

///
/// \brief Transaction date and time begin (CONVENIENCE)
///
/// Date and time for the beginning of the transaction range.
/// This property gets/sets TransactionDateTimeBegin using the value in the NSDate object.
/// This property is for convenience and not part of the Express message.
///
/// \sa TransactionDateTimeBegin
///
@property (retain, nonatomic) NSDate *TransactionDateTimeBeginEx;

///
/// \brief Transaction date and time end (CONVENIENCE)
///
/// Date and time for the end of the transaction range.
/// This property gets/sets TransactionDateTimeEnd using the value in the NSDate object.
/// This property is for convenience and not part of the Express message.
///
/// \sa TransactionDateTimeEnd
///
@property (retain, nonatomic) NSDate *TransactionDateTimeEndEx;

///
/// \brief Transaction ID
///
/// Unique transaction ID.
///
@property (retain, nonatomic) NSString *TransactionID;

///
/// \brief Terminal ID
///
/// Unique terminal identifier assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *TerminalID;

///
/// \brief Application ID
///
/// Unique application identifier. This value is assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *ApplicationID;

///
/// \brief Approval number
///
/// Issuer assigned approval number.
///
@property (retain, nonatomic) NSString *ApprovalNumber;

///
/// \brief Approved amount
///
/// Amount approved by the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *ApprovedAmount;

///
/// \brief Express transaction date
///
/// Express transaction date formatted YYMMDD.
///
@property (retain, nonatomic) NSString *ExpressTransactionDate;

///
/// \brief Express transaction time
///
/// Express transaction time.
///
@property (retain, nonatomic) NSString *ExpressTransactionTime;

///
/// \brief Express transaction date and time (CONVENIENCE)
///
/// Express date and time of the transaction.
/// This property gets/sets ExpressTransactionDate and ExpressTransactionTime using the value in the NSDate object.
/// This property is for convenience and not part of the Express message.
///
/// \sa ExpressTransactionDate, ExpressTransactionTime
///
@property (retain, nonatomic) NSDate *ExpressTransactionDateTimeEx;

///
/// \brief Host batch ID
///
/// Host batch ID.
///
@property (retain, nonatomic) NSString *HostBatchID;

///
/// \brief Host item ID
///
/// Host item ID.
///
@property (retain, nonatomic) NSString *HostItemID;

///
/// \brief Host reversal queue ID
///
/// Host reversal queue ID.
///
@property (retain, nonatomic) NSString *HostReversalQueueID;

///
/// \brief Original authorized amount
///
/// Original authorized amount.
///
@property (retain, nonatomic) NSDecimalNumber *OriginalAuthorizedAmount;

///
/// \brief Reference number
///
/// Reference number.
///
@property (retain, nonatomic) NSString *ReferenceNumber;

///
/// \brief Shift ID
///
/// Shift ID.
///
@property (retain, nonatomic) NSString *ShiftID;

///
/// \brief Source transaction ID
///
/// Source transaction ID.
///
@property (retain, nonatomic) NSString *SourceTransactionID;

///
/// \brief Terminal type
///
/// Terminal type.
///
@property (nonatomic) VXPTerminalType TerminalType;

///
/// \brief Tracking ID
///
/// Tracking ID.
///
@property (retain, nonatomic) NSString *TrackingID;

///
/// \brief Transaction amount
///
/// Transaction amount.
///
@property (retain, nonatomic) NSDecimalNumber *TransactionAmount;

///
/// \brief Transaction setup ID
///
/// Transaction setup ID.
///
@property (retain, nonatomic) NSString *TransactionSetupID;

///
/// \brief Transaction status
///
/// Transaction status.
///
@property (retain, nonatomic) NSString *TransactionStatus;

///
/// \brief Transaction type
///
/// Transaction type.
///
@property (retain, nonatomic) NSString *TransactionType;

///
/// \brief Verified by Visa value
///
/// Verified by Visa value.
///
@property (retain, nonatomic) NSString *XID;

///
/// \brief Reverse order
///
/// Indicates the records are in descending order.
///
@property (nonatomic) VXPBooleanType ReverseOrder;

@end

#endif /* VXPParameters_h */
