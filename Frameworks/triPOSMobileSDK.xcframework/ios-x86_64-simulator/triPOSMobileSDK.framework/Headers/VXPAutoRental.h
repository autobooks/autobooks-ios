#if VXPPHASE > 1
///
/// \file VXPAutoRental.h
///

#ifndef VXPAutoRental_h
#define VXPAutoRental_h

#import "VXPBase.h"
#import "VXPAutoRentalNoShowIndicator.h"

///
/// \class VXPAutoRental
/// \brief Auto rental class
///
/// The AutoRental class is requred for auto rental industry transactions and
/// is used to identify auto rental transaction details. This methods is used
/// on the TSYS and FDC platforms only.
///
@interface VXPAutoRental : VXPBase
        
///
/// \brief Auto rental agreement number
///
/// Auto rental agreement number
///
@property (retain, nonatomic) NSString *AutoRentalAgreementNumber;

///
/// \brief Auto rental no show indicator
///
/// Auto rental no show indicator
///
@property (nonatomic) VXPAutoRentalNoShowIndicator AutoRentalNoShowIndicator;

///
/// \brief Auto rental extra charges detail
///
/// Auto rental extra charges detail. This field may contain up to 6 of the following values:
/// <table>
/// <tr>
/// <td width='25%'>0</td>
/// <td>No extra charge</td>
/// </tr>
/// <tr>
/// <td width='25%'>1</td>
/// <td>Gasoline</td>
/// </tr>
/// <tr>
/// <td width='25%'>2</td>
/// <td>Extra mileage</td>
/// </tr>
/// <tr>
/// <td width='25%'>3</td>
/// <td>Late return</td>
/// </tr>
/// <tr>
/// <td width='25%'>4</td>
/// <td>One way service</td>
/// </tr>
/// <tr>
/// <td width='25%'>5</td>
/// <td>Parking or moving violation</td>
/// </tr>
/// </table>
///
@property (retain, nonatomic) NSString *AutoRentalExtraChargesDetail;

///
/// \brief Auto rental pickup date
///
/// Auto rental pickup date. The format is YYYYMMDD.
///
@property (retain, nonatomic) NSString *AutoRentalPickupDate;

///
/// \brief Auto rental dropoff date
///
/// Auto rental dropoff date. The format is YYYYMMDD.
///
@property (retain, nonatomic) NSString *AutoRentalDropoffDate;

///
/// \brief Auto rental customer name
///
/// Auto rental customer name.
///
@property (retain, nonatomic) NSString *AutoRentalCustomerName;

///
/// \brief Auto rental return city
///
/// Auto rental return city.
///
@property (retain, nonatomic) NSString *AutoRentalReturnCity;

///
/// \brief Auto rental return state.
///
/// Auto rental return state.
///
@property (retain, nonatomic) NSString *AutoRentalReturnState;

///
/// \brief Auto rental return location ID
///
/// Auto rental return location ID.
///
@property (retain, nonatomic) NSString *AutoRentalReturnLocationID;

///
/// \brief Auto rental duration
///
/// Auto rental duration in days.
///
@property (retain, nonatomic) NSString *AutoRentalDuration;

///
/// \brief Auto rental pickup location
///
/// Auto rental pickup location.
///
@property (retain, nonatomic) NSString *AutoRentalPickupLocation;

///
/// \brief Auto rental pickup city
///
/// Auto rental pickup city.
///
@property (retain, nonatomic) NSString *AutoRentalPickupCity;

///
/// \brief Auto rental pickup state
///
/// Auto rental pickup state.
///
@property (retain, nonatomic) NSString *AutoRentalPickupState;

///
/// \brief Auto rental pickup country code
///
/// Auto rental pickup country code.
///
@property (retain, nonatomic) NSString *AutoRentalPickupCountryCode;

///
/// \brief Auto rental pickup time
///
/// Auto rental pickup time. The format is HHMMSS.
///
@property (retain, nonatomic) NSString *AutoRentalPickupTime;

///
/// \brief Auto rental return country code
///
/// Auto rental return country code.
///
@property (retain, nonatomic) NSString *AutoRentalReturnCountryCode;

///
/// \brief Auto rental return date
///
/// Auto rental return date. The format is YYYMMDD.
///
@property (retain, nonatomic) NSString *AutoRentalReturnDate;

///
/// \brief Auto rental return time.
///
/// Auto rental return time. The format is HHMMSS.
///
@property (retain, nonatomic) NSString *AutoRentalReturnTime;

