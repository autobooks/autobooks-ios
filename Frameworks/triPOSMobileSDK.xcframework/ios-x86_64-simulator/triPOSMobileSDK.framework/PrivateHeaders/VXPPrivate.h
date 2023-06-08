#ifndef VXPPrivate_h
#define VXPPrivate_h

#import <Foundation/Foundation.h>

#import "VXP.h"
#import "VXPBase.h"
#import "XmlDict.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define TOCPP(s)        (((s) == nil) ? nil : [(s) cStringUsingEncoding: NSASCIIStringEncoding])
#define FROMCPP(cpp)    (((cpp) == nil) ? nil : [[NSString alloc] initWithCString: (cpp) encoding: NSASCIIStringEncoding])

#define VXPTransactionDomain             "elementexpress.com"
#define VXPHostedPaymentsDomain          "hostedpayments.com"

/*
 * transaction
 */
#define VXPTransactionServerLive         "transaction"
#define VXPTransactionHostLive           VXPTransactionServerLive "." VXPTransactionDomain
#define VXPTransactionUrlLive            [@"https://" stringByAppendingString: FROMCPP(VXPTransactionHostLive)]

#define VXPTransactionServerCert         "cert" VXPTransactionServerLive
#define VXPTransactionHostCert           VXPTransactionServerCert "." VXPTransactionDomain
#define VXPTransactionUrlCert            [@"https://" stringByAppendingString: FROMCPP(VXPTransactionHostCert)]

#define VXPTransactionNamespace          "https://transaction." VXPTransactionDomain

/*
 * reporting
 */
#define VXPReportingDomain               VXPTransactionDomain

#define VXPReportingServerLive           "reporting"
#define VXPReportingHostLive             VXPReportingServerLive "." VXPReportingDomain
#define VXPReportingUrlLive              [@"https://" stringByAppendingString: FROMCPP(VXPReportingHostLive)]

#define VXPReportingServerCert           "cert" VXPReportingServerLive
#define VXPReportingHostCert             VXPReportingServerCert "." VXPReportingDomain
#define VXPReportingUrlCert              [@"https://" stringByAppendingString: FROMCPP(VXPReportingHostCert)]

#define VXPReportingNamespace            "https://reporting." VXPReportingDomain

/*
 * services
 */
#define VXPServicesDomain                VXPTransactionDomain

#define VXPServicesServerLive            "services"
#define VXPServicesHostLive              VXPServicesServerLive "." VXPServicesDomain
#define VXPServicesUrlLive               [@"https://" stringByAppendingString: FROMCPP(VXPServicesHostLive)]

#define VXPServicesServerCert            "cert" VXPServicesServerLive
#define VXPServicesHostCert              VXPServicesServerCert "." VXPServicesDomain
#define VXPServicesUrlCert               [@"https://" stringByAppendingString: FROMCPP(VXPServicesHostCert)]

#define VXPServicesNamespace             "https://services." VXPServicesDomain

/*
 * hosted payments
 */
#define VXPHostedPaymentsHostCert        VXPTransactionServerCert "." VXPHostedPaymentsDomain "/mobile"
#define VXPHostedPaymentsUrlCert         [@"https://" stringByAppendingString: FROMCPP(VXPHostedPaymentsHostCert)]

#define VXPHostedPaymentsHostLive        VXPTransactionServerLive "." VXPHostedPaymentsDomain
#define VXPHostedPaymentsUrlLive         [@"https://" stringByAppendingString: FROMCPP(VXPHostedPaymentsHostLive)]

#define VXPHostedPaymentsReturnUrl       @"https://localhost/HostedPaymentsResponse"

@interface VXP(Private)

+(NSURL *)getUrlFromRequestType:(VXPRequestType)requestType overrideUrl:(NSURL *)overrideUrl testCertification:(BOOL)testCertification;

-(void)sendRequest:(VXPRequest *)request url:(NSURL *)url timeout:(NSInteger)timeout completionHandler:(VXPCompletionHandler)completionHandler errorHandler:(VXPErrorHandler)errorHandler;

-(void)sendRequest:(VXPRequest *)request url:(NSURL *)url timeout:(NSInteger)timeout autoReversal:(BOOL)autoReversal completionHandler:(VXPCompletionHandler)completionHandler errorHandler:(VXPErrorHandler)errorHandler;

@end

@interface VXPBase()

-(BOOL)exportDict:(NSObject *)parent xml:(VXPXMLDICTHANDLE)xml;

+(VXPBase *)importDict:(NSObject *)parentOrClassName xml:(VXPXMLDICTHANDLE)xml;

@end

@interface VXPResponse()

-(void)setReportingDataEx:(NSArray *)value;

@end

@interface VXPReportingDataItem()

-(void)setTransactionTypeEx:(VXPRequestType)value;

@end

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VXPPrivate_h */

