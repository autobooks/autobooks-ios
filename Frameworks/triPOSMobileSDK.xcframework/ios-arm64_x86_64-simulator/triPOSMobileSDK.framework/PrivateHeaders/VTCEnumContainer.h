///
/// \file VTCEnumContainer.h
///

#ifndef VTCEnumContainer_h
#define VTCEnumContainer_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTCEnum.h"

@protocol VTCEnumContainer

@required

+(NSArray<NSString *> *)getNamesForEnumName:(NSString *)enumName;

+(NSArray<NSNumber *> *)getValuesForEnumName:(NSString *)enumName;

+(NSString *)getNameForEnumName:(NSString *)enumName forValue:(int)value;

+(int)getValueForEnumName:(NSString *)enumName forName:(NSString *)name;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCEnumContainer_h */
