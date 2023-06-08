///
/// \file VXPPASSUpdaterStatus.h
///

#ifndef VXPPASSUpdaterStatus_h
#define VXPPASSUpdaterStatus_h

///
/// \enum VXPPASSUpdaterStatus
///
typedef enum _VXPPASSUpdaterStatus
{
    /// This field is not used
    VXPPASSUpdaterStatusNotSet = VXPEnumNotSet,
    /// Null
    VXPPASSUpdaterStatusNull = 0,
    /// Update in progress
    VXPPASSUpdaterStatusUpdateInProgress,
    /// Match, no changes
    VXPPASSUpdaterStatusMatchNoChanges,
    /// Match, account changed
    VXPPASSUpdaterStatusMatchAccountChange,
    /// Match, expiration date changed
    VXPPASSUpdaterStatusMatchExpirationChange,
    /// Match, account closed
    VXPPASSUpdaterStatusMatchAccountClosed,
    /// Match, contact cardholder
    VXPPASSUpdaterStatusMatchContactCardholder,
    /// No match, participating
    VXPPASSUpdaterStatusNoMatchParticipating,
    /// No match, non-participating
    VXPPASSUpdaterStatusNoMatchNonParticipating,
    /// Invalid information
    VXPPASSUpdaterStatusInvalidInfo,
    /// No response
    VXPPASSUpdaterStatusNoResponse,
    /// Not allowed
    VXPPASSUpdaterStatusNotAllowed,
    /// Error
    VXPPASSUpdaterStatusError,
    /// PASS updater disabled
    VXPPASSUpdaterStatusPASSUpdaterDisabled,
    /// Not updated
    VXPPASSUpdaterStatusNotUpdated,
}   VXPPASSUpdaterStatus;

#endif /* VXPPASSUpdaterStatus_h */
