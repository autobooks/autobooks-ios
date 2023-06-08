///
/// \file NSData+HexString.h
///

#ifndef NSData_HexString_h
#define NSData_HexString_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSData(HexString)

-(NSString *)toHexString;

-(NSString *)toHexStringWithSpaces:(BOOL)withSpaces;

-(NSString *)toHexStringFromOffset:(NSUInteger)offset length:(NSUInteger)length withSpaces:(BOOL)withSpaces;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSData_HexString_h */
