///
/// \file NSNumber+StringFormats.h
///

#ifndef NSNumber_StringFormats_h
#define NSNumber_StringFormats_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSNumber(StringFormats)

-(NSString *)getValueFormattedAsCurrency:(NSString *)currencyCode;

-(NSString *)getValueFormattedAsCurrency:(NSString *)currencyCode roundedToWholeNumber:(BOOL)roundedToWholeNumber;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSNumber_StringFormats_h */
