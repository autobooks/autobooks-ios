///
///  \file VTPManuallyForwardResponse.h
///

#ifndef VTPManuallyForwardResponse_h
#define VTPManuallyForwardResponse_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialRequestConvenienceFeeAmount.h"
#import "VTPDebitFinancialResponseBase.h"

///
/// \class VTPManuallyForwardResponse
///
/// \brief The definition of the manually forward response
///
@interface VTPManuallyForwardResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPDebitFinancialResponseBase>

@property (retain, nonatomic) NSString *transactionId;

@property (nonatomic) NSObject *response;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPManuallyForwardResponse_h */
