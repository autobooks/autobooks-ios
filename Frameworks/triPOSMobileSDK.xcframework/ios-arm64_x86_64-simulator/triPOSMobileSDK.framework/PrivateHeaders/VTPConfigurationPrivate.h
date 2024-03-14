///
/// \file VTPConfigurationPrivate.h
///

#ifndef VTPConfigurationPrivate_h
#define VTPConfigurationPrivate_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTCEnumContainer.h"

@protocol VTPConfigurationPrivate

@required

-(BOOL)validateConfiguration:(NSError **)error;

@end

@interface VTPConfigurationPrivate : NSObject

+(BOOL)validateConfiguration:(id)configuration name:(NSString *)name error:(NSError **)error;

+(BOOL)errorIfStringPropertyIsNilOrEmpty:(NSString *)value name:(NSString *)name error:(NSError **)error;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPConfigurationPrivate_h */
