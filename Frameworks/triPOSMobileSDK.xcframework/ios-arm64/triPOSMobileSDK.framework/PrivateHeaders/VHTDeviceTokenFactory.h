///
/// \file VHTDeviceTokenFactory.h
///

#ifndef VHTDeviceTokenFactory_h
#define VHTDeviceTokenFactory_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VHTDeviceTokenHost.h"
#import "VHTDeviceTokenHostNull.h"
#import "VHTDeviceTokenHostExpress.h"

@interface VHTDeviceTokenFactory : NSObject

+(NSObject<VHTDeviceTokenHost> *)createDeviceTokenHost:(VHTTokenProvider)tokenProvider tokenType:(VHTTokenType)tokenType;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VHTDeviceTokenFactory_h */
