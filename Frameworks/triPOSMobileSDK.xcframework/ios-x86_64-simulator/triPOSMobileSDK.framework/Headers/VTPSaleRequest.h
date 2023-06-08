///
/// \file VTPSaleRequest.h
///

#ifndef VTPSaleRequest_h
#define VTPSaleRequest_h

#import "VTPFinancialRequestBase.h"
#import "VTPFinancialRequestAmounts.h"
#import "VTPFinancialRequestConvenienceFeeAmount.h"
#import "VTPFinancialRequestTipAmount.h"
#import "VTPAddressRequest.h"
#import "VTPGiftProgramRequest.h"
#import "VTPPINlessPOSConversionRequest.h"
#import "VTPFinancialRequestFoodStampsAmount.h"
#import "VTPHealthcareRequestAmounts.h"

///
/// \class VTPSaleRequest
///
/// \brief The definition for a sale request
///
@interface VTPSaleRequest : NSObject <VTPFinancialRequestBase, VTPFinancialRequestAmounts,VTPFinancialRequestFoodStampsAmount,VTPFinancialRequestConvenienceFeeAmount, VTPFinancialRequestTipAmount, VTPAddressRequest, VTPGiftProgramRequest, VTPPINlessPOSConversionRequest, VTPHealthcareRequestAmounts>

@end

#endif /* VTPSaleRequest_h */
