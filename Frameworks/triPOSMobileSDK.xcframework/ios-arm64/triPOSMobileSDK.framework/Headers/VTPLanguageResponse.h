//
//  VTPPreferredLanguageResponse.h
//  triPOSMobileSDK
//
//  Created on 9/20/24.
//  Copyright © 2024 Worldpay from FIS. All rights reserved.
//

#import "VTPDeviceLanguage.h"

#ifndef VTPLanguageResponse_h
#define VTPLanguageResponse_h


///
/// \protocol VTPPreferredLanguageResponse
///
/// \brief The protocol that defines the properties returned in all preferred language responses.
///
@protocol VTPLanguageResponse

///
/// \brief Gets the preferred language from the transaction
///
/// This property gets the preferred language from the tranaction.
///
@property (nonatomic) VTPDeviceLanguage language;

@end

#endif /* VTPPreferredLanguageResponse_h */
