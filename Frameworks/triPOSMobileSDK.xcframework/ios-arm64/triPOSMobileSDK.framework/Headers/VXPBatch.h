///
/// \file VXPBatch.h
///

#ifndef VXPBatch_h
#define VXPBatch_h

#import "VXPBase.h"
#import "VXPBatchCloseType.h"
#import "VXPBatchQueryType.h"

///
/// \class VXPBatch
/// \brief Batch class
///
/// The Batch class is used to request and receive batch information from Express.
///
@interface VXPBatch : VXPBase

///
/// \brief Batch close type
///
/// Batch close type.
///
@property (nonatomic) VXPBatchCloseType BatchCloseType;

///
/// \brief Batch query type
///
/// Batch query type.
///
@property (nonatomic) VXPBatchQueryType BatchQueryType;

///
/// \brief Host batch ID
///
/// Host batch ID.
///
@property (retain, nonatomic) NSString *HostBatchID;

///
/// \brief Host item ID
///
/// Host item ID.
///
@property (retain, nonatomic) NSString *HostItemID;

///
/// \brief Host batch count
///
/// Host batch count.
///
@property (retain, nonatomic) NSNumber *HostBatchCount;

///
/// \brief Host batch amount
///
/// Host batch amount.
///
@property (retain, nonatomic) NSDecimalNumber *HostBatchAmount;

///
/// \enum VXPBatchGroupingCode
///
typedef enum _VXPBatchGroupingCode
    {
    /// This field is not used
    VXPBatchGroupingCodeNotSet = VXPEnumNotSet,
    /// Full
    VXPBatchGroupingCodeFull = 0,
    /// Single
    VXPBatchGroupingCodeSingle,
    }   VXPBatchGroupingCode;

///
/// \brief Batch grouping code
///
/// Batch grouping code.
///
@property (nonatomic) VXPBatchGroupingCode BatchGroupingCode;

///
/// \brief Host reversal queue ID
///
/// Host reversal queue ID.
///
@property (retain, nonatomic) NSString *HostReversalQueueID;

///
/// \brief Host credit sale count
///
/// Host credit sale count.
///
@property (retain, nonatomic) NSNumber *HostCreditSaleCount;

///
/// \brief Host credit sale amount
///
/// Host credit sale amount.
///
@property (retain, nonatomic) NSDecimalNumber *HostCreditSaleAmount;

///
/// \brief Host credit return count
///
/// Host credit return count.
///
@property (retain, nonatomic) NSNumber *HostCreditReturnCount;

///
/// \brief Host credit return amount
///
/// Host credit return amount.
///
@property (retain, nonatomic) NSDecimalNumber *HostCreditReturnAmount;

///
/// \brief Host debit sale count
///
/// Host debit sale count.
///
@property (retain, nonatomic) NSNumber *HostDebitSaleCount;

///
/// \brief Host debit sale amount
///
/// Host debit sale amount.
///
@property (retain, nonatomic) NSDecimalNumber *HostDebitSaleAmount;

///
/// \brief Host debit return count
///
/// Host debit return count.
///
@property (retain, nonatomic) NSNumber *HostDebitReturnCount;

///
/// \brief Host debit return amount
///
/// Host debit return amount.
///
@property (retain, nonatomic) NSDecimalNumber *HostDebitReturnAmount;

///
/// \brief Host batch items
///
/// Host batch items.
///
@property (retain, nonatomic) NSString *HostBatchItems;

typedef enum _VXPBatchIndexCode
    {
    /// This field is not used
    VXPBatchIndexCodeNotSet = VXPEnumNotSet,
    /// Current batch
    VXPBatchIndexCodeCurrent = 0,
    /// First previous batch
    VXPBatchIndexCodeFirstPrevious,
    }   VXPBatchIndexCode;

///
/// \brief Batch index code
///
/// Batch index code.
///
@property (nonatomic) VXPBatchIndexCode BatchIndexCode;

@end

#endif /* VXPBatch_h */
