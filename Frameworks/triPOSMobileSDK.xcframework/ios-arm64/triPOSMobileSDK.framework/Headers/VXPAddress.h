///
/// \file VXPAddress.h
///

#ifndef VXPAddress_h
#define VXPAddress_h

#import "VXPBase.h"

///
/// \class VXPAddress
///
/// \brief Address class
///
/// Provides access to Express address information.
///
@interface VXPAddress : VXPBase

///
/// \brief Billing name
///
/// The name used for billing purposes.
///
@property (retain, nonatomic) NSString *BillingName;

///
/// \brief Billing address 1
///
/// The street address used for billing purposes.
///
@property (retain, nonatomic) NSString *BillingAddress1;

///
/// \brief Billing address 2
///
/// The street address used for billing purposes.
///
@property (retain, nonatomic) NSString *BillingAddress2;

///
/// \brief Billing city
///
/// The name of the city used for billing purposes.
///
@property (retain, nonatomic) NSString *BillingCity;

///
/// \brief Billing state
///
/// The name of the state used for billing purposes. This value may be any two character state code or the full state name.
///
@property (retain, nonatomic) NSString *BillingState;

///
/// \brief Billing ZIP code
///
/// The ZIP code used for billing purposes.
///
@property (retain, nonatomic) NSString *BillingZipcode;

///
/// \brief Billing e-mail
///
/// The e-mail address used for billing purposes.
///
@property (retain, nonatomic) NSString *BillingEmail;

///
/// \brief Billing phone
///
/// The phone number used for billing purposes. The recommended format is (###)###-####.
///
@property (retain, nonatomic) NSString *BillingPhone;

///
/// \brief Shipping name
///
/// The name used for shipping purposes.
///
@property (retain, nonatomic) NSString *ShippingName;

///
/// \brief Shipping address 1
///
/// The street address used for shipping purposes.
///
@property (retain, nonatomic) NSString *ShippingAddress1;

///
/// \brief Shipping address 2
///
/// The street address used for shipping purposes.
///
@property (retain, nonatomic) NSString *ShippingAddress2;

///
/// \brief Shipping city
///
/// The name of the city used for shipping purposes.
///
@property (retain, nonatomic) NSString *ShippingCity;

///
/// The name of the state used for shipping purposes. This value may be any two character state code or the full state name.
///
@property (retain, nonatomic) NSString *ShippingState;

///
/// \brief Shipping ZIP code
///
/// The ZIP code used for shipping purposes.
///
@property (retain, nonatomic) NSString *ShippingZipcode;

///
/// \brief Shipping e-mail
///
/// The e-mail address used for shipping purposes.
///
@property (retain, nonatomic) NSString *ShippingEmail;

///
/// \brief Shipping phone
///
/// The phone number used for shipping purposes. The recommended format is (###)###-####
///
@property (retain, nonatomic) NSString *ShippingPhone;

@end

#endif /* VXPAddress_h */

