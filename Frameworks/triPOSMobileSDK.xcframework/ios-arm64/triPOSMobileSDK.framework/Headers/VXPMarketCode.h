///
/// \file VXPMarketCode.h
///

#ifndef VXPMarketCode_h
#define VXPMarketCode_h

///
/// \enum VXPMarketCode
///
typedef enum _VXPMarketCode
{
    /// This field is not used
    VXPMarketCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPMarketCodeDefault = 0,
    /// Auto rental
    VXPMarketCodeAutoRental,
    /// Direct marketing
    VXPMarketCodeDirectMarketing,
    /// E-commerce
    VXPMarketCodeECommerce,
    /// Food/restaurant
    VXPMarketCodeFoodRestaurant,
    /// Hotel/lodging
    VXPMarketCodeHotelLodging,
    /// Petroleum
    VXPMarketCodePetroleum,
    /// Retail
    VXPMarketCodeRetail,
    /// QSR
    VXPMarketCodeQSR,
}   VXPMarketCode;

#endif /* VXPMarketCode_h */
