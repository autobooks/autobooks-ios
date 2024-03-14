///
/// \file NSString+HexToData.h
///

#import <Foundation/Foundation.h>

#ifndef NSString_HexToData_h
#define NSString_HexToData_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSString(HexToData)

-(NSData *)dataFromHexString;

-(NSData *)dataFromHexStringFromOffset:(NSUInteger)offset;

-(NSData *)dataFromHexStringFromOffset:(NSUInteger)offset length:(NSUInteger)length;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSString_HexToData_h */
