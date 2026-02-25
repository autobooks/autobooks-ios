//
//  VTPReceiptData.h
//  triPOSMobileSDK
//
//  Created on 10/07/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTPEmvData.h"

@interface VTPReceiptData : NSObject
///
/// \brief Array of header lines string
///
/// This property gets the array of strings that need to be printed as the receipt header
///
@property (nonatomic) NSArray<NSString *> *headerLines;

///
/// \brief Gets the array of footer lines string
///
/// This property gets the array of strings that need to be printed as the receipt footer
///
@property (nonatomic) NSArray<NSString *> *footerLines;

///
/// \brief Gets the  merchant Id 
///
/// This property gets the merchant Id used for the transaction
///
@property (nonatomic) NSString *merchantId;

///
/// \brief Gets the terminal  Id
///
/// This property gets the terminal Id used for the transaction
///
@property (nonatomic) NSString *terminalId;

///
/// \brief Gets the reference number
///
/// This property gets the reference number used for the transaction.
///
@property (nonatomic) NSString *referenceNumber;

///
/// \brief Gets the account number
///
/// This property gets the account number for the transaction
///
@property (nonatomic) NSString *accountNumber;

///
/// \brief Gets the card type
///
/// This property gets the card type used for the transaction
///
@property (nonatomic) NSString *cardType;

///
/// \brief Gets the card entry type
///
/// This property gets the entry type of the card used for the transaction
///
@property (nonatomic) NSString *entryType;

///
/// \brief Gets the transaction id
///
/// This property gets the transaction Id
///
@property (nonatomic) NSString *transactionId;

///
/// \brief Gets the approval code
///
/// This property gets the approval code of the transaction
///
@property (nonatomic) NSString *approvalCode;

///
/// \brief Gets the response code
///
/// This property gets the response code of the transaction
///
@property (nonatomic) NSString *responseCode;

///
/// \brief Gets whether the transaction is approved or not.
///
/// This property gets whether the transaction is approved or not.
///
@property (nonatomic) NSString *transactionStatus;

///
/// \brief Gets the transaction type
///
/// This property gets the transaction type of the transaction
///
@property (nonatomic) NSString *transactionType;

///
/// \brief Gets the transaction amount
///
/// This property gets the transaction amount
///
@property (nonatomic) NSDecimalNumber *transactionAmount;

///
/// \brief Gets the approved amount
///
/// This property gets the approved amount of the transaction
///
@property (nonatomic) NSDecimalNumber *approvedAmount;

///
/// \brief Gets whether a signature is required or not
///
/// This property gets whether a signature is required or not.
///
@property (nonatomic) BOOL signatureRequired;

///
/// \brief Gets whether the PIN was verified
///
/// This property gets whether the PIN was verified. This includes both online and offline PIN.
///
@property (nonatomic) BOOL pinVerified;

///
/// \brief Gets the emvData flags 
///
/// This property gets the emv data flags that are used for declined transaction reference
///
@property (nonatomic) VTPEmvData *emvData;

///
/// \brief Gets the cashback amount
///
/// This property gets the cashback amount of the transaction
///
@property (nonatomic) NSDecimalNumber *cashbackAmount;

///
/// \brief Gets the tip amount
///
/// This property gets the tip amount of the transaction
///
@property (nonatomic) NSDecimalNumber *tipAmount;

///
/// \brief Gets the date time
///
/// This property gets the date time of the transaction
///
@property (nonatomic) NSDate *dateTime;

///
/// \brief Gets the type of copy
///
/// This property gets the type of copy to be shown on the receipt - ex:Customer copy, Merchant copy
///
@property (nonatomic) NSString *typeOfCopy;

///
/// \brief Gets the signature agreement text
///
/// This property gets the signature agreement text to be printed if signature is required for any transaction
@property (nonatomic) NSString *signatureAgreementText;

@end
