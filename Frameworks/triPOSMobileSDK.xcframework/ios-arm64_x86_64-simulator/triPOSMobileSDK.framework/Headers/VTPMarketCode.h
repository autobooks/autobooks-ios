///
/// \file VTPMarketCode.h
///

#ifndef VTPMarketCode_h
#define VTPMarketCode_h

///
/// \enum VTPMarketCode
///
typedef enum _VTPMarketCode
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPMarketCodeMinimum,
#endif
    
    /// Auto rental
    VTPMarketCodeAutoRental = _VTPMarketCodeMinimum,
    
    /// Direct marketing
    VTPMarketCodeDirectMarketing,
    
    /// e-Commerce
    VTPMarketCodeECommerce,
    
    /// Food/restaruant
    VTPMarketCodeFoodRestaurant,
    
    /// Hotel lodging
    VTPMarketCodeHotelLodging,
    
    /// Petroleum
    VTPMarketCodePetroleum,
    
    /// Retail
    VTPMarketCodeRetail,
    
    /// QSR
    VTPMarketCodeQsr,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPMarketCodeMaximum
#endif
}   VTPMarketCode;

#endif /* VTPMarketCode_h */
