///
/// \file VXPTerminalCapabilityCode.h
///

#ifndef VXPTerminalCapabilityCode_h
#define VXPTerminalCapabilityCode_h

///
/// \enum VXPTerminalCapabilityCode
///
typedef enum _VXPTerminalCapabilityCode
{
    /// This field is not used
    VXPTerminalCapabilityCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPTerminalCapabilityCodeDefault = 0,
    /// Unknown
    VXPTerminalCapabilityCodeUnknown,
    /// No terminal
    VXPTerminalCapabilityCodeNoTerminal,
    /// Magnetic stripe reader
    VXPTerminalCapabilityCodeMagstripeReader,
    /// Contactless card reader
    VXPTerminalCapabilityCodeContactlessMagstripeReader,
    /// Key entered
    VXPTerminalCapabilityCodeKeyEntered,
    /// Contact ICC reader.
    VXPTerminalCapabilityCodeChipReader,
    /// Contactless ICC reader.
    VXPTerminalCapabilityCodeContactlessChipReader,
}   VXPTerminalCapabilityCode;

#endif /* VXPTerminalCapabilityCode_h */
