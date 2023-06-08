///
/// \file VTCEnum.h
///

#ifndef VTCEnum_h
#define VTCEnum_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@protocol VTCEnum

@required

+(NSArray<NSString *> *)getNames;

+(NSArray<NSNumber *> *)getValues;

+(NSString *)getNameForValue:(int)value;

+(int)getValueForName:(NSString *)name;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCEnum_h */
