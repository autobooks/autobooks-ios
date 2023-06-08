///
/// \file VXPTerminalPinCapability.h
///

#ifndef VXPTerminalPinCapability_h
#define VXPTerminalPinCapability_h

///
/// \enum VXPTerminalPinCapability
///
typedef enum _VXPTerminalPinCapability
{
    /// This field is not used
    VXPTerminalPinCapabilityNotSet = VXPEnumNotSet,
    /// Default
    VXPTerminalPinCapabilityDefault = 0,
    /// PIN Capable
    VXPTerminalPinCapable, // 1
    /// Not PIN Capable
    VXPTerminalNotPinCapable, // 2
}   VXPTerminalPinCapability;

#endif /* VXPTerminalPinCapability_h */
