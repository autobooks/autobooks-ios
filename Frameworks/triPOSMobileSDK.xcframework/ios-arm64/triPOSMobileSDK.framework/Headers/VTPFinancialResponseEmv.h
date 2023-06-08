///
/// \file VTPFinancialResponseEmv.h
///

#ifndef VTPFinancialResponseEmv_h
#define VTPFinancialResponseEmv_h

#import "VTPEmvData.h"

///
/// \protocol VTPFinancialResponseEmv
///
/// \brief The protocol that defines the EMV data returned in some financial responses
///
@protocol VTPFinancialResponseEmv


///
/// \brief Gets the EMV data
///
/// This property contains the EMV data used to process the transaction.
///
@property (retain, nonatomic) VTPEmvData *emv;

@end

#endif /* VTPFinancialResponseEmv_h */
