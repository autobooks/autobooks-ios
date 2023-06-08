///
/// \file VXPRequest.h
///

#ifndef VXPResponse_h
#define VXPResponse_h

#import "VXPBase.h"
#import "VXPAddress.h"
#import "VXPCredentials.h"
#import "VXPCard.h"
#import "VXPBatch.h"
#import "VXPTransaction.h"
#import "VXPBIN.h"
#import "VXPTransactionSetup.h"
#import "VXPAddress.h"
#import "VXPPaymentAccount.h"
#import "VXPPcrtData.h"
#import "VXPResponseCode.h"
#import "VXPResponseType.h"
#import "VXPToken.h"

///
/// \class VXPResponse
/// \brief Response class
///
/// The response class is used to communicate any output messages back to the sender.
/// An ExpressResponseCode is returned with every transaction and should be the first
/// field examined to determine success or failure.
///
@interface VXPResponse : VXPBase

///
/// \brief Type of message.
///
/// Specifies the type of message.
///
@property (nonatomic) VXPResponseType Type;

///
/// \brief Credentials class
///
/// An instance of the Credentials class. NOTE: This property is only present if the Credentials class is present in the Express response.
///
@property (retain, nonatomic) VXPCredentials *Credentials;

///
/// \brief Card class
///
/// An instance of the Credentials class. NOTE: This property is only present if the Card class is present in the Express response.
///
@property (retain, nonatomic) VXPCard *Card;

///
/// \brief Batch class
///
/// An instance of the Batch class. NOTE: This property is only present if the Batch class is present in the Express response.
///
@property (retain, nonatomic) VXPBatch *Batch;

///
/// \brief Transaction class
///
/// An instance of the Transaction class. NOTE: This property is only present if the Transaction class is present in the Express response.
///
@property (retain, nonatomic) VXPTransaction *Transaction;

///
/// \brief BIN class
///
/// An instance of the BIN class. NOTE: This property is only present if the BIN class is present in the Express response.
///
@property (retain, nonatomic) VXPBIN *BIN;

///
/// \brief TransactionSetup class
///
/// An instance of the TransactionSetup class. NOTE: This property is only present if the TransactionSetup class is present in the Express response.
///
@property (retain, nonatomic) VXPTransactionSetup *TransactionSetup;

///
/// \brief PaymentAccount class
///
/// An instance of the PaymentAccount class. NOTE: This property is only present if the PaymentAccount class is present in the Express response.
///
@property (retain, nonatomic) VXPPaymentAccount *PaymentAccount;

///
/// \brief Address class
///
/// An instance of the Address class. NOTE: This property is only present if the Address class is present in the Express response.
///
@property (retain, nonatomic) VXPAddress *Address;

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
/// \brief Express transaction date
///
/// The date when Express processed the transaction.
/// The timezone for this value is determined by ExpressTransactionTimezone.
/// The format of this property is YYYYMMDD.
///
/// \sa ExpressTransactionTimezone
///
@property (retain, nonatomic) NSString *ExpressTransactionDate;

///
/// \brief Express transaction time
///
/// The time when Express processed the transaction.
/// The timezone for this value is determined by ExpressTransactionTimezone.
/// The format of this property is HHMMSS where HH is 00-23.
///
/// \sa ExpressTransactionTimezone
///
@property (retain, nonatomic) NSString *ExpressTransactionTime;

///
/// \brief Express transaction time zone
///
/// The time zone in which Express processed the transaction. This value is expressed as an offset from UTC (i.e. UTC-05:00:00).
///
/// \sa ExpressTransactionDate, ExpressTransactionTime
///
@property (retain, nonatomic) NSString *ExpressTransactionTimezone;

///
/// \brief Express response XML
///
/// The raw response XML.
///
@property (retain, nonatomic) NSString *RawResponse;

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
/// \brief Host transaction date/time
///
/// Date and time of the host that processed the transaction.
///
@property (retain, nonatomic) NSString *HostTransactionDateTime;

///
/// \brief Query data
///
/// Query information in XML format.
///
@property (retain, nonatomic) NSString *QueryData;

///
/// \brief QueryDataEx  (CONVENIENCE, readonly)
///
/// An array of parsed VXPPaymentAccountQueryRecordCountItems, VXPPaymentAccountTokenReportItems, or VXPPaymentAccountQueryItems.
/// This property is for convenience and not part of the Express message.
///
/// \sa VXPPaymentAccountQueryRecordCountItem, VXPPaymentAccountTokenReportItem, or VXPPaymentAccountQueryItem
///
@property (retain, nonatomic) NSArray *QueryDataEx;

///
/// \brief Reporting data
///
/// Transaction report information in XML format.
///
@property (retain, nonatomic) NSString *ReportingData;

