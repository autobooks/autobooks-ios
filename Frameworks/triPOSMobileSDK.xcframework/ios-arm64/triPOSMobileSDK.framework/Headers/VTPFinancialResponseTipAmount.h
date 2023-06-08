///
/// \file VTPFinancialResponseTipAmount.h
///

#ifndef VTPFinancialResponseTipAmount_h
#define VTPFinancialResponseTipAmount_h

///
/// \protocol VTPFinancialResponseTipAmount
///
/// \brief The protocol that defines the tip amount returned in some financial responses
///
@protocol VTPFinancialResponseTipAmount

///
/// \brief Gets the tip amount
///
/// Gets the tip amount for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *tipAmount;

@end

#endif /* VTPFinancialResponseTipAmount_h */
