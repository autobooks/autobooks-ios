///
/// \file NSString+IsNilOrWhiteSpace.h
///

#ifndef NSString_IsNilOrWhiteSpace_h
#define NSString_IsNilOrWhiteSpace_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSString(IsNilOrWhiteSpace)

+(BOOL)isNil:(NSString *)string;

+(BOOL)isEmpty:(NSString *)string;

+(BOOL)isWhiteSpace:(NSString *)string;

+(BOOL)isNilOrWhiteSpace:(NSString *)string;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSString_IsNilOrWhiteSpace_h */
