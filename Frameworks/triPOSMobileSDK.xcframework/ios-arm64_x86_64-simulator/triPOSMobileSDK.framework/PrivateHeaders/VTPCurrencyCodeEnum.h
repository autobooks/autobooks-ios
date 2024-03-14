///
/// \file VTPCurrencyCodeEnum.h
///

#ifndef VTPCurrencyCodeEnum_h
#define VTPCurrencyCodeEnum_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPCurrencyCode.h"
#import "VTCEnum.h"

@interface VTPCurrencyCodeEnum : NSObject <VTCEnum>

+(NSArray<NSNumber *> *)getIso4217Codes;

+(NSString *)getIso4217CodeForValue:(int)value;

+(int)getValueForIso4217Code:(NSString *)name;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPCurrencyCode_h */
