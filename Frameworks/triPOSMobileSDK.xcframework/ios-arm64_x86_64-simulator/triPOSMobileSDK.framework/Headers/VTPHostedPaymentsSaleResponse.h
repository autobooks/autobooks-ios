///
/// \file VTPHostedPaymentsSaleResponse.h
///

#ifndef VTPHostedPaymentsSaleResponse_h
#define VTPHostedPaymentsSaleResponse_h
@class VTPSaleResponse;

///
/// \class VTPHostedPaymentsSaleResponse
///
/// \brief The definition of the hosted payments sale response
///
@interface VTPHostedPaymentsSaleResponse: NSObject

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
/// \brief Processes the Hosted Payments Sale Response from the returned URL
///
/// This method accepts the Return URL from Hosted Payments for parsing.
/// \return A Sale Response object representing the parsed hosted payments data
///
-(VTPSaleResponse *)processHostedPaymentsSaleResponse:(NSURL *)url;

@end

#endif /* VTPHostedPaymentsSaleResponse_h */