///
/// \brief ReportDataEx (CONVENIENCE)
///
/// An array of parsed VXPReportingDataItems.
/// This property is for convenience and not part of the Express message.
///
/// \sa VXPReportingData
///
@property (retain, nonatomic, readonly) NSArray *ReportingDataEx;

///
/// \brief Services ID
///
/// Unique services identifier.
///
@property (retain, nonatomic) NSString *ServicesID;

///
/// \brief Reporting ID
///
/// Unique reporting identifier.
///
@property (retain, nonatomic) NSString *ReportingID;

///
/// \brief Express transaction date and time (CONVENIENCE)
///
/// Date and time when Express processed the transaction.
/// This property returns an NSDate object equivilant to ExpressTransactionDate, ExpressTransactionTime, and ExpressTransactionTimezone.
/// This property is for convenience and not part of the Express message.
///
/// \sa ExpressTransactionDate, ExpressTransactionTime, ExpressTransactionTimezone
///
@property (retain, nonatomic, readonly) NSDate *ExpressTransactionDateTimeEx;

///
/// \brief Host transaction date and time (CONVENIENCE)
///
/// Date and time when the host processed the transaction.
/// This property returns an NSDate object equivilant to HostTransactionDateTime.
/// This property is for convenience and not part of the Express message.
///
/// \sa HostTransactionDateTime
///
@property (retain, nonatomic, readonly) NSDate *HostTransactionDateTimeEx;

///
/// \brief gets or sets the Token class
///
/// This property gets or sets the Token class.
///
@property (retain, nonatomic) VXPToken *Token;

///
/// \brief Gets or sets the PcrtData class
///
/// This property gets or sets the PcrtData class.
///
@property (retain, nonatomic) VXPPcrtData *PCRTData;

///
/// \brief Returns the URL to use for Hosted Payments
///
/// This method creates and returns the URL used for Hosted Payments based on the transactionSetupID and testCertification parameters.
///
/// \param transactionSetupID The transactionSetupID returned in a TransactionSetup response.
///
/// \param testCertification Flag that indicates whether to use the test/certification or production host.
///
/// \return An NSURL set to the appropriate value.
///
/// \sa HostedPaymentsUrl
///
+(NSURL *)hostedPaymentsUrlWithTransactionSetupID:(NSString *)transactionSetupID testCertification:(BOOL)testCertification;

///
/// \brief Returns the URL to use for Hosted Payments
///
/// This property gets the URL used for Hosted Payments. This value should only be queried after a successful
/// TransactionSetup request/response. The property will be nil if Response, Response.TransactionSetup, or
/// Response.TransactionSetup.TransactionSetupID is not set.
///
@property (retain, nonatomic) NSURL *HostedPaymentsUrl;

///
/// \brief Returns an VXPResponse object from the message.
///
/// This method returns an VXPResponse object with its properties set according to the data received from Express.
///
/// \param message The message received from Express.
///
/// \return A VXPResponse object initialized with the Express message.
///
-(instancetype)initWithString:(NSString *)message;

///
/// \brief Creates and returns an VXPResponse object from the message.
///
/// This method creates an VXPResponse object and sets the properties according to the data received from Express.
///
/// \param message The message received from Express.
///
/// \return A VXPResponse object initialized with the Express message.
///
+(VXPResponse *)responseWithString:(NSString *)message;

///
/// \brief Returns an VXPResponse object from the Hosted Payments return URL
///
/// This method returns an VXPResponse object with its properties set according to the Hosted Payments return URL.
///
/// \param returnUrl The Hosted Payments return URL.
///
/// \return A VXPResponse object initialized with the Hosted Payments return URL.
///
-(instancetype)initWithHostedPaymentsReturnUrl:(NSURL *)returnUrl;

///
/// \brief Creates and returns an VXPResponse object from the Hosted Payments return URL.
///
/// This method creates and returns an VXPResponse object with its properties set according to the Hosted Payments return URL.
///
/// \param returnUrl The Hosted Payments return URL.
///
/// \return A VXPResponse object initialized with the Hosted Payments return URL.
///
+(VXPResponse *)responseWithHostedPaymentsReturnUrl:(NSURL *)returnUrl;

///
/// \brief Gets this object as an XML string
///
/// Gets all class properties and returns them as an XML string.
///
/// \return An NSString containing all class properties as XML.
///
-(NSString *)getXmlString;

///
/// \brief Converts a message type to a C string
///
/// This method converts a message type to a C string.
///
/// \return A string representing the type or "UNKNOWN".
///
+(const char *)cstringFromResponseType:(VXPResponseType)type;

///
/// \brief Converts a message type to a string
///
/// This method converts a message type to a string.
///
/// \return A string representing the type or "UNKNOWN".
///
+(NSString *)stringFromResponseType:(VXPResponseType)type;


@end

#endif /* VXPResponse_h */
