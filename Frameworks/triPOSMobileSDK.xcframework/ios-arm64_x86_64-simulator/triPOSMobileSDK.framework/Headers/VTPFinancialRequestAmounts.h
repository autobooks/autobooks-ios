///
/// \file VTPFinancialRequestAmounts.h
///

#ifndef VTPFinancialRequestAmounts_h
#define VTPFinancialRequestAmounts_h

///
/// \protocol VTPFinancialRequestAmounts
///
/// \brief The protocol for financial requests with amounts
///
@protocol VTPFinancialRequestAmounts

///
/// \brief Gets or sets the sales tax amount
///
/// Gets or sets the amount of the sales tax for the transaction. This amount should be included in the transaction amount.
///
/// \sa transactionAmount
///
@property (retain, nonatomic) NSDecimalNumber *salesTaxAmount;

///
/// \brief Gets or sets the transaction amount
///
/// Gets or sets the amount of the transaction. This amount should include the sales tax amount, but not include tipAmount or convenienceFeeAmount.
///
/// \sa salesTaxAmount, tipAmount, convenienceFeeAmount
///
@property (retain, nonatomic) NSDecimalNumber *transactionAmount;

@end

#endif /* VTPFinancialRequestAmounts_h */
