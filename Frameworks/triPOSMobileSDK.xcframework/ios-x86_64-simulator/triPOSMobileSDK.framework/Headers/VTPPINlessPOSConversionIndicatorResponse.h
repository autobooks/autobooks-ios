//
//  VTPPINlessPOSConversionIndicatorResponse.h
//  triPOSMobileSDK
//
//  Created on 3/10/22.
//  Copyright © 2022 Worldpay from FIS. All rights reserved.
//

#ifndef VTPPINlessPOSConversionIndicatorResponse_h
#define VTPPINlessPOSConversionIndicatorResponse_h

///
/// \protocol VTPPINlessPOSConversionIndicatorResponse
///
/// \brief The protocol that defines the properties returned for PINless POS conversion indicator
///
@protocol VTPPINlessPOSConversionIndicatorResponse

///
/// \brief Gets the PINless POS conversion indicator
///
/// This property gets the PINless POS conversion indicator.
///
@property (nonatomic) BOOL pinlessPosConversionIndicator;

@end
#endif /* VTPPINlessPOSConversionIndicatorResponse_h */
