///
/// \file VTCFinancialTrack2Data.h
///

#ifndef VTCFinancialTrack2Data_h
#define VTCFinancialTrack2Data_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTCFinancialTrackData.h"

///
/// \class VTCFinancialTrack2Data
/// \brief Financial track 2 data class
///
/// This interface provides financial card track 2 parsing functionality.
///
@interface VTCFinancialTrack2Data : NSObject <VTCFinancialTrackData>

///
/// \brief Returns an VTCFinancialTrack2Data object initialized with a string
///
/// Returns an VTCFinancialTrack2Data object initialized with values parsed from the given string.
///
/// \param track2Data A string containing track 2 data.
///
/// \return Returns an VTCFinancialTrack2Data object initialized with a string.
///
-(instancetype)initWithTrack2Data:(NSString *)track2Data;

///
/// \brief Creates and returns an VTCFinancialTrack2Data object initialized with a string
///
/// Creates and returns an VTCFinancialTrack2Data object initialized with values parsed from the given string.
///
/// \param track2Data A string containing track 2 data.
///
/// \return Returns an VTCFinancialTrack2Data object initialized with a string.
///
+(VTCFinancialTrack2Data *)financialTrack2WithTrack2Data:(NSString *)track2Data;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCFinancialTrack2Data_h */
