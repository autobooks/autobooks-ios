///
/// \file VTPFinancialResponseAmounts.h
///

#ifndef VTPFinancialResponseAmounts_h
#define VTPFinancialResponseAmounts_h

///
/// \protocol VTPFinancialResponseAmounts
///
/// \brief The protocol that defines the amounts returned in a financial response
///
@protocol VTPFinancialResponseAmounts

///
/// \brief Gets the approved amount
///
/// Gets the amount approved for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *approvedAmount;

///
/// \brief Gets the balance amount
///
/// Gets the balance amount for a gift card transaction.
///
@property (retain, nonatomic) NSDecimalNumber *balanceAmount;

@end

#endif /* VTPFinancialResponseAmounts_h */
