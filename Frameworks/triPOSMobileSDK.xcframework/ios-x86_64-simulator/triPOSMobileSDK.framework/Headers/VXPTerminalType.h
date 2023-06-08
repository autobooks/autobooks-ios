///
/// \file VXPTerminalType.h
///

#ifndef VXPTerminalType_h
#define VXPTerminalType_h

///
/// \enum VXPTerminalType
///
typedef enum _VXPTerminalType
{
    /// This field is not used
    VXPTerminalTypeNotSet = VXPEnumNotSet,
    /// Unknown
    VXPTerminalTypeUnknown = 0,
    /// Point-of-sale
    VXPTerminalTypePointOfSale,
    /// E-commerce
    VXPTerminalTypeECommerce,
    /// Mail/telephone order
    VXPTerminalTypeMoto,
    /// Fuel pump
    VXPTerminalTypeFuelPump,
    /// ATM
    VXPTerminalTypeAtm,
    /// Voice
    VXPTerminalTypeVoice,
    /// Mobile
    VXPTerminalTypeMobile
}   VXPTerminalType;

#endif /* VXPTerminalType_h */
