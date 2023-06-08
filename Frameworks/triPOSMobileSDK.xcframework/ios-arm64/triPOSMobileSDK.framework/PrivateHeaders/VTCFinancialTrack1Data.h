///
/// \file VTCFinancialTrack1Data.h
///

#ifndef VTCFinancialTrack1Data_h
#define VTCFinancialTrack1Data_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTCFinancialTrackData.h"

///
/// \class VTCFinancialTrack1Data
/// \brief Financial track 2 data class
///
/// This interface provides financial card track 2 parsing functionality.
///
@interface VTCFinancialTrack1Data : NSObject <VTCFinancialTrackData>

///
/// \brief Name
///
/// The name parsed from this track data.
///
@property (nonatomic, retain) NSString *name;

///
/// \brief Returns an VTCFinancialTrack1Data object initialized with a string
///
/// Returns an VTCFinancialTrack1Data object initialized with values parsed from the given string.
///
/// \param track1Data A string containing track 2 data.
///
/// \return Returns an VTCFinancialTrack1Data object initialized with a string.
///
-(instancetype)initWithTrack1Data:(NSString *)track1Data;

///
/// \brief Creates and returns an VTCFinancialTrack1Data object initialized with a string
///
/// Creates and returns an VTCFinancialTrack1Data object initialized with values parsed from the given string.
///
/// \param track1Data A string containing track 2 data.
///
/// \return Returns an VTCFinancialTrack1Data object initialized with a string.
///
+(VTCFinancialTrack1Data *)financialTrack1WithTrack1Data:(NSString *)track1Data;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCFinancialTrack1Data_h */
