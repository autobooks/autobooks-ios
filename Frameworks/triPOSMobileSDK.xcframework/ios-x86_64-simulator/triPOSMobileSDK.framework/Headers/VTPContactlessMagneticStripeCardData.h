///
/// \file VTPContactlessMagneticStripeCardData.h
///

#ifndef VTPContactlessMagneticStripeCardData_h
#define VTPContactlessMagneticStripeCardData_h

#import "VTPSwipedCardData.h"

///
/// \class VTPContactlessMagneticStripeCardData
///
/// \brief The contactless magnetic stripe card data class
///
/// The contactless magnetic stripe card data class.
///
@interface VTPContactlessMagneticStripeCardData : VTPSwipedCardData

#ifndef DOXYGEN_SHOULD_SKIP_THIS

-(instancetype)initWithSwipedCardData:(VTPSwipedCardData *)swipedCardData;

+(VTPContactlessMagneticStripeCardData *)contactlessMagneticStripeCardDataWithSwipedCardData:(VTPSwipedCardData *)swipedCardData;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPContactlessMagneticStripeCardData_h */
