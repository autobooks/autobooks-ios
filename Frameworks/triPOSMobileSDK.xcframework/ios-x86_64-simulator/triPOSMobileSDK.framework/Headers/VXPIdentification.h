#if VXPPHASE > 1

#ifndef VXPIdentification_h
#define VXPIdentification_h

#import "VXPBase.h"

///
/// \file VXPIdentification.h
///

///
/// \class VXPIdentification
/// \brief Identification class
///
/// This class is used to pass identification information.
///
@interface VXPIdentification : VXPBase
        
///
/// \brief Tax ID number
///
/// Social security number or tax ID, no dashes.
///
@property (retain, nonatomic) NSString *TaxIDNumber;

///
/// \brief Drivers license number
///
/// Drivers license number.
///
@property (retain, nonatomic) NSString *DriversLicenseNumber;

///
/// \brief Drivers license state
///
/// Two digit indicator of the state where the drivers license was issued.
///
@property (retain, nonatomic) NSString *DriversLicenseState;

///
/// \brief Birth date
///
/// Birth date formatted YYYYMMDD.
///
@property (retain, nonatomic) NSString *BirthDate;

@end

#endif /* VXPIdentification_h */

#endif      //end of VXPPHASE > 1
