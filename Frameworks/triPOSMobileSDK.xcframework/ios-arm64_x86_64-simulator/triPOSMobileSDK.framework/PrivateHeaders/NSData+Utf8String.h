///
/// \file NSData+Utf8String.h
///

#ifndef NSData_Utf8String_h
#define NSData_Utf8String_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSData(Utf8String)

-(NSString *)toUtf8String;

-(NSString *)toUtf8StringFromOffset:(NSUInteger)offset;

-(NSString *)toUtf8StringFromOffset:(NSUInteger)offset length:(NSUInteger)length;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSData_Utf8String_h */
