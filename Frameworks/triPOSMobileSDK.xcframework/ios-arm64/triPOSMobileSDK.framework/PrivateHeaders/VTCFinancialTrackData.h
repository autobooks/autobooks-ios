///
/// \file VTCFinancialTrackData.h
///

#ifndef VTCFinancialTrackData_h
#define VTCFinancialTrackData_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTCFinancialTrackDataParseStatus.h"


///
/// \def VTCMaximumTrack1
/// \brief Maximum track 1 length
///
/// The maximum allowed length for track 1 data.
///
#define VTCMaximumTrack1DataLength              79

///
/// \def VTCMaximumTrack2
/// \brief Maximum track 2 length
///
/// The maximum allowed length for track 2 data.
///
#define VTCMaximumTrack2DataLength              40

///
/// \def VTCMaximumAccountNumber
/// \brief Maximum account number length
///
/// The maximum allowed length for the primary account number.
///
#define VTCMaximumAccountNumberLength           19

///
/// \def VTCMaximumExpirationDate
/// \brief Maximum expiration data length
///
/// The maximum allowed length for the expiration date.
///
#define VTCMaximumExpirationDateLength          4

///
/// \def VTCMaximumName
/// \brief Maximum name length
///
/// The maximum allowed length for the track 1 name.
///
#define VTCMaximumNameLength                    26

///
/// \def VTCMaximumServiceCode
/// \brief Maximum service code length
///
/// The maximum allowed length for service code data.
///
#define VTCMaximumServiceCodeLength             3

///
/// \def VTCMaximumDiscretionaryData
/// \brief Maximum discretionary data
///
/// The maximum allowed length for discretionary data.
///
#define VTCMaximumDiscretionaryDataLength       21

///
/// \brief Track 1 start sentinel
///
/// The standard value that indicates the start of track 1 data.
///
extern NSString * const VTCFinancialTrack1DataStartSentinel;

///
/// \brief Track 1 end sentinel
///
/// The standard value that indicates the end of track 1 data.
///
extern NSString * const VTCFinancialTrack1DataEndSentinel;

///
/// \brief Track 1 separator
///
/// The standard value that separates track 1 data fields.
///
extern NSString * const VTCFinancialTrack1DataSeparator;

///
/// \brief Track 2 start sentinel
///
/// The standard value that indicates the start of track 2 data.
///
extern NSString * const VTCFinancialTrack2DataStartSentinel;

///
/// \brief Track 2 end sentinel
///
/// The standard value that indicates the end of track 2 data.
///
extern NSString * const VTCFinancialTrack2DataEndSentinel;

///
/// \brief Track 2 separator
///
/// The standard value that separates track 2 data fields.
///
extern NSString * const VTCFinancialTrack2DataSeparator;


///
/// \protocol VTCFinancialTrackData
/// \brief Financial track 2 data class
///
/// This interface provides financial card track 2 parsing functionality.
///
@protocol VTCFinancialTrackData

///
/// \brief Parse error
///
/// The result of parsing the track data.
///
@property (nonatomic) VTCFinancialTrackDataParseStatus parseStatus;

///
/// \brief Track data, no sentinels
///
/// Track data excluding sentinels and checksum.
///
@property (nonatomic, retain) NSString *trackDataWithoutSentinels;

///
/// \brief Account number
///
/// Account number for this card data. This property is masked if the card data is encrypted.
///
@property (nonatomic, retain) NSString *accountNumber;

///
/// \brief Expiration date
///
/// Expiration date for this card data. This property may be masked if the card data is encrypted.
///
@property (nonatomic, retain) NSString *expirationDate;

/// \brief Service code
///
/// The service code parsed from this track data.
///
@property (nonatomic, retain) NSString *serviceCode;

///
/// \brief Discretionary data
///
/// The discretionary data parsed from this track data.
///
@property (nonatomic, retain) NSString *discretionaryData;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCFinancialTrackData_h */
