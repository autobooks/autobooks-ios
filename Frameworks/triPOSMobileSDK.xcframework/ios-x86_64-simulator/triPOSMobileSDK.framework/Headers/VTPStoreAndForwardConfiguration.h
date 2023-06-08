///
///  \file VTPStoreAndForwardConfiguration.h
///

#ifndef VTPStoreAndForwardConfiguration_h
#define VTPStoreAndForwardConfiguration_h

#import "VTPTransactionStoringMode.h"

///
/// \class VTPStoreAndForwardConfiguration
///
/// \brief Configuration options for store and forward
///
/// This class defines methods and properties for store and forward configuration options.
///
@interface VTPStoreAndForwardConfiguration : NSObject

///
/// \brief Gets or sets if store and forward is enabled
///
/// This property gets or sets whether store and foward is enabled or not.
/// NOTE: This flag has been deprecated.

@property (nonatomic) BOOL isStoringTransactionsAllowed __deprecated;

///
/// \brief Gets or sets if transactions should be automatically forwarded.
///
/// This property gets or sets whether stored transactions should be automatically forwarded.
///
@property (nonatomic) BOOL shouldTransactionsBeAutomaticallyForwarded;

///
/// \brief Gets or sets store and forward transaction amount limit.
///
/// This property gets or sets the amount over which the transaction will be declined and not stored.
///
@property (nonatomic) NSUInteger transactionAmountLimit;

///
/// \brief Gets or sets store and forward unprocessed total amount limit
///
/// This property gets or sets the total amount over which transactions will be declined and not stored. This property is used to limit the total amount for stored and unprocessed transactions.
///
@property (nonatomic) NSUInteger unprocessedTotalAmountLimit;

///
/// \brief Gets or set the number of days processed transactions should be retained
///
/// This property gets or sets teh number of days a transaction marked as processed or deleted will be retained.
///
@property (nonatomic) NSUInteger numberOfDaysToRetainProcessedTransactions;

///
/// \brief Gets or sets Transaction Storing Modes
///
/// This property gets or sets Transaction Storing Modes - Disabled, Manual or Auto Storing
///
@property (nonatomic) VTPTransactionStoringMode transactionStoringMode;


///
/// \brief Validates the configuration.
///
/// This method validates the configuration. While some items may have their values verified, others are only checked to ensure they are not nil and/or empty.
///
/// \param error Pointer to NSError object. If the enable fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)validateConfiguration:(NSError **)error;

@end

#endif /* VTPStoreAndForwardConfiguration_h */
