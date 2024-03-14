///
/// \file VXPCard.h
///

#ifndef VXPCard_h
#define VXPCard_h

#import "VXPBase.h"
#import "VXPCardEncryptedFormat.h"
#import "VXPEncryptedEmvFormat.h"

///
/// \class VXPCard
/// \brief Card class
///
/// The Card class is used to transmit/receive cardholder information.
///
@interface VXPCard : VXPBase
        
///
/// \brief Track 1 data
///
/// Clear text swiped track 1 data.
///
@property (retain, nonatomic) NSString *Track1Data;

///
/// \brief Track 2 data
///
/// Clear text swiped track 2 data.
///
@property (retain, nonatomic) NSString *Track2Data;

///
/// \brief Track 3 data
///
/// Clear text swiped track 3 data.
///
@property (retain, nonatomic) NSString *Track3Data;

///
/// \brief Magneprint data
///
/// Raw output of certain devices directly supported by Express.
/// 
@property (retain, nonatomic) NSString *MagneprintData;

///
/// \brief Card number
///
/// Manually keyed account number. If this field is used,
/// ExpirationMonth and ExpirationYear must be used.
///
/// \sa ExpirationMonth, ExpirationYear
///
@property (retain, nonatomic) NSString *CardNumber;

///
/// \brief Card number masked
///
/// The masked account number returned from Express.
///
@property (retain, nonatomic) NSString *CardNumberMasked;

///
/// \brief Truncated card number
///
/// Truncated card number.
///
@property (retain, nonatomic) NSString *TruncatedCardNumber;

///
/// \brief Expiration month
///
/// Manually keyed expiration month. This field is used along
/// with CardNumber and ExpirationYear.
///
/// \sa CardNumber, ExpirationYear
///
@property (retain, nonatomic) NSString *ExpirationMonth;

///
/// \brief Expiration year
///
/// Manually keyed expiration year. This field is used along
/// with CardNumber and ExpirationMonth.
///
/// \sa CardNumber, ExpirationMonth
///
@property (retain, nonatomic) NSString *ExpirationYear;

///
/// \brief Card holder name
///
/// The name of the card holder as printed on the front of the card.
///
@property (retain, nonatomic) NSString *CardholderName;

///
/// \brief Card verification value
///
/// Card verification value found on the card.
///
@property (retain, nonatomic) NSString *CVV;

///
/// \brief Card authentication verification value
///
/// Card authentication verification value.
///
@property (retain, nonatomic) NSString *CAVV;

///
/// \brief Verified by Visa
///
/// Verified by Visa value.
///
@property (retain, nonatomic) NSString *XID;

///
/// \brief Encrypted PIN block
///
/// Encrypted PIN block information sent from the PIN encryption device.
///
@property (retain, nonatomic) NSString *PINBlock;

///
/// \brief PIN key serial number
///
/// PIN key serial number.
///
@property (retain, nonatomic) NSString *KeySerialNumber;

///
/// \brief The EMV data.
///
@property (retain, nonatomic) NSString *EMVData;

///
/// \brief Encrypted format
///
/// The format of the encrypted EMV data.
///
/// \sa EncryptedEMVData, EMVDataKeySerialNumber
///
@property (nonatomic) VXPEncryptedEmvFormat EncryptedEMVFormat;

///
/// \brief Encrypted EMV data.
///
/// \sa EncryptedEmvFormat, EMVDataKeySerialNumber
///
@property (retain, nonatomic) NSString *EncryptedEMVData;

///
/// \brief Encrypted EMV data key serial number.
///
/// \sa EncryptedEMVData, EncryptedEmvFormat
///
@property (retain, nonatomic) NSString *EMVDataKeySerialNumber;

///
/// \brief Encrypted soft POS data.
///
@property (retain, nonatomic) NSString *EncryptedSoftPOSData;

///
/// \brief Encrypted format
///
/// The format of the encrypted card data.
///
/// \sa EncryptedTrack1Data, EncryptedTrack2Data, EncryptedCardData, CardDataKeySerialNumber
///
@property (nonatomic) VXPCardEncryptedFormat EncryptedFormat;

///
/// \brief Encrypted track 1 data
///
/// Encrypted swiped track 1 data.
///
/// \sa EncryptedFormat, CardDataKeySerialNumber
///
@property (retain, nonatomic) NSString *EncryptedTrack1Data;

///
/// \brief Encrypted track 2 data
///
/// Encrypted swiped track 2 data.
///
/// \sa EncryptedFormat, CardDataKeySerialNumber
///
@property (retain, nonatomic) NSString *EncryptedTrack2Data;

///
/// \brief Encrypted manually keyed card data
///
/// Encrypted manually keyed card data.
///
/// \sa EncryptedFormat, CardDataKeySerialNumber
///
@property (retain, nonatomic) NSString *EncryptedCardData;

///
/// \brief Encrypted card data key serial number
///
/// Encrypted card data key serial number.
///
/// \sa EncryptedTrack1Data, EncryptedTrack2Data, EncryptedCardData
///
@property (retain, nonatomic) NSString *CardDataKeySerialNumber;

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
/// \brief Card authentication verification value response code
///
/// Card authentication verification value response code.
///
@property (retain, nonatomic) NSString *CAVVResponseCode;

///
/// \brief Card logo
///
/// Brand of the card. Possible values include: Visa, Mastercard, Discover, Amex, Diners Club, JCB, Carte Blanche, Other.
///
@property (retain, nonatomic) NSString *CardLogo;

///
/// \brief Gift card security code
///
/// Gift card security code
///
@property (retain, nonatomic) NSString *GiftCardSecurityCode;

///
/// \brief Alternate Card Number 1
///
/// Source card number 1 (non encrypted)
///
@property (retain, nonatomic) NSString *AlternateCardNumber1;

///
/// \brief Alternate Card Number 2
///
/// Source card number 2 (non encrypted)
///
@property (retain, nonatomic) NSString *AlternateCardNumber2;

///
/// \brief Alternate Card Number 3
///
/// Source card number 3 (non encrypted)
///
@property (retain, nonatomic) NSString *AlternateCardNumber3;

///
/// \brief Card number BIN
///
/// The card number BIN returned from Express.
///
@property (retain, nonatomic) NSString *BIN;


@end

#endif /* VXPCard_h */
