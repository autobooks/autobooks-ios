///
/// \file VTPSaleResponse.h
///

#ifndef VTPSaleResponse_h
#define VTPSaleResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCashbackAmount.h"
#import "VTPFinancialResponseTipAmount.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseCardVerification.h"
#import "VTPFinancialResponseEmv.h"
#import "VTPFinancialResponseHost.h"
#import "VTPStoreAndForwardResponse.h"
#import "VTPValutecRewardsResponse.h"
#import "VTPPINlessPOSConversionIndicatorResponse.h"
#import "VTPCommercialCardCustomerCodeResponse.h"
#import "VTPDccResponse.h"
#import "VTPFinancialResponseSurchargeAmount.h"
#import "VTPDebitFinancialResponseBase.h"
#import "VTPLanguageResponse.h"


///
/// \class VTPSaleResponse
///
/// \brief The definition of the sale response
///
@interface VTPSaleResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts, VTPFinancialResponseCashbackAmount, VTPFinancialResponseTipAmount,VTPFinancialResponseCard, VTPFinancialResponseCardVerification, VTPFinancialResponseEmv, VTPFinancialResponseHost, VTPStoreAndForwardResponse, VTPValutecRewardsResponse, VTPPINlessPOSConversionIndicatorResponse, VTPDccResponse, VTPFinancialResponseSurchargeAmount, VTPCommercialCardCustomerCodeResponse, VTPDebitFinancialResponseBase, VTPLanguageResponse>

@end

#endif /* VTPSaleResponse_h */
