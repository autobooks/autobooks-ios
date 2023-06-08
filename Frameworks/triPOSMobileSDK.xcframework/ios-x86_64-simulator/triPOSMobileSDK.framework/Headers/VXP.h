///
/// \file VXP.h
///

#ifndef VXP_h
#define VXP_h

#import "VXPRequest.h"
#import "VXPResponse.h"
#import "VXPResponseType.h"

///
/// \brief the VXP (Express) error domain
///
extern NSString * const VXPErrorDomain;

///
/// \class VXP
/// \brief Provides access to the Express functionality
///
/// This is the main interface to the Express functionality.
///
@interface VXP : NSObject

///
/// \brief Min and Max timout value
///
///  Setting this connection timout min and max value, which can't be set less than 5000ms or greater than 300000ms.
///
@property (nonatomic) NSInteger const VXPRequestTimeoutMin;
@property (nonatomic) NSInteger const VXPRequestTimeoutMax;
///
/// \brief Test/Certification flag
///
/// Setting this flag to YES sends all transactions to the Express test/certification host. Setting this flag to NO sends all transactions to the Express production host.
///
@property (nonatomic) BOOL TestCertification;

///
/// \brief Specifies the maximum retries for an auto reversal in case of a communication issue.
///
/// This property sets the maximum number of retiries for an auto reversal during a communication error with express. Valid values are between 1 and 4.
///
@property (nonatomic) NSUInteger AutoReversalRetryLimit;


///
/// \brief Checks the connection to the Express host
///
/// The host is automatically selected based on the value of TestCertification property.
/// If TestCertification is set to YES, the Express test host is checked for connectivity.
/// If TestCertification is set to NO, the Express production host is checked for connectivity.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)checkConnectionToExpress;

///
/// \brief Checks the connection to the specified host
///
/// This method checks the connectivity of the specified host.
///
/// \param host The fully qualified host name (e.g. certtransaction.elementexpress.com).
///
/// \return YES if successful, NO otherwise.
///
+(BOOL)checkConnectionToHost:(const char *)host;

///
/// \brief Block definition for the completionHandler
///
/// Block definition for the completionHandler parameter of sendRequest.
///
/// \param response The Express response. If a response is not received from Express, this value is undefined.
///
/// \sa sendRequest
///
typedef void (^VXPCompletionHandler)(VXPResponse *response);

///
/// \brief Block definition for the errorHandler
///
/// Block definition for the errorHandler parameter of sendRequest.
///
/// \param error Used if an error occurs while processing the request.
///
/// \sa sendRequest
///
typedef void (^VXPErrorHandler)(NSError *error);

///
/// \brief Sends the request to Express asynchronously
///
/// This method serializes the Express message, sends it to the Express host, receives the response, and deserializes the response.
///
/// \param request The request to send.
///
/// \param timeout The timeout in milliseconds to wait for the response from Express.
///
/// \param completionHandler The handler block executed upon completion.
///
/// \param errorHandler The handler block executed if an error occurs.
///
/// \sa VXPCompletionHandler, VXPErrorHandler
///
-(void)sendRequest:(VXPRequest *)request timeout:(NSInteger)timeout completionHandler:(VXPCompletionHandler)completionHandler errorHandler:(VXPErrorHandler)errorHandler;

///
/// \brief Sends the request to Express asynchronously
///
/// This method serializes the Express message, sends it to the Express host, receives the response, and deserializes the response.
///
/// \param request The request to send.
///
/// \param timeout The timeout in milliseconds to wait for the response from Express.
///
/// \param autoReversal flag that indicates whether a system reversal is generated for a communication error.
///
/// \param completionHandler The handler block executed upon completion.
///
/// \param errorHandler The handler block executed if an error occurs.
///
/// \sa VXPCompletionHandler, VXPErrorHandler
///
-(void)sendRequest:(VXPRequest *)request timeout:(NSInteger)timeout autoReversal:(BOOL)autoReversal completionHandler:(VXPCompletionHandler)completionHandler errorHandler:(VXPErrorHandler)errorHandler;

@end

#endif /* VXP_h */
