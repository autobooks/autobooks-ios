///
/// \file VTPFinancialResponseCard.h
///

#ifndef VTPFinancialResponseCard_h
#define VTPFinancialResponseCard_h

#import "VTPFinancialCardData.h"

///
/// \protocol VTPFinancialResponseCard
///
/// \brief The protocol that defines the card data in financial responses
///
@protocol VTPFinancialResponseCard

///
/// \brief Gets the card data
///
/// This property contains the card data used to process the transaction.
///
@property (retain, nonatomic) VTPFinancialCardData *card;

@end

#endif /* VTPFinancialResponseCard_h */
