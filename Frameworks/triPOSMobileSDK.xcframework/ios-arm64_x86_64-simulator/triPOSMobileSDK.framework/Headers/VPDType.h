///
/// \file VPDType.h
///

#ifndef VPDType_h
#define VPDType_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

typedef enum _VPDType
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDTypeMinimum,
#endif
    
    /// Null
    VPDTypeNull = _VPDTypeMinimum,

#if !TRIPOS_TTP_SDK
    
    /// Ingenico RBA
    VPDTypeIngenicoRba,
    
    /// Ingenico RBA, TCP/IP
    VPDTypeIngenicoRbaTcpIp,
    
    // Ingenico UPP
    VPDTypeIngenicoUpp,
    
    /// Ingenico UPP, TCP/IP
    VPDTypeIngenicoUppTcpIp,    
    
    /// Ingenico Moby Bluetooth
    VPDTypeIngenicoMobyBluetooth,
    
    /// Ingenico Moby USB
    VPDTypeIngenicoMobyUSB,

#endif
    
    /// Apple Tap to Pay on iPhone
    VPDTypeAppleTapToPay,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDTypeMaximum
#endif
}   VPDType;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDType_h */
