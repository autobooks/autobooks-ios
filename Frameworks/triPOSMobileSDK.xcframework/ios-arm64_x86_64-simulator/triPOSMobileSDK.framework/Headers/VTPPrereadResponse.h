//
//  VTPPrereadResponse.h
//  triPOSMobileSDK
//
//  Created on 24/09/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VTPPaymentType.h"
#import "VTPFinancialResponseCard.h"

///
/// \class VTPPrereadResponse
///
/// \brief The definition of the pre read response
///

@interface VTPPrereadResponse : NSObject <VTPFinancialResponseCard>

///
/// \brief Gets the paymentType
///
/// This property gets the paymentType.
///
@property (nonatomic, assign) VTPPaymentType paymentType;

///
/// \brief Gets whether the PIN was verified
///
/// This property gets whether the PIN was verified.
///
@property (nonatomic) BOOL wasPinVerified;

@end
