///
/// \file VPDCardInputCapability.h
///

#ifndef VPDCardInputCapability_h
#define VPDCardInputCapability_h

///
/// \enum VPDCardInputCapability
///
typedef enum _VPDCardInputCapability
{
    /// None
    VPDCardInputCapabilityNone                          = 0x0000,
    /// Keyed card data
    VPDCardInputCapabilityKeyed                         = 0x0001,
    /// Magnetic stripe card data
    VPDCardInputCapabilityMagneticStripe                = 0x0002,
    /// Contactless magnetstripe data (MSD)
    VPDCardInputCapabilityContactlessMagneticStripe     = 0x0004,
    /// Contact integrated circuit card (ICC)
    VPDCardInputCapabilityContactIcc                    = 0x0008,
    /// Contactless integrated circuit card (ICC)
    VPDCardInputCapabilityContactlessIcc                = 0x0010,
}   VPDCardInputCapability;

#endif /* VPDCardInputCapability_h */
