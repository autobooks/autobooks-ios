///
/// \file VXPTerminalEnvironmentCode.h
///

#ifndef VXPTerminalEnvironmentCode_h
#define VXPTerminalEnvironmentCode_h

///
/// \enum VXPTerminalEnvironmentCode
///
typedef enum _VXPTerminalEnvironmentCode
{
    /// This field is not used
    VXPTerminalEnvironmentCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPTerminalEnvironmentCodeDefault = 0,
    /// No terminal
    VXPTerminalEnvironmentCodeNoTerminal,
    /// Local attended
    VXPTerminalEnvironmentCodeLocalAttended,
    /// Local unattended
    VXPTerminalEnvironmentCodeLocalUnattended,
    /// Remote attended
    VXPTerminalEnvironmentCodeRemoteAttended,
    /// Remote unattended
    VXPTerminalEnvironmentCodeRemoteUnattended,
    /// E-commerce
    VXPTerminalEnvironmentCodeECommerce,
}   VXPTerminalEnvironmentCode;

#endif /* VXPTerminalEnvironmentCode_h */
