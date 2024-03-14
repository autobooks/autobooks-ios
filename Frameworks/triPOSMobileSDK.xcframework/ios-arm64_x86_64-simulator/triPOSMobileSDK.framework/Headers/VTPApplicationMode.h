///
/// \file VTPApplicationMode.h
///

#ifndef VTPApplicationMode_h
#define VTPApplicationMode_h

///
/// \enum VTPApplicationMode
///
typedef enum _VTPApplicationMode
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPApplicationModeMinimum,
#endif
    
    /// Production
    VTPApplicationModeProduction = _VTPApplicationModeMinimum,
    
    /// Test/Certification
    VTPApplicationModeTestCertification,

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPApplicationModeMaximum
#endif
    
}   VTPApplicationMode;

#endif /* VTPApplicationMode_h */
