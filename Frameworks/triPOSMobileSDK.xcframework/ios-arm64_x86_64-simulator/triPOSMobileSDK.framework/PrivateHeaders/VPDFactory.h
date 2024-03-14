///
/// \file VPDFactory.h
///

#ifndef VPDFactory_h
#define VPDFactory_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDDevice.h"
#import "VPDNull.h"
#import "VPDType.h"

@interface VPDFactory : NSObject

+(NSObject<VPDDevice> *)createDevice:(VPDType)type;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDFactory_h */