///
/// \enum VXPAutoRentalVehicleClassCode
///
typedef enum _VXPAutoRentalVehicleClassCode
    {
    /// This field is not used.
    VXPAutoRentalVehicleClassCodeNotSet = VXPEnumNotSet,
    /// Unused
    VXPAutoRentalVehicleClassCodeUnused = 0,
    /// Mini
    VXPAutoRentalVehicleClassCodeMini,
    /// Subcompact
    VXPAutoRentalVehicleClassCodeSubcompact,
    /// Economy
    VXPAutoRentalVehicleClassCodeEconomy,
    /// Compact
    VXPAutoRentalVehicleClassCodeCompact,
    /// Mid size
    VXPAutoRentalVehicleClassCodeMidsize,
    /// Intermediate
    VXPAutoRentalVehicleClassCodeIntermediate,
    /// Standard
    VXPAutoRentalVehicleClassCodeStandard,
    /// Full size
    VXPAutoRentalVehicleClassCodeFullsize,
    /// Luxary
    VXPAutoRentalVehicleClassCodeLuxury,
    /// Premium
    VXPAutoRentalVehicleClassCodePremium,
    /// Minivan
    VXPAutoRentalVehicleClassCodeMinivan,
    /// Van, 12 passenger
    VXPAutoRentalVehicleClassCodeVan12Passenger,
    /// Van, moving
    VXPAutoRentalVehicleClassCodeMovingVan,
    /// Van, 15 passenger
    VXPAutoRentalVehicleClassCodeVan15Passenger,
    /// Van, cargo
    VXPAutoRentalVehicleClassCodeCargoVan,
    /// Truck, 12 foot
    VXPAutoRentalVehicleClassCodeTruck12Foot,
    /// Truck, 20 foot
    VXPAutoRentalVehicleClassCodeTruck20Foot,
    /// Truck, 24 foot
    VXPAutoRentalVehicleClassCodeTruck24Foot,
    /// Truck, 26 foot
    VXPAutoRentalVehicleClassCodeTruck26Foot,
    /// Moped
    VXPAutoRentalVehicleClassCodeMoped,
    /// Stretch
    VXPAutoRentalVehicleClassCodeStretch,
    /// Regular
    VXPAutoRentalVehicleClassCodeRegular,
    /// Unique
    VXPAutoRentalVehicleClassCodeUnique,
    /// Exotic
    VXPAutoRentalVehicleClassCodeExotic,
    /// Truck, small engine
    VXPAutoRentalVehicleClassCodeTruckSmallMedium,
    /// Truck, large
    VXPAutoRentalVehicleClassCodeTruckLarge,
    /// SUV, small
    VXPAutoRentalVehicleClassCodeSUVSmall,
    /// SUV, medium
    VXPAutoRentalVehicleClassCodeSUVMedium,
    /// SUV, large
    VXPAutoRentalVehicleClassCodeSUVLarge,
    /// SUV, exotic
    VXPAutoRentalVehicleClassCodeSUVExotic,
    /// Four-wheel drive
    VXPAutoRentalVehicleClassCodeFourWheelDrive,
    /// Special
    VXPAutoRentalVehicleClassCodeSpecial,
    // Miscellaneous
    VXPAutoRentalVehicleClassCodeMiscellaneous,
    }   VXPAutoRentalVehicleClassCode;

///
/// \brief Auto rental vehicle class code
///
/// Auto rental class code.
///
@property (nonatomic) VXPAutoRentalVehicleClassCode AutoRentalVehicleClassCode;

///
/// \brief Auto rental distance
///
/// Auto rental distance.
///
@property (retain, nonatomic) NSString *AutoRentalDistance;

///
/// \enum VXPAutoRentalDistanceUnit
///
typedef enum _VXPAutoRentalDistanceUnit
    {
    /// This field is not used
    VXPAutoRentalDistanceUnitNotSet = VXPEnumNotSet,
    /// Miles
    VXPAutoRentalDistanceUnitMiles = 0,
    /// Kilometers
    VXPAutoRentalDistanceUnitKilometers,
    }   VXPAutoRentalDistanceUnit;

///
/// \brief Auto rental distance unit
///
/// Auto rental distance unit.
///
@property (nonatomic) VXPAutoRentalDistanceUnit AutoRentalDistanceUnit;

///
/// \enum VXPAutoRentalAuditAdjustmentCode
///
typedef enum _VXPAutoRentalAuditAdjustmentCode
    {
    /// This field is not used
    VXPAutoRentalAuditAdjustmentCodeNotSet = VXPEnumNotSet,
    /// No adjustments
    VXPAutoRentalAuditAdjustmentCodeNoAdjustments = 0,
    /// Multiple adjustments
    VXPAutoRentalAuditAdjustmentCodeMultipleAdjustments,
    /// One adjustment, card member notified
    VXPAutoRentalAuditAdjustmentCodeOneAdjustmentCardmemberNotified,
    /// One adjustment, card member not notified
    VXPAutoRentalAuditAdjustmentCodeOneAdjustmentCardmemberNotNotified,
    }   VXPAutoRentalAuditAdjustmentCode;

///
/// \brief Auto rental adjustment code
///
/// Auto rental adjustment code.
///
@property (nonatomic) VXPAutoRentalAuditAdjustmentCode AutoRentalAuditAdjustmentCode;

///
/// \brief Auto rental audit adjustment amount
///
/// Auto rental audit adjustment amount.
///
@property (retain, nonatomic) NSDecimalNumber *AutoRentalAuditAdjustmentAmount;

///
/// \brief Auto rental pickup date and time (CONVENIENCE)
///
/// This property accepts/returns an NSDate and sets/gets AutoRentalPickupDate and AutoRentalPickupTime.
/// This property is for convenience and not part of the Express message.
///
/// \sa AutoRentalPickupDate, AutoRentalPickupTime
///
@property (retain, nonatomic, readonly) NSDate *AutoRentalPickupDateTimeEx;

///
/// \brief Auto rental dropoff date and time (CONVENIENCE)
///
/// This property accepts/returns an NSDate and sets/gets AutoRentalDropoffDate.
/// This property is for convenience and not part of the Express message.
/// As Express does not currently define an auto rental dropoff time, the time value is ignored.
///
/// \sa AutoRentalDropoffDate
///
@property (retain, nonatomic, readonly) NSDate *AutoRentalDropoffDateTimeEx;

///
/// \brief Auto rental return date and time (CONVENIENCE)
///
/// This property accepts/returns an NSDate and sets/gets AutoRentalReturnDate and AutoRentalReturnTime.
/// This property is for convenience and not part of the Express message.
///
/// \sa AutoRentalReturnDate, AutoRentalReturnTime
///
@property (retain, nonatomic, readonly) NSDate *AutoRentalReturnDateTimeEx;

@end
#endif      //end of VXPPHASE > 1

#endif /* VXPAutoRental_h */

