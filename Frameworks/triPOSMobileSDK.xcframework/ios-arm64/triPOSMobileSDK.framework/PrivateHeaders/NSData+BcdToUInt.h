///
/// \file NSData+BcdToUInt.h
///

#ifndef NSData_BcdToUInt_h
#define NSData_BcdToUInt_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSData(BcdToUInt)

-(unsigned short)bcdToUint16;

-(unsigned short)bcdToUint16FromOffset:(NSUInteger)offset;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSData_BcdToUInt_h */
