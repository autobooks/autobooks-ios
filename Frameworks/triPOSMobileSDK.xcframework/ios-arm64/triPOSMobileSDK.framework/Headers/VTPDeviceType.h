///
/// \file VTPDeviceType.h
///

#ifndef VTPDeviceType_h
#define VTPDeviceType_h

///
/// \enum VTPDeviceType
///
typedef enum _VTPDeviceType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPDeviceTypeMinimum,
#endif
    
    /// Null device
    VTPDeviceTypeNull = _VTPDeviceTypeMinimum,

#if !TRIPOS_TTP_SDK
    
    /// Ingenico RBA
    VTPDeviceTypeIngenicoRba,
    
    /// Ingenico RBA TCP/IP
    VTPDeviceTypeIngenicoRbaTcpIp,
    
    /// Ingenico UPP
    VTPDeviceTypeIngenicoUpp,
    
    /// Ingenico UPP TCP/IP
    VTPDeviceTypeIngenicoUppTcpIp,
    
    /// Ingenico Moby Bluetooth
    VTPDeviceTypeIngenicoMobyBluetooth,
    
    /// Ingenico Moby USB
    VTPDeviceTypeIngenicoMobyUSB,

#endif
    /// Apple Tap to Pay on iPhone
    VTPDeviceTypeAppleTapToPay,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPDeviceTypeMaximum
#endif
}   VTPDeviceType;

#endif /* VTPDeviceType_h */
