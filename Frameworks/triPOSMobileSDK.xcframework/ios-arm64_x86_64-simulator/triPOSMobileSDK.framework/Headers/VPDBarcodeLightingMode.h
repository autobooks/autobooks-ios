///
/// \file VPDBarcodeLightingMode.h
///

#ifndef VPDBarcodeLightingMode_h
#define VPDBarcodeLightingMode_h

///
/// \enum VPDBarcodeLightingMode
///
typedef enum _VPDBarcodeLightingMode
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDBarcodeLightingModeMinimum,
#endif
    
    /// Shorter exposure
    VPDBarcodeLightingModeShorterExposure = _VPDBarcodeLightingModeMinimum,
    
    /// Longer exposure
    VPDBarcodeLightingModeLongerExposure,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDBarcodeLightingModeMaximum
#endif
}   VPDBarcodeLightingMode;

#endif /* VPDBarcodeLightingMode_h */
