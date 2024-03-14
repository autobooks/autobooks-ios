//
//  VHTDeviceTokenHost.h
//  triPOSMobileSDK
//

#ifndef VHTDeviceTokenHost_h
#define VHTDeviceTokenHost_h

#import "VHTTokenProvider.h"
#import "VHTTokenType.h"
#import "VTPHostConfiguration.h"
#import "VXP.h"

@protocol  VHTDeviceTokenHost

@optional

@property (retain, nonatomic) NSString *applicationId;

@property (retain, nonatomic) NSString *applicationName;

@property (retain, nonatomic) NSString *applicationVersion;

@property (retain, nonatomic) NSString *accountId;

@property (retain, nonatomic) NSString *accountToken;

@property (retain, nonatomic) NSString *acceptorId;

@property (retain, nonatomic) NSString *merchantName;

@property (retain, nonatomic) NSString *terminalProfileId;

@required

@property (nonatomic) BOOL testCertification;

@property (retain, nonatomic) NSURL *overrideUrl;

+(BOOL)doesImplementTokenProvider:(NSNumber *)tokenProvider tokenType:(NSNumber *)tokenType;

-(instancetype)initWithTokenProvider:(NSNumber *)tokenProvider tokenType:(NSNumber *)tokenType;

+(NSObject<VHTDeviceTokenHost> *)tokenHostWithTokenProvider:(NSNumber *)tokenProvider tokenType:(NSNumber *)tokenType;

typedef void (^VHTTokenCompletionHandler)(id token);

typedef void (^VHTTokenErrorHandler)(NSError *error);

-(void)sendRequestWithCompletionHandler:(VHTTokenCompletionHandler)completionHandler errorHandler:(VHTTokenErrorHandler)errorHandler;

@end

@interface VHTDeviceTokenHost : NSObject

@property (readonly) VHTTokenProvider tokenProvider;
    
@property (readonly) VHTTokenType tokenType;
    
@property (readonly) NSString *token;

-(instancetype)initWithTokenProvider:(NSNumber *)tokenProvider tokenType:(NSNumber *)tokenType;

@end

#endif /* VHTDeviceTokenHost_h */
