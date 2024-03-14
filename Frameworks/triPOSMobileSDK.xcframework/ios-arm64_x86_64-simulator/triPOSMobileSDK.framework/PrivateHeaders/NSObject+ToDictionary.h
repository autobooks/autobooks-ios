///
/// \file NSObject+ToDictionary.h
///

#ifndef NSObject_ToDictionary_h
#define NSObject_ToDictionary_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSObject(ToDictionary)

-(NSDictionary *)toDictionary;

-(NSDictionary *)toDictionary:(NSArray<NSString *> *)propertiesToExclude;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSObject_ToDictionary_h */
