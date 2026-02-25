///
///  \file VTPManuallyForwardRequest.h
///

#ifndef VTPManuallyForwardRequest_h
#define VTPManuallyForwardRequest_h

#import "VTPFinancialRequestAmounts.h"
#import "VTPFinancialRequestConvenienceFeeAmount.h"
#import "VTPFinancialRequestSurchargeAmount.h"

///
/// \class VTPManuallyForwardRequest
///
/// \brief The definition for an manually forward transaction request
///
@interface VTPManuallyForwardRequest : NSObject <VTPFinancialRequestAmounts, VTPFinancialRequestConvenienceFeeAmount, VTPFinancialRequestSurchargeAmount>

@property (nonatomic, retain) NSString *tpId;

@end

#endif /* VTPManuallyForwardRequest_h */
