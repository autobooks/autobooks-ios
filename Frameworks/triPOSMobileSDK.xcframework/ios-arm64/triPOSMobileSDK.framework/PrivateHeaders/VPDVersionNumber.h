///
/// \file VPDVersionNumber.h
///

#ifndef VPDVersionNumber_h
#define VPDVersionNumber_h

#import <Foundation/Foundation.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface VPDVersionNumber : NSObject

@property (nonatomic, retain) NSString *versionString;
@property (nonatomic, assign) NSInteger majorVersion;
@property (nonatomic, assign) NSInteger minorVersion;
@property (nonatomic, assign) NSInteger microVersion;
@property (nonatomic, assign) NSInteger buildNumber;

-(instancetype) initWithVersionNumber:(NSString*) versionString;

-(NSComparisonResult)compare:(VPDVersionNumber*)other;

@end


#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDVersionNumber_h */

