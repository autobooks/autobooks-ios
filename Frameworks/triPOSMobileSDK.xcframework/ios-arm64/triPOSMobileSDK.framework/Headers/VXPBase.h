///
/// \file VXPBase.h
///

#ifndef VXPBase_h
#define VXPBase_h

#import <Foundation/Foundation.h>

#import "VXPBooleanType.h"

///
/// \class VXPBase
/// \brief Base class
///
/// All other Express classes are derived from this class.
/// This class should not be used directly.
///
@interface VXPBase : NSObject

#ifndef DOXYGEN_SHOULD_SKIP_THIS
-(NSDate *)dateFromStrings:(NSString *)date time:(NSString *)time;

-(NSDate *)dateFromStrings:(NSString *)date time:(NSString *)time timezone:(NSString *)timezone;

-(NSArray *)dateToStrings:(NSDate *)dateTime;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VXPBase_h */
