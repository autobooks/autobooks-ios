///
/// \file VTPSecurityCodeStatus.h
///

#ifndef VTPSecurityCodeStatus_h
#define VTPSecurityCodeStatus_h

///
/// \enum VTPSecurityCodeStatus
///
/// Security code statuses
///
typedef enum _VTPSecurityCodeStatus
{
    /// Not provided
    VTPSecurityCodeStatusNotProvided,
    /// Provided
    VTPSecurityCodeStatusProvided,
    /// Illegible
    VTPSecurityCodeStatusIllegible,
}   VTPSecurityCodeStatus;

#endif /* VTPSecurityCodeStatus_h */
