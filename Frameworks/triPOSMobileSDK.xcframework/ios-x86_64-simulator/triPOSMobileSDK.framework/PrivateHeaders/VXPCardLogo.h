//
//  VXPCardLogo.h
//  triPOSMobileSDK
//
//  Created by Doug Sheridan on 6/28/17.
//  Copyright © 2018 Worldpay, LLC. and/or its affiliates. All rights reserved.
//

#ifndef VXPCardLogo_h
#define VXPCardLogo_h

///
/// \enum VXPCardLogo
///
typedef enum _VXPCardLogo
{
    /// Unknown
    VXPCardLogoUnknown = 0,
    /// Visa
    VXPCardLogoVisa = 1,
    /// MasterCard
    VXPCardLogoMasterCard = 2,
    /// Amex
    VXPCardLogoAmex = 3,
    /// Discover
    VXPCardLogoDiscover = 4,
    /// Diners
    VXPCardLogoDiners = 5,
    /// StoredValue
    VXPCardLogoStoredValue = 6,
    /// Other
    VXPCardLogoOther = 7,
    /// JCB
    VXPCardLogoJCB = 8,
    /// CarteBlanche
    VXPCardLogoCarteBlanche = 9,
    /// Interac
    VXPCardLogoInterac = 10,
}   VXPCardLogo;

#endif /* VXPCardLogo_h */
