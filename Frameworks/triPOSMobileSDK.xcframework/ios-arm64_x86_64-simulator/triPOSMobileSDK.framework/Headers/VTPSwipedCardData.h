///
/// \file VTPSwipedCardData.h
///

#ifndef VTPSwipedCardData_h
#define VTPSwipedCardData_h

#import "VTPCardData.h"

///
/// \class VTPSwipedCardData
///
/// \brief The swiped card data class
///
/// The swiped card data class.
///
@interface VTPSwipedCardData : VTPCardData

///
/// \brief Track 1 data
///
/// Track 1 data including sentinels and checksum.
///
@property (nonatomic, retain) NSString *track1;

///
/// \brief Track 2 data
///
/// Track 2 data including sentinels and checksum.
///
@property (nonatomic, retain) NSString *track2;

@end

#endif /* VTPSwipedCardData_h */
