///
/// \file VTPRefundRequest.h
///

#ifndef VTPRefundRequest_h
#define VTPRefundRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPFinancialRequestConvenienceFeeAmount.h"
#import "VTPAddressRequest.h"
#import "VTPGiftProgramRequest.h"
#import "VTPPINlessPOSConversionRequest.h"
#import "VTPFinancialRequestFoodStampsAmount.h"
///
/// \class VTPRefundRequest
///
/// \brief The definition for a refund request
///
@interface VTPRefundRequest : NSObject <VTPFinancialRequestBase, VTPFinancialRequestAmounts, VTPFinancialRequestFoodStampsAmount, VTPFinancialRequestConvenienceFeeAmount, VTPAddressRequest, VTPGiftProgramRequest, VTPPINlessPOSConversionRequest>

@end

#endif /* VTPRefundRequest_h */
