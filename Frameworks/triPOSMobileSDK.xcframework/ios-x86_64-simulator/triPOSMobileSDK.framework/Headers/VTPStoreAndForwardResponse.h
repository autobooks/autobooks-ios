///
///  \file VTPStoreAndForwardResponse.h
///

#ifndef VTPStoreAndForwardResponse_h
#define VTPStoreAndForwardResponse_h

///
/// \protocol VTPStoreAndForwardResponse
/// 
/// \brief The protocol that defines the response from store and forward
///
@protocol VTPStoreAndForwardResponse

///
/// \brief Gets tpId
///
/// This property contains a UUID representing the transaction.
///
@property (retain, nonatomic) NSString *tpId;

///
/// \brief Gets whether or not the transaction was stored
///
/// This property contains the status after attempting to store a transaction.
///
@property (nonatomic) BOOL wasTransactionStored;

@end

#endif /* VTPStoreAndForwardResponse_h */
