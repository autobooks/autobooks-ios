///
/// \file NSString+Split.h
///

#ifndef NSString_Split_h
#define NSString_Split_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import <Foundation/Foundation.h>

@interface NSString(Split)

-(NSArray<NSString *> *)componentsSeparatedByString:(NSString *)separator withMaximumCount:(NSUInteger)count;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSString_Split_h */
