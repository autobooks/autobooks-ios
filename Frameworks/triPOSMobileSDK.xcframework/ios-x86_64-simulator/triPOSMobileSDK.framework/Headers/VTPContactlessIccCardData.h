///
/// \file VTPContactlessIccCardData.h
///

#ifndef VTPContactlessIccCardData_h
#define VTPContactlessIccCardData_h

#import "VTPIccCardData.h"
#import "VTCTlvUtility.h"

///
/// \class VTPContactlessIccCardData
///
/// \brief The contactless ICC card data class
///
/// The contactless ICC card data class.
///
@interface VTPContactlessIccCardData : VTPIccCardData

#ifndef DOXYGEN_SHOULD_SKIP_THIS

+(VTPContactlessIccCardData *)contactlessIccCardDataWithTags:(VTCTlvCollection)tags;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPContactlessIccCardData_h */
