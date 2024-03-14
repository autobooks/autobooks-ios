#if VXPPHASE > 1

#ifndef VXPLodging_h
#define VXPLodging_h

#import "VXPBase.h"
#import "VXPLodgingNoShowIndicator.h"
#import "VXPLodgingPrestigiousPropertyCode.h"
#import "VXPLodgingSpecialProgramCode.h"
#import "VXPLodgingChargeType.h"

///
/// \file VXPLodging.h
///

///
/// \class VXPLodging
/// \brief Lodging class
///
/// This class is used to pass lodging information.
///
@interface VXPLodging : VXPBase
        
///
/// \brief Lodging agreement number
///
/// Hotel folio number.
///
@property (retain, nonatomic) NSString *LodgingAgreementNumber;

///
/// \brief Lodging check-in date
///
/// Check-in date formatted YYYYMMDD.
/// For advance check-in, this is the date of the reservation.
/// For no-show, this is the anticipated arrival date.
///
@property (retain, nonatomic) NSString *LodgingCheckInDate;

///
/// \brief Lodging check-out date
///
/// Check-out date formatted YYYYMMDD.
///
@property (retain, nonatomic) NSString *LodgingCheckOutDate;

///
/// \brief Lodging room amount
///
/// Nightly rate for one room. Must always be greater than 0.00 for a room reservation.
///
@property (retain, nonatomic) NSDecimalNumber *LodgingRoomAmount;

///
/// \brief Lodging room tax
///
/// Reserved for future use.
///
@property (retain, nonatomic) NSString *LodgingRoomTax;

///
/// \brief Lodging no-show indicator
///
/// Indicates a room was reserved, but not actually rented.
///
@property (nonatomic) VXPLodgingNoShowIndicator LodgingNoShowIndicator;

///
/// \brief Lodging duration
///
/// Number of hotel stay days.
///
@property (retain, nonatomic) NSString *LodgingDuration;

///
/// \brief Lodging customer name
///
/// Lodging customer name.
///
@property (retain, nonatomic) NSString *LodgingCustomerName;

///
/// \brief Lodging client code
///
/// Reserved for future use.
///
@property (retain, nonatomic) NSString *LodgingClientCode;

///
/// \brief Lodging extra charges detail
///
/// Lodging extra charges detail. This field may contain up to 6 of the following values:
/// <table>
/// <tr>
/// <td width='25%'>0</td>
/// <td>Not used</td>
/// </tr>
/// <tr>
/// <td width='25%'>1</td>
/// <td>Reserved</td>
/// </tr>
/// <tr>
/// <td width='25%'>2</td>
/// <td>Restaurant</td>
/// </tr>
/// <tr>
/// <td width='25%'>3</td>
/// <td>Gift shop</td>
/// </tr>
/// <tr>
/// <td width='25%'>4</td>
/// <td>Mini-bar</td>
/// </tr>
/// <tr>
/// <td width='25%'>5</td>
/// <td>Telephone</td>
/// </tr>
/// <tr>
/// <td width='25%'>6</td>
/// <td>Other</td>
/// </tr>
/// <tr>
/// <td width='25%'>7</td>
/// <td>Laundry</td>
/// </tr>
/// </table>
///
///
@property (retain, nonatomic) NSString *LodgingExtraChargesDetail;

///
/// \brief Lodging extra charges amounts
///
/// Reserved for future use.
///
@property (retain, nonatomic) NSString *LodgingExtraChargesAmounts;

///
/// \brief Lodging prestigious property code
///
/// Lodging prestigious property code.
///
@property (nonatomic) VXPLodgingPrestigiousPropertyCode LodgingPrestigiousPropertyCode;

///
/// \brief Lodging special program code
///
/// Lodging special program code.
///
@property (nonatomic) VXPLodgingSpecialProgramCode LodgingSpecialProgramCode;

///
/// \brief Lodging charge type
///
/// Lodging charge type.
///
@property (nonatomic) VXPLodgingChargeType LodgingChargeType;

@end

#endif /* VXPLodging_h */

#endif      //end of VXPPHASE > 1
