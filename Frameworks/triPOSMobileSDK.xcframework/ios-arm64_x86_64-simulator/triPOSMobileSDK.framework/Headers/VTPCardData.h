///
/// \file VTPCardData.h
///

#ifndef VTPCardData_h
#define VTPCardData_h

#import <Foundation/Foundation.h>

///
/// \class VTPCardData
///
/// \brief The base card data class
///
/// The base card data class.
///
@interface VTPCardData : NSObject

-(instancetype)initWithJsonDictionary:(NSDictionary *)jsonDictionary;

@end

#endif /* VTPCardData_h */
