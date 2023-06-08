///
/// \file VTPStoreTransactionState.h
///

#ifndef VTPStoreTransactionState_h
#define VTPStoreTransactionState_h

typedef enum _VTPStoreTransactionState
{
    VTPStoreTransactionStateStored,
    VTPStoreTransactionStateStoredPendingGenac2,
    VTPStoreTransactionStateProcessing,
    VTPStoreTransactionStateProcessed,
    VTPStoreTransactionStateDeleted
}   VTPStoreTransactionState;

#endif /* VTPStoreTransactionState_h */
