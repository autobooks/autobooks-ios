///
/// \file VTPFinancialCardData.h
///

#ifndef VTPFinancialCardData_h
#define VTPFinancialCardData_h

#import "VTPCardEntryMode.h"

///
/// \brief The protocol that defines the card data returned in financial responses
///
@interface VTPFinancialCardData : NSObject

///
/// \brief Gets the entry mode for the card
///
/// This property gets the entry mode for the card used for this transaction.
///
@property (nonatomic) VTPCardEntryMode entryMode;

///
/// \brief Gets the masked account number
///
/// This property gets the masked acccount number obtained from the card used for this transaction.
///
@property (retain, nonatomic) NSString *maskedAccountNumber;

///
/// \brief Gets the card logo
///
/// This property gets the card logo for this transaction. Possible values include: “Visa”, “Mastercard”, “Discover”, “Amex”, “Diners Club”, “JCB”, “Carte Blanche”, and “Other”. Currently, this property is passed back directly from the Express response and may be nil if the transaction was not processed online.
///
@property (retain, nonatomic) NSString *cardLogo;

///
/// \brief Gets the card holder name
///
/// This property gets the card holder name found on the card. This property may be nil if the card holder name is found on the card.
///
@property (retain, nonatomic) NSString *cardHolderName;

///
/// \brief Gets the expiration month for the card
///
/// This property contains the expiration month for the card used for this transaction.
///
@property (retain, nonatomic) NSString *expirationMonth;

///
/// \brief Gets the expiration year for the card
///
/// This property contains the expiration year for the card used for this transaction.
///
@property (retain, nonatomic) NSString *expirationYear;

//
/// \brief Gets the AID for the card.
///
/// This property contains the Application Identifer for the card used for this transaction.  Some Magstripe-Mode Contactless transactions
/// have an AID.
///
@property (retain, nonatomic) NSString *applicationIdentifier;

@end

#endif /* VTPFinancialCardData_h */
