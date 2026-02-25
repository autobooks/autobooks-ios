
#ifndef VTPDebitFinancialResponseBase_h
#define VTPDebitFinancialResponseBase_h


///
/// \protocol VTPDebitFinancialResponseBase
///
/// \brief The protocol that defines the properties returned in debit transaction responses
///
@protocol VTPDebitFinancialResponseBase

///
/// \brief Gets the debit account type for the transaction
///
/// This property gets the debit account type for the transaction.
///
@property (nonatomic) VTPDebitAccountType debitAccountType;

@end

#endif /* VTPDebitFinancialResponseBase_h */
