#if VXPPHASE > 1

#import "VXPBase.h"
#import "VXPScheduledTaskRunFrequency.h"
#import "VXPScheduledTaskStatus.h"

#ifndef VXPScheduledTask_h
#define VXPScheduledTask_h

///
/// \file VXPScheduledTask.h
///

///
/// \class VXPScheduledTask
/// \brief Scheduled task class
///
/// The scheduled task class us used to schedule transactions.
///
@interface VXPScheduledTask : VXPBase
        
///
/// \brief Scheduled task ID
///
/// Unique value that identifies the scheduled task. The Express platform generates this.
///
@property (retain, nonatomic) NSString *ScheduledTaskID;

///
/// \brief Scheduled task run log ID
///
/// Run log ID of the scheduled task.
///
@property (retain, nonatomic) NSString *ScheduledTaskRunLogID;

///
/// \brief Scheduled task group ID
///
/// Group ID of the scheduled task. The Express platform generates this.
///
@property (retain, nonatomic) NSString *ScheduledTaskGroupID;

///
/// \brief Scheduled task name
///
/// User generated name of the scheduled task.
///
@property (retain, nonatomic) NSString *ScheduledTaskName;

///
/// \brief Scheduled task reference number
///
/// User generated reference number used to identify a scheduled task.
///
@property (retain, nonatomic) NSString *ScheduledTaskReferenceNumber;

///
/// \brief Run frequency
///
/// Specifies how often an event should occur.
///
@property (nonatomic) VXPScheduledTaskRunFrequency RunFrequency;

///
/// \brief Run start date
///
/// The start date.
/// The format of this property is YYYYMMDD
///
@property (retain, nonatomic) NSString *RunStartDate;

///
/// \brief Run until cancel flag
///
/// If this flag is set to trud the task will run every scheduled time until the task is deleted by the user.
///
@property (nonatomic) VXPBooleanType RunUntilCancelFlag;

///
/// \brief run cycles
///
/// Number of times this task should run. This property is only required when RunUntilCancelFlag is set to false.
///
/// \sa RunUntilCancelFlag
///
@property (retain, nonatomic) NSString *RunCycles;

///
/// \brief Scheduled task status
///
/// The status of the task.
///
@property (nonatomic) VXPScheduledTaskStatus ScheduledTaskStatus;

@end

#endif /* VXPScheduledTask_h */

#endif      //end of VXPPHASE > 1
