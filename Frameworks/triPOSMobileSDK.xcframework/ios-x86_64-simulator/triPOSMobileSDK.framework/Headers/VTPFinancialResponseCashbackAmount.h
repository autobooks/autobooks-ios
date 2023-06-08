///
/// \file VTPFinancialResponseCashbackAmount.h
///

#ifndef VTPFinancialResponseCashbackAmount_h
#define VTPFinancialResponseCashbackAmount_h

///
/// \protocol VTPFinancialResponseCashbackAmount
///
/// \brief The protocol that defines the cashback amount returned in some financial responses
///
@protocol VTPFinancialResponseCashbackAmount

///
/// \brief Gets the cashback amount
///
/// Gets the cashback amount approved for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *cashbackAmount;

@end

#endif /* VTPFinancialResponseCashbackAmount_h */
