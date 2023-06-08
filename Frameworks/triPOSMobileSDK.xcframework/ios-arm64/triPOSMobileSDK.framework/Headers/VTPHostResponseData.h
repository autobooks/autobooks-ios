///
/// \file VTPHostResponseData.h
///

#ifndef VTPHostResponseData_h
#define VTPHostResponseData_h

///
/// \brief The protocol that defines the host data returned in some financial responses
///
@interface VTPHostResponseData : NSObject

///
/// \brief Express response code
///
/// The result of the transaction as determined by Express.
///
@property (nonatomic, nonatomic) NSString *expressResponseCode;

///
/// \brief Express response message
///
/// A brief text description of the result of the transaction as determined by Express.
///
@property (retain, nonatomic) NSString *expressResponseMessage;

///
/// \brief Express transaction date
///
/// The date when Express processed the transaction.
/// The timezone for this value is determined by ExpressTransactionTimezone.
/// The format of this property is YYYYMMDD.
///
/// \sa ExpressTransactionTimezone
///
@property (retain, nonatomic) NSString *expressTransactionDate;

///
/// \brief Gets the Express transaction time
///
/// This property contains the time when Express processed the transaction. The timezone for this value is determined by ExpressTransactionTimezone.
///
/// \sa ExpressTransactionTimezone
///
@property (retain, nonatomic) NSString *expressTransactionTime;

///
/// \brief Gets the Express transaction time zone
///
/// This property contains the time zone in which Express processed the transaction. This value is expressed as an offset from UTC (i.e. UTC-05:00:00).
///
/// \sa ExpressTransactionDate, ExpressTransactionTime
///
@property (retain, nonatomic) NSString *expressTransactionTimezone;

///
/// \brief Gets the host response code
///
/// This property contains the response code for the transaction returned by the host that processed the transaction.
///
@property (retain, nonatomic) NSString *hostResponseCode;

///
/// \brief Gets the host response message
///
/// This property contains the response message for the transaction returned by the host that processed the transaction.
///
@property (retain, nonatomic) NSString *hostResponseMessage;

///
/// \brief Gets the processor (host) name
///
/// This property contains the name of the processor (host) that processed the transaction.
///
@property (retain, nonatomic) NSString *processorName;

///
/// \brief Gets the transaction ID
///
/// This property contains the unique transaction identifier retuned by Express.
///
@property (retain, nonatomic) NSString *transactionID;

///
/// \brief Gets the approval number
///
/// This property contains the issuer assigned approval number.
///
@property (retain, nonatomic) NSString *approvalNumber;

///
/// \brief Gets the raw Express XML response
///
/// This property contains the raw Express response XML.
///
@property (retain, nonatomic) NSString *expressResponseXml;

///
/// \brief Gets network label
///
/// This property contains the network label.  Not avaiable for all processors.
///
@property (retain, nonatomic) NSString *networkLabel;

@end

#endif /* VTPHostResponseData_h */
