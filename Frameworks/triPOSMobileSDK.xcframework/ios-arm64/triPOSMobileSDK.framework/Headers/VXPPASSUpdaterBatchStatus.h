///
/// \file VXPPASSUpdaterBatchStatus.h
///

#ifndef VXPPASSUpdaterBatchStatus_h
#define VXPPASSUpdaterBatchStatus_h

///
/// \enum VXPPASSUpdaterBatchStatus
///
typedef enum _VXPPASSUpdaterBatchStatus
{
    /// This field is not used
    VXPPASSUpdaterBatchStatusNotSet = VXPEnumNotSet,
    /// Null
    VXPPASSUpdaterBatchStatusNull = 0,
    /// Included in next batch
    VXPPASSUpdaterBatchStatusIncludedInNextBatch,
    /// Not included in next batch
    VXPPASSUpdaterBatchStatusNotIncludedInNextBatch,
}   VXPPASSUpdaterBatchStatus;

#endif /* VXPPASSUpdaterBatchStatus_h */
