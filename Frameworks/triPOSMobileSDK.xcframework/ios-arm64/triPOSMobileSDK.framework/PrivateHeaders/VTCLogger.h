//
//  \file VTCLogger.h
//

#import <Foundation/Foundation.h>

#ifndef VTCLogger_h
#define VTCLogger_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifdef __cplusplus
extern "C" {
#endif

#define NSLog(args...) VTCLog(__FILE__,__LINE__,__PRETTY_FUNCTION__,args);

void VTCLog(const char *file, int lineNumber, const char *functionName, NSString *format, ...);

#ifdef __cplusplus
}
#endif
    
    
@interface VTCLogger : NSObject

@property (retain, nonatomic, readonly) NSArray<NSString *> *logFileList;
@property (class) NSString *identifier;

+(NSString *) getLogIdentifier;
+(void) resetLogIdentifier;

+(void)error:(NSString *)message;
+(void)warn:(NSString *)message;
+(void)info:(NSString *)message;
+(void)debug:(NSString *)message;
+(void)verbose:(NSString *)message;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCLogger_h */
