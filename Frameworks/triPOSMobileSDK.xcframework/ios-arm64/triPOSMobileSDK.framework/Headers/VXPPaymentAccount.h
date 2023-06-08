///
/// \file VXPPaymentAccount.h
///

#ifndef VXPPaymentAccount_h
#define VXPPaymentAccount_h

#import "VXPBase.h"
#import "VXPPaymentAccountType.h"
#import "VXPPASSUpdaterBatchStatus.h"
#import "VXPPASSUpdaterOption.h"

///
/// \class VXPPaymentAccount
/// \brief Payment account class
///
/// This class is used in transactions utilizing our Payment Account Secure Storage (PASS) service.
///
@interface VXPPaymentAccount : VXPBase
        
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
/// \brief PASS updater option.
///
/// Specifies the match status of the PASS record.
///
@property (nonatomic) VXPPASSUpdaterOption PASSUpdaterOption;

///
/// \brief Parses the QueryData XML for PaymentAccountQueryRecordCount
///
/// This method parses the query data XML and returns an array of type VXPPaymentAccountQueryRecordCountItem.
/// The data in QueryData must be the data returned for a PaymentAccountQueryRecordCount request.
///
/// \param queryData The XML string returned in QueryData.
///
/// \return An array of type VXPPaymentAccountQueryRecordCountItem.
///
+(NSArray *)parseRecordCount:(NSString *)queryData;

///
/// \brief Parses the QueryData XML for PaymentAccountTokenReport
///
/// This method parses the query data XML and returns an array of type VXPPaymentAccountTokenReportItem.
/// The data in QueryData must be the data returned for a PaymentAccountTokenReport request.
///
/// \param queryData The XML string returned in QueryData.
///
/// \return An array of type VXPPaymentAccountTokenReportItem.
///
+(NSArray *)parseTokenReport:(NSString *)queryData;

///
/// \brief Parses the QueryData XML for PaymentAccountTokenReport
///
/// This method parses the query data XML and returns an array of type VXPPaymentAccountQueryItem.
/// The data in QueryData must be the data returned for a PaymentAccountQuery request.
///
/// \param queryData The XML string returned in QueryData.
///
/// \return An array of VXPPaymentAccountQueryItem.
///
+(NSArray *)parseQueryItems:(NSString *)queryData;

///
/// \brief Identifies and parses the QueryData XML for PaymentAccountQueryRecordCount, PaymentAccountTokenReport, or PaymentAccountTokenReport
///
/// This method identifies then parses the query data XML and returns an array of of type VXPPaymentAccountQueryRecordCountItem, VXPPaymentAccountTokenReportItem, or VXPPaymentAccountQueryItem.
///
/// \param queryData The XML string returned in QueryData.
///
/// \return An array of type VXPPaymentAccountQueryRecordCountItem, VXPPaymentAccountTokenReportItem, or VXPPaymentAccountQueryItem.
///
+(NSArray *)parseQueryData:(NSString *)queryData;

@end

#endif /* VXPPaymentAccount_h */
