///
/// \file VXPEnhancedBIN.h
///

#ifndef VXPEnhancedBIN_h
#define VXPEnhancedBIN_h

#import "VXPBase.h"

///
/// \class VXPEnhancedBIN
/// \brief Enhanced BIN class
///
/// The enhanced BIN class is used when performing EnhancedBINQuery requests.
///
@interface VXPEnhancedBIN : VXPBase
        
///
/// \brief Query status
///
/// The query status returned as “Found” or “NotFound” according to whether BIN information is included in the response.
///
@property (retain, nonatomic) NSString *Status;

///
/// \brief Check card indicator.
///
/// The check card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *CheckCard;

///
/// \brief Commercial card indicator.
///
/// The commercial card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *CommercialCard;

///
/// \brief Credit card indicator.
///
/// The credit card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *CreditCard;

///
/// \brief Debit card indicator.
///
/// The debit card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *DebitCard;

///
/// \brief Durbin BIN regulation
///
/// The Durbin BIN regulation returned with integer indicating the type of Durbin regulation for queried card
///
@property (retain, nonatomic) NSString *DurbinBINRegulation;

///
/// \brief EBT indicator.
///
/// The EBT indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *EBT;

///
/// \brief Fleet card indicator.
///
/// The fleet card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *FleetCard;

///
/// \brief Gift card indicator.
///
/// The gift card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *GiftCard;

///
/// \brief HSA/FSA card indicator.
///
/// The HSA/FSA card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *HSAFSACard;

///
/// \brief International BIN indicator.
///
/// The international BIN indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *InternationalBIN;

///
/// \brief PINless bill pay indicator.
///
/// The PINless bill pay indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *PinLessBillPay;

///
/// \brief Prepaid card indicator.
///
/// The prepaid card indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *PrepaidCard;

///
/// \brief WIC indicator.
///
/// The WIC indicator returned with value “Y” if applicable to queried card, otherwise not returned.
///
@property (retain, nonatomic) NSString *WIC;

@end

#endif /* VXPEnhancedBIN_h */
