///
/// \file VTCTlvUtility.h
///

#ifndef VTCTlvUtility_h
#define VTCTlvUtility_h

#import "VTCEmvTag.h"

typedef NSDictionary<NSNumber *, NSData *> * VTCTlvCollection;

typedef NSMutableDictionary<NSNumber *, NSData *> * VTCMutableTlvCollection;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

extern NSString * const VTCTlvUtilityException;

@interface VTCTlvUtility : NSObject

+(VTCTlvCollection)parseTlvData:(NSData *)tlvData;

+(VTCTlvCollection)parseTlvData:(NSData *)tlvData offset:(NSUInteger)offset;

+(VTCTlvCollection)parseTlvData:(NSData *)tlvData offset:(NSUInteger)offset length:(NSUInteger)length;

+(NSData *)getTlvTagBytes:(VTCEmvTag)tag;

+(NSData *)getTlvBytes:(VTCEmvTag)tag byteValue:(unsigned char)byteValue;

+(NSData *)getTlvBytes:(VTCEmvTag)tag value:(NSData *)value;

+(void)logTlvCollection:(VTCTlvCollection)tlvCollection;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCTlvUtlity_h */
