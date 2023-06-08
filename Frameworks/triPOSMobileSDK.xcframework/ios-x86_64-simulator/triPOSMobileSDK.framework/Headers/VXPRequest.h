///
/// \file VXPRequest.h
///

#ifndef VXPRequest_h
#define VXPRequest_h

#import <Foundation/Foundation.h>

#import "VXPAddress.h"
#import "VXPApplication.h"
#import "VXPBatch.h"
#import "VXPCard.h"
#import "VXPCredentials.h"
#import "VXPDemandDepositAccount.h"
#import "VXPEBT.h"
#import "VXPError.h"
#import "VXPExtendedParameters.h"
#import "VXPIdentification.h"
#import "VXPPaging.h"
#import "VXPParameters.h"
#import "VXPPaymentAccount.h"
#import "VXPPaymentAccountParameters.h"
#import "VXPPcrtData.h"
#import "VXPRequestType.h"
#import "VXPScheduledTask.h"
#import "VXPTransaction.h"
#import "VXPTerminal.h"
#import "VXPTransactionSetup.h"

///
/// \class VXPRequest
///
/// \brief Express request message definition
///
/// This is the Express request message definition.
///
@interface VXPRequest : NSObject

///
/// \brief Gets or sets the type of message.
///
/// This property gets or sets he type of message.
///
@property (nonatomic) VXPRequestType Type;

///
/// \brief Gets or sets the Application class
///
/// This property gets or sets teh Application class. The Application class is required for every transaction and is used to uniquely identify the sending application.
///
@property (retain, nonatomic) VXPApplication *Application;

///
/// \brief Gets or sets Credentials class
///
/// This property gets or sets the Credentials class. The Credentials class is required for every transaction and is used to authenticate the sender.
///
@property (retain, nonatomic) VXPCredentials *Credentials;

///
/// \brief Gets or sets the Transaction class
///
/// This property gets or sets the Transaction class.
///
@property (retain, nonatomic) VXPTransaction *Transaction;

///
/// \brief Gets or sets Terminal class
///
/// This property gets or sets the Terminal class.
///
@property (retain, nonatomic) VXPTerminal *Terminal;

///
/// \brief Gets or sets the Card class
///
/// This property gets or sets the Card class. The Card class is used to transmit/receive cardholder information.
///
@property (retain, nonatomic) VXPCard *Card;

///
/// \brief Gets or sets the PaymentAccount class
///
/// This property gets or sets the PaymentAccount class.
///
@property (retain, nonatomic) VXPPaymentAccount *PaymentAccount;

///
/// \brief Gets or sets the PaymentAccountParameters class
///
/// This property gets or sets the PaymentAccountParameters class.
///
@property (retain, nonatomic) VXPPaymentAccountParameters *PaymentAccountParameters;

///
/// \brief Gets or sets the Address class
///
/// This property gets or sets the Address class.
///
@property (retain, nonatomic) VXPAddress *Address;

///
/// \brief Gets or sets the Healthcare class
///
/// This property gets or sets the Healthcare class.
///
@property (retain, nonatomic) VXPHealthcare *Healthcare;

#if VXPPHASE > 1
///
/// \brief Gets or sets the ScheduledTask class
///
/// This property gets or sets the Scheduled class. The ScheduledTask class is used ot schedule transaction.
///
@property (retain, nonatomic) VXPScheduledTask *ScheduledTask;
#endif      //end of VXPPHASE > 1

#if VXPPHASE > 1
///
/// \brief Gets or sets the Identification class
///
/// This property gets or sets sthe Identification class.
///
@property (retain, nonatomic) VXPIdentification *Identification;
#endif      //end of VXPPHASE > 1

#if VXPPHASE > 1
///
/// \brief Gets or sets DemandDepositAccount class
///
/// This property gets or sets DemandDepositAccount class.
///
@property (retain, nonatomic) VXPDemandDepositAccount *DemandDepositAccount;
#endif      //end of VXPPHASE > 1

