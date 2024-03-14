///
/// \file VTPTerminalType.h
///

#ifndef VTPTerminalType_h
#define VTPTerminalType_h

///
/// \enum VTPTerminalType
///
typedef enum _VTPTerminalType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPTerminalTypeMinimum,
#endif
    
    /// Unknown
    VTPTerminalTypeUnknown = _VTPTerminalTypeMinimum,
    /// Point-of-sale
    VTPTerminalTypePointOfSale,
    /// E-commerce
    VTPTerminalTypeECommerce,
    /// Mail/telephone order
    VTPTerminalTypeMoto,
    /// Fuel pump
    VTPTerminalTypeFuelPump,
    /// ATM
    VTPTerminalTypeAtm,
    /// Voice
    VTPTerminalTypeVoice,
    /// Mobile
    VTPTerminalTypeMobile,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPTerminalTypeMaximum
#endif
}   VTPTerminalType;

#endif /* VTPTerminalType_h */
