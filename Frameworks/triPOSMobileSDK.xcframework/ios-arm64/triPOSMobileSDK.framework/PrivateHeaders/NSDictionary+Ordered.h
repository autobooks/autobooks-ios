///
/// \file NSDictionary+Ordered.h
///

#ifndef NSDictionary_Ordered_h
#define NSDictionary_Ordered_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface NSDictionary(Ordered)

+(NSDictionary *)orderedDictionaryWithObjectsAndKeys:(id)firstObject, ... NS_REQUIRES_NIL_TERMINATION;

+(NSDictionary *)orderedDictionaryWithObjects:(NSArray *)objects forKeys:(NSArray *)keys;

@property(readonly, copy) NSArray *allOrderedKeys;

@property(readonly, copy) NSArray *allOrderedValues;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* NSDictionary_Ordered_h */
