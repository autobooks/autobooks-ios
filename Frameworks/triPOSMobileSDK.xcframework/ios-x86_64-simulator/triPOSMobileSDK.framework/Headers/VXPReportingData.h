///
/// \file VXPReportingData.h
///

#ifndef VXPReportingData_h
#define VXPReportingData_h

#import <Foundation/Foundation.h>

#import "VXPBase.h"

#import "VXPResponse.h"
#import "VXPTransaction.h"
#import "VXP.h"

///
/// \class VXPReportingDataItem
/// \brief Reporting data item class
///
/// This class is a utility class that defines individual items in the ReportingData field.
/// This class is not part of the Express message specification.
///
@interface VXPReportingDataItem : VXPBase

///
/// \brief Terminal ID
///
/// Unique transaction identifier.
///
@property (retain, nonatomic) NSString *TransactionID;
    
///
/// \brief Acceptor ID
///
/// Unique merchant account identifier. Assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *AcceptorID;
    
///
/// \brief Account ID
///
/// Unique account ID. Assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *AccountID;
    
///
/// \brief Name
///
/// Name.
///
@property (retain, nonatomic) NSString *Name;
    
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
/// Approved dollar amount.
///
@property (retain, nonatomic) NSDecimalNumber *ApprovedAmount;
    
///
/// \brief Address verification response code
///
/// Address verification response code.
///
@property (retain, nonatomic) NSString *AVSResponseCode;
    
///
/// \brief Card verification value response code
///
/// Card verification value response code.
///
@property (retain, nonatomic) NSString *CVVResponseCode;
    
///
/// \brief Expiration month
///
/// Expiration month.
///
@property (retain, nonatomic) NSString *ExpirationMonth;
    
///
/// \brief Expiration year
///
/// Expiration year.
///
@property (retain, nonatomic) NSString *ExpirationYear;
    
///
/// \brief Express response code
///
/// The result of the transaction as determined by Express.
///
@property (nonatomic) VXPResponseCode ExpressResponseCode;
    
///
/// \brief Express response message
///
/// A brief text description of the result of the transaction as determined by Express.
///
@property (retain, nonatomic) NSString *ExpressResponseMessage;
    
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
/// \brief Host response code
///
/// Response code for the transaction returned by the host that processed the transaction.
///
@property (retain, nonatomic) NSString *HostResponseCode;
    
///
/// \brief Host response message
///
/// Response message for the transaction returned by the host that processed the transaction.
///
@property (retain, nonatomic) NSString *HostResponseMessage;
    
///
/// \brief Reference number
///
/// User assigned reference number.
///
@property (retain, nonatomic) NSString *ReferenceNumber;
    
///
/// \brief Ticket number
///
/// User assigned ticket number.
///
@property (retain, nonatomic) NSString *TicketNumber;

///
/// \brief Tracking ID
///
/// Tracking ID.
///
@property (retain, nonatomic) NSString *TrackingID;
    
///
/// \brief Terminal type
///
/// Terminal type.
///
@property (retain, nonatomic) NSString *TerminalType;

///
/// \brief Transaction amount
///
/// Dollar amount of the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *TransactionAmount;
    
///
/// \brief Transaction status
///
/// Description of the status/state of the transaction.
///
@property (retain, nonatomic) NSString *TransactionStatus;
    
///
/// \brief Transaction status code
///
/// Status/state of the transaction.
///
@property (nonatomic) VXPTransactionStatusCode TransactionStatusCode;
    
///
/// \brief Transaction type
///
/// Type of transaction.
///
/// \sa TransactionTypeEx
///
@property (retain, nonatomic) NSString *TransactionType;

///
/// \brief Transaction type (CONVENIENCE)
///
/// Type of transaction.
///
/// \sa TransactionType
///
@property (nonatomic, readonly) VXPRequestType TransactionTypeEx;

///
/// \brief Card number masked
///
/// Masked card account number.
///
@property (retain, nonatomic) NSString *CardNumberMasked;
    
///
/// \brief Card logo
///
/// Brand of the card. Possible values include: Visa, Mastercard, Discover, Amex, Diners Club, JCB, Carte Blanche, Other.
///
@property (retain, nonatomic) NSString *CardLogo;
    
///
/// \brief Card type
///
/// Type of the card.
///
@property (retain, nonatomic) NSString *CardType;

///
/// \brief Track data present
///
/// Indicates whether track data was present in the transaction.
///
@property (nonatomic) BOOL TrackDataPresent;
    
///
/// \brief Sales tax amount
///
/// Dollar amount of the sales tax for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *SalesTaxAmount;

///
/// \brief Tip amount
///
/// Dollar amount of the tip for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *TipAmount;

///
/// \brief Cash back amount
///
/// Dollar amount of the cash back for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *CashBackAmount;

///
/// \brief Express transaction date
///
/// The date when Express processed the transaction.
/// The timezone for this value is determined by ExpressTransactionTimezone.
/// The format of this property is YYYYMMDD.
///
@property (retain, nonatomic) NSString *ExpressTransactionDate;
    
///
/// \brief Express transaction time
///
/// The time when Express processed the transaction.
/// The timezone for this value is determined by ExpressTransactionTimezone.
/// The format of this property is HHMMSS where HH is 00-23.
///
@property (retain, nonatomic) NSString *ExpressTransactionTime;
    
///
/// \brief Time stamp
///
/// Time stamp.
///
@property (retain, nonatomic) NSString *TimeStamp;

///
/// \brief Undefined items
///
/// Undefined items.
///
@property (retain, nonatomic) NSDictionary *UndefinedItems;

@end

///
/// \class VXPReportingData
/// \brief Reporting data class
///
/// This class is a utility class used to parse the ReportingData field.
/// This class is not part of the Express message specification.
///
@interface VXPReportingData : VXPBase

///
/// \brief Parses the ReportingData XML
///
/// This method parses the reporting data XML and returns an array of VXPReportingDataItems.
///
/// \param reportingData The XML string returned in ReportingData.
///
/// \return An array of VXPReportingDataItem.
///
+(NSArray *)parseReportItems:(NSString *)reportingData;

@end

#endif /* VXPReportingData_h */
