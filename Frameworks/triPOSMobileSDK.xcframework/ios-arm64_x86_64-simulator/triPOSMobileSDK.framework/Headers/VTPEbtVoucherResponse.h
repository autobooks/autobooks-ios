///
/// \file VTPEbtVoucherResponse.h
///

#ifndef VTPEbtVoucherResponse_h
#define VTPEbtVoucherResponse_h

#import "VTPFinancialResponseBase.h"
#import "VTPFinancialResponseAmounts.h"
#import "VTPFinancialResponseCashbackAmount.h"
#import "VTPFinancialResponseTipAmount.h"
#import "VTPFinancialResponseCard.h"
#import "VTPFinancialResponseCardVerification.h"
#import "VTPFinancialResponseEmv.h"
#import "VTPFinancialResponseHost.h"
#import "VTPStoreAndForwardResponse.h"

///
/// \class VTPEbtVoucherResponse
///
/// \brief The definition of the sale response
///
@interface VTPEbtVoucherResponse : NSObject <VTPFinancialResponseBase, VTPFinancialResponseAmounts,VTPFinancialResponseCard, VTPFinancialResponseHost>

@end

#endif /* VTPEbtVoucherResponse_h */
