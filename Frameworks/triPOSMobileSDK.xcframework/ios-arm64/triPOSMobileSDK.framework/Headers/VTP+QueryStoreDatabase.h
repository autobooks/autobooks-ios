///
///  \file VTP+QueryStoreDatabase.h
///

#ifndef VTP_QueryStoreDatabase_h
#define VTP_QueryStoreDatabase_h

#import "VTP.h"
#import "VTPError.h"
#import "VTPStoreTransactionRecord.h"

///
/// \category VTP(QueryStoreDatabase)
///
/// \brief The extension class for querying stored transactions
///
/// This class defines the methods for querying stored transactions.
///
@interface VTP(QueryStoreDatabase)

///
/// \brief Query all stored transactions
///
/// This method queries all stored transactions.
///
/// \param error A VTPErrorHandler used to return any errors.
///
-(NSArray<VTPStoreTransactionRecord *> *)getAllStoredTransactions:(NSError **)error;

///
/// \brief Query all stored transactions from start to count sorted by createdOn.
///
/// This method queries all stored transactions from the start index inclusively.
/// The number of transactions returned is defined by count.
///
/// \param startIndex The index of the first element in the range.
///
/// \param count The count of the number elements to return.
///
/// \param error A VTPErrorHandler used to return any errors.
///
-(NSArray<VTPStoreTransactionRecord *> *)getAllStoredTransactionsFromIndex:(NSUInteger)startIndex forCount:(NSUInteger)count error:(NSError **)error;

///
/// \brief Query stored transaction by tpId
///
/// This method queries stored transactions by tpId.
///
/// \param tpId The tpId of the transaction to query.
///
/// \param error A VTPErrorHandler used to return any errors.
///
-(VTPStoreTransactionRecord *)getStoredTransactionByTpId:(NSString *)tpId error:(NSError **)error;

///
/// \brief Query stored transactions by state
///
/// This method queries stored transactions by state.
///
/// \param state The state of the transactions to query.
///
/// \param error A VTPErrorHandler used to return any errors.
///
-(NSArray<VTPStoreTransactionRecord *> *)getStoredTransactionsWithState:(VTPStoreTransactionState)state error:(NSError **)error;

///
/// \brief Delete stored transaction with state stored
///
/// This method deletes a stored transaction with the state stored.
///
/// \param tpId The stored transaction UDID to delete.
///
/// \param error A VTPErrorHandler used to return any errors.
///
-(void)deleteStoredTransactionWithStateStored:(NSString *)tpId error:(NSError **)error;

@end

#endif /* VTP_QueryStoreDatabase_h */
