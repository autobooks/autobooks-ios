///
/// \file VTPAddressVerificationCondition.h
///

#ifndef VTPAddressVerificationCondition_h
#define VTPAddressVerificationCondition_h

///
/// \enum VTPAddressVerificationCondition
///
typedef enum _VTPAddressVerificationCondition
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPAddressVerificationConditionMinimum,
#endif
    
    /// Never
    VTPAddressVerificationConditionNever = _VTPAddressVerificationConditionMinimum,
    
    /// Always
    VTPAddressVerificationConditionAlways,

    /// Keyed
    VTPAddressVerificationConditionKeyed,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPAddressVerificationConditionMaximum
#endif
    
}   VTPAddressVerificationCondition;

#endif /* VTPAddressVerificationCondition_h */
