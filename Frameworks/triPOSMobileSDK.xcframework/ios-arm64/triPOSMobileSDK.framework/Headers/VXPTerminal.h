///
/// \file VXPTerminal.h
///

#ifndef VXPTerminal_h
#define VXPTerminal_h

#import "VXPBase.h"
#import "VXPCardHolderPresentCode.h"
#import "VXPCardInputCode.h"
#import "VXPCardPresentCode.h"
#import "VXPConsentCode.h"
#import "VXPCVVPresenceCode.h"
#import "VXPCVVResponseType.h"
#import "VXPMotoECICode.h"
#import "VXPTerminalCapabilityCode.h"
#import "VXPTerminalEncryptionFormat.h"
#import "VXPTerminalEnvironmentCode.h"
#import "VXPTerminalType.h"
#import "VXPTerminalPinCapability.h"
    
///
/// \class VXPTerminal
///
/// \brief Terminal class
///
/// The terminal class identifies characteristics of the payment device used.
///
@interface VXPTerminal : VXPBase

///
/// \brief Gets or sets the terminal ID
///
/// This property gets or sets the terminal ID. The terminal ID is a unique identifier assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *TerminalID;

///
/// \brief Gets or sets the terminal type
///
/// This property gets or sets the termainl type.
///
@property (nonatomic) VXPTerminalType TerminalType;

///
/// \brief Gets or sets the card present code
///
/// This propert gets or sets the card present code which specifies the location of the card at the time of the transaction.
///
@property (nonatomic) VXPCardPresentCode CardPresentCode;

///
/// \brief Gets or sets the cardholder present code
///
/// This property gets or sets the card holder present code which is the location of the cardholder at the time of the transaction.
///
@property (nonatomic) VXPCardHolderPresentCode CardholderPresentCode;

///
/// \brief Gets or sets the card input code
///
/// This property gets or sets the card input code which is the means by which the card number or track data was acquired.
///
@property (nonatomic) VXPCardInputCode CardInputCode;

///
/// \brief Gets or sets the CVV presence code
///
/// This property gets or sets the CVV presence code or the reason why it could not be obtained.
///
@property (nonatomic) VXPCVVPresenceCode CVVPresenceCode;

///
/// \brief Gets or sets the terminal capability code
///
/// This property gets or sets the terminal capability code.
///
@property (nonatomic) VXPTerminalCapabilityCode TerminalCapabilityCode;

///
/// \brief Gets or sets the terminal environment code
///
/// This property gets or sets the terminal environement code which specifies whether a payment terminal is used or the environment in which the terminal is installed.
///
@property (nonatomic) VXPTerminalEnvironmentCode TerminalEnvironmentCode;

///
/// \brief Gets or sets the MOTO/ECI code
///
/// This property gets or sets the MOTO/ECI code which is used for mail/telephone order or e-commerce transactions to identify the type of transaction and the means by which it was obtained.
///
@property (nonatomic) VXPMotoECICode MotoECICode;

///
/// \brief Gets or sets the CVV response type
///
/// This property gets or sets the CVV response type.
///
@property (nonatomic) VXPCVVResponseType CVVResponseType;

///
/// \brief Gets or sets the consent code
///
/// This property gets or sets the consent code.
///
@property (nonatomic) VXPConsentCode ConsentCode;

///
/// \brief Gets or sets the terminal serial number
///
/// This property gets or sets the terminal serial number.
///
@property (retain, nonatomic) NSString *TerminalSerialNumber;

///
/// \brief Gets or sets the terminal encryption format
///
/// This property gets or sets the terminal encryption format.
///
@property (nonatomic) VXPTerminalEncryptionFormat TerminalEncryptionFormat;

///
/// \brief Gets or sets the lane number
///
/// This property gets or sets the lane number.
///
@property (retain, nonatomic) NSString *LaneNumber;

///
/// \brief Gets or sets EMV kernel version
///
/// This property gets or sets EMV kernel version.
///
@property (retain, nonatomic) NSString *TerminalEMVKernelVersion;

///
/// \brief Gets or sets the terminal model
///
/// This property gets or sets the terminal model.
///
@property (retain, nonatomic) NSString *TerminalModel;

///
/// \brief Gets or sets the Store Card ID
///
/// This property gets or sets the Store Card ID.
///
@property (retain, nonatomic) NSString *StoreCardID;

///
/// \brief Gets or sets the Store Card password
///
/// This property gets or sets the Store Card password.
///
@property (retain, nonatomic) NSString *StoreCardPassword;

///
/// \brief Gets or sets the terminal capability code
///
/// This property gets or sets the terminal capability code.
///
@property (nonatomic) VXPTerminalPinCapability TerminalPinCapability;

///
/// \brief Gets the soft POS ID
///
/// This property gets the soft POS ID.
///
@property (retain, nonatomic, readonly) NSString *SoftPOSID;

@end

#endif /* VXPTerminal_h */
