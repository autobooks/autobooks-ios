///
/// \file VXPEncryptedEmvFormat.h
///

#ifndef VXPEncryptedEmvDataFormat_h
#define VXPEncryptedEmvDataFormat_h

///
/// \enum VXPEncryptedEmvFormat
///
/// Encrypted EMV format values
///
typedef enum _VXPEncryptedEmvFormat
{
    /// This field is not used
    VXPEncryptedEmvFormatNotSet = VXPEnumNotSet,
    /// Default, currently does nothing.
    VXPEncryptedEmvFormatDefault = 0,
    /// Format 1, used for Form Agent/XPI devices.
    VXPEncryptedEmvFormat1,
    /// Format 2, used for Mercury Vx805 devices.
    VXPEncryptedEmvFormat2,
    /// Format 3, used for devices that only output data variant encrypted track 2 data for EMV.
    VXPEncryptedEmvFormat3,
    /// Format 4, used for MagTek-Ziosk devices.
    VXPEncryptedEmvFormat4,
    /// Format 3, used for Equinox L5xxx devices.
    VXPEncryptedEmvFormat5,
    /// Format 4, used for Apple Tap to Pay or other soft POS/tap on COTS formats.
    VXPEncryptedEmvFormat6,
}   VXPEncryptedEmvFormat;

#endif /* VXPEncryptedEmvDataFormat_h */