///
/// \brief Gets or sets Parameters class
///
/// This property gets or sets the Parameters class.
///
@property (retain, nonatomic) VXPParameters *Parameters;

///
/// \brief Gets or sets the Batch class
///
/// This property gets or sets the BatchClass. The Batch class is used to request and receive batch information from Express.
///
@property (retain, nonatomic) VXPBatch *Batch;

///
/// \brief Gets or sets the TransactionSetup class
///
/// This property gets or sets the TransactionSetup class.
///
@property (retain, nonatomic) VXPTransactionSetup *TransactionSetup;

///
/// \brief gets or sets the ExtendedParameters class
///
/// This property gets or sets the ExtendedParameters class.
///
@property (retain, nonatomic) VXPExtendedParameters *ExtendedParameters;

///
/// \brief gets or sets the Token class
///
/// This property gets or sets the Token class.
///
@property (retain, nonatomic) VXPToken *Token;

///
/// \brief Gets or sets the Paging class
///
/// This property gets or sets the Paging class.
///
@property (retain, nonatomic) VXPPaging *Paging;

///
/// \brief Gets or sets the EBT class
///
/// This property gets or sets the EBT class.
///
@property (retain, nonatomic) VXPEBT *EBT;

///
/// \brief Gets or sets the PcrtData class
///
/// This property gets or sets the PcrtData class.
///
@property (retain, nonatomic) VXPPcrtData *PCRTData;

///
/// \brief Returns an VXPRequest object initialized with credentials
///
/// This method returns an VXPRequest object with Credentials and Application initialized with the supplied information.
///
/// \param requestType The type of request.
///
/// \param credentials An instance of a Credentials class used for this message. This parameter may be nil, but Credentials must be set before processing the transaction.
///
/// \param application An instance of an Application class used for this message. This parameter may be nil, but Application must be set before processing the transaction.
///
/// \return An VXPRequest object initialized with the supplied information.
///
-(instancetype)initWithRequestType:(VXPRequestType)requestType credentials:(VXPCredentials *)credentials application:(VXPApplication *)application;

///
/// \brief Creates and returns an VXPRequest object initialized with credentials
///
/// This method creates and returns an VXPRequest object with Credentials and Application initialized with the supplied information.
///
/// \param requestType The type of request.
///
/// \param credentials An instance of a Credentials class used for this message. This parameter may be nil, but Credentials must be set before processing the transaction.
///
/// \param application An instance of an Application class used for this message. This parameter may be nil, but Application must be set before processing the transaction.
///
/// \return A VXPRequest object initialized with the supplied information.
///
+(VXPRequest *)requestWithRequestType:(VXPRequestType)requestType credentials:(VXPCredentials *)credentials application:(VXPApplication *)application;

///
/// \brief Converts a message type to a C string
///
/// This method converts a message type to a C string.
///
/// \return A string representing the type or "UNKNOWN".
///
+(const char *)cstringFromRequestType:(VXPRequestType)type;

///
/// \brief Converts a message type to a string
///
/// This method converts a message type to a string.
///
/// \return A string representing the type or "UNKNOWN".
///
+(NSString *)stringFromRequestType:(VXPRequestType)type;

///
/// \brief Converts a C string to a message type
///
/// This method converts a C string to a message type.
///
/// \return A valid VXPType or VXPTypeUnknown if the string is NULL or unknown.
///
+(VXPRequestType)requestTypeFromCString:(const char *)cstring;

///
/// \brief Converts a string to a message type
///
/// This method converts a string to a message type.
///
/// \return A valid VXPType or VXPTypeUnknown if the string is NULL or unknown.
///
+(VXPRequestType)requestTypeFromString:(NSString *)string;

///
/// \brief Serializes the Express message
///
/// This method generates stream of data that is transmitted to Express. This data is dependent on the values of the properties in the Express message.
///
/// \return The serialized Express message or nil if there was an error.
///
-(NSString *)getXmlString;

@end

//
// VXPReportingData.h relies on the definition of VXPRequest
//
#import "VXPReportingData.h"

#endif /* VXPRequest_h */
