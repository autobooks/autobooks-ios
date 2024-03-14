///
/// \file VTPFinancialRequestTipAmount.h
///

#ifndef VTPFinancialRequestTipAmount_h
#define VTPFinancialRequestTipAmount_h

///
/// \protocol VTPFinancialRequestTipAmount
///
/// \brief The protocol for convenience fee amount
///
@protocol VTPFinancialRequestTipAmount

///
/// \brief Gets or sets the tip amount
///
/// Gets or sets the amount of the tip for the transaction. This amount should not be included in transactionAmount.
///
/// \sa transactionAmount.
///
@property (retain, nonatomic) NSDecimalNumber *tipAmount;

@end

#endif /* VTPFinancialRequestTipAmount_h */
