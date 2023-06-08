///
/// \file VXPTerminalEncryptionFormat.h
///

#ifndef VXPTerminalEncryptionFormat_h
#define VXPTerminalEncryptionFormat_h

///
/// \enum VXPTerminalEncryptionFormat
///
typedef enum _VXPTerminalEncryptionFormat
{
    /// This field is not used
    VXPTerminalEncryptionFormatNotSet = VXPEnumNotSet,
    /// Default, used for standard EPS encryption devices
    VXPTerminalEncryptionFormatDefault = 0,
    /// Format 1, used MagTek devices
    VXPTerminalEncryptionFormat1,
    /// Format 2, used form Ingenico DPP device
    VXPTerminalEncryptionFormat2,
    /// Format 3 used for Ingenico On-Guard devices
    VXPTerminalEncryptionFormat3,
    /// Format 4 used for IDTECH devices
    VXPTerminalEncryptionFormat4,
}   VXPTerminalEncryptionFormat;

#endif /* VXPTerminalEncryptionFormat_h */
