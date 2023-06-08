///
/// \file VTPFinancialRequestConvenienceFeeAmount.h
///

#ifndef VTPFinancialRequestConvenienceFeeAmount_h
#define VTPFinancialRequestConvenienceFeeAmount_h

///
/// \protocol VTPFinancialRequestConvenienceFeeAmount
///
/// \brief The protocol for convenience fee amount
///
@protocol VTPFinancialRequestConvenienceFeeAmount

///
/// \brief Gets or sets the convenience fee amount
///
/// Gets or sets the amount of the convenience fee for the transaction. This amount should not be included in transactionAmount.
///
/// \sa transactionAmount.
///
@property (retain, nonatomic) NSDecimalNumber *convenienceFeeAmount;

@end

#endif /* VTPFinancialRequestConvenienceFee_h */
