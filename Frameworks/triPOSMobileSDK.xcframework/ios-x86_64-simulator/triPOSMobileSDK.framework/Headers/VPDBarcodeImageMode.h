///
/// \file VPDBarcodeImageMode.h
///

#ifndef VPDBarcodeImageMode_h
#define VPDBarcodeImageMode_h

///
/// \enum VPDBarcodeImageMode
///
typedef enum _VPDBarcodeImageMode
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDBarcodeImageModeMinimum,
#endif
    
    /// 1D mode
    VPDBarcodeImageMode1D = _VPDBarcodeImageModeMinimum,
    
    /// 2D mode
    VPDBarcodeImageMode2D,
    
    /// 2D mode for a bright environment
    VPDBarcodeImageMode2DForBrightEnvironment,
    
    /// 2D mode for shiny/reflective surfaces
    VPDBarcodeImageMode2DForShinySurfaces,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDBarcodeImageModeMaximum
#endif
}   VPDBarcodeImageMode;

#endif /* VPDBarcodeImageMode_h */
