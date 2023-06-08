///
/// \file NSString+Masked.h
///

#ifndef NSString_Masked_h
#define NSString_Masked_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSString(Masked)

-(NSString *)stringByMaskingWithMask:(unichar)mask beginClearCount:(NSUInteger)beginClearCount endClearCount:(NSUInteger)endClearCount;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSString_Masked_h */
