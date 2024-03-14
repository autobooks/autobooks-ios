///
/// \file VTPHostedPaymentsAuthorizationResponse.h
///

#ifndef VTPHostedPaymentsAuthorizationResponse_h
#define VTPHostedPaymentsAuthorizationResponse_h
@class VTPAuthorizationResponse;

///
/// \class VTPHostedPaymentsAuthorizationResponse
///
/// \brief The definition of the hosted payments authorization response
///
@interface VTPHostedPaymentsAuthorizationResponse : NSObject

///
/// \brief Gets transactionSetupID
///
/// This property contains a transactionSetupID from express.
///
@property (retain, nonatomic) NSString *transactionSetupID;

///
/// \brief Gets the hostedPaymentsURL.
///
/// This property contains the hostedPaymentsURL from express.
///
@property (retain, nonatomic) NSURL *hostedPaymentsURL;

///
/// \brief Processes the Hosted Payments Authorization Response from the returned URL
///
/// This method accepts the Return URL from Hosted Payments for parsing.
/// \return \return A Authorizaton Response object representing the parsed hosted payments data
///
-(VTPAuthorizationResponse *)processHostedPaymentsAuthorizationResponse:(NSURL *)url;

@end

#endif /* VTPHostedPaymentsAuthorizationResponse_h */
