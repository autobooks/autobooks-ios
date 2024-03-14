///
/// \file VXPPcrtData.h
///

#ifndef VXPPcrtData_h
#define VXPPcrtData_h

#import "VXPBase.h"

///
/// \class VXPPcrtData
/// \brief Payment card reader token class
///
/// The payment card reader token class is used to retrieve a token from Express to enable the card reader.
///
@interface VXPPcrtData : VXPBase
        
///
/// \brief Terminal profile ID
///
/// The optional ID of the payment card reader PcrtData profile. If this value is not supplied, the profile associated with the merchant profile is used.
///
@property (retain, nonatomic) NSString *TerminalProfileID;

///
/// \brief Merchant banner name
///
/// The optional name of the merchant displayed when card input is requested. The maximum lenght of this property is 110.
///
@property (retain, nonatomic) NSString *MerchantBannerName;

///
/// \brief Time to live seconds
///
/// The optional number of seconds for which the payment card reader PcrtData is valid. If this value is not specified, 48 hours (172800 seconds) is used.
///
@property (retain, nonatomic) NSNumber *TimeToLiveSeconds;

///
/// \brief Payment card reader token
///
/// The payment card reader token.
///
@property (retain, nonatomic) NSString *Token;

@end

#endif /* VXPPcrtData_h */
