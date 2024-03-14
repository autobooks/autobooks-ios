//
//  VTPDccResponse.h
//  triPOSMobileSDK
//
//  Created on 26/06/23.
//  Copyright © 2021 Vantiv Inc. All rights reserved.
//

#ifndef VTPDccResponse_h
#define VTPDccResponse_h

///
/// \protocol VTPDccResponse
///
/// \brief The protocol that defines the properties returned in all financial responses
///
@protocol VTPDccResponse

///
/// \brief Gets the foreign transaction amount
///
/// This property gets the foreign transaction amount.
///
@property (retain, nonatomic) NSString *foreignTransactionAmount;

///
/// \brief Gets the foreign currency code
///
/// This property gets the foreign currency code.
///
@property (retain, nonatomic) NSString *foreignCurrencyCode;

///
/// \brief Gets the conversion rate
///
/// This property gets the conversion rate.
///
@property (retain, nonatomic) NSString *conversionRate;

@end
#endif /* VTPDccResponse_h */



