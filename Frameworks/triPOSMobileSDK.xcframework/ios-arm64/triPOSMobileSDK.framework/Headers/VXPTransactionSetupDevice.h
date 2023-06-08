///
/// \file VXPTransactionSetupDevice.h
///

#ifndef VXPTransactionSetupDevice_h
#define VXPTransactionSetupDevice_h

///
/// \enum VXPTransactionSetupDevice
///
typedef enum _VXPTransactionSetupDevice
{
    /// This field is not used
    VXPTransactionSetupDeviceNotSet = VXPEnumNotSet,
    /// Default
    VXPTransactionSetupDeviceDefault = 0,
    /// MagTek encrypted swipe
    VXPTransactionSetupDeviceMagtekEncryptedSwipe,
    /// Encrypted input device (reserved for future use)
    VXPTransactionSetupDeviceEncryptedInputDevice,
}   VXPTransactionSetupDevice;

#endif /* VXPTransactionSetupDevice_h */
