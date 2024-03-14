///
/// \file VTPHostConfiguration.h
///

#ifndef VTPHostConfiguration_h
#define VTPHostConfiguration_h

#import <Foundation/Foundation.h>

#import "VTPPaymentProcessor.h"

///
/// \class VTPHostConfiguration
///
/// \brief The host configuration class
///
/// This class defines the methods and properties for the host configuration.
///
@interface VTPHostConfiguration : NSObject

///
/// \brief Gets or sets the acceptor ID
///
/// This property gets or sets the acceptor ID.
///
@property (retain, nonatomic) NSString *acceptorId;

///
/// \brief Gets the acceptor ID with all but the last 4 digits masked
///
/// This property gets the acceptor ID with all but the last 4 digits masked.
///
@property (retain, nonatomic,readonly) NSString *maskedAcceptorId;

///
/// \brief Gets or sets the acceptor ID
///
/// This property gets or sets the acceptor ID.
///
@property (retain, nonatomic) NSString *accountId;

///
/// \brief Gets or sets the account token
///
/// This property gets or sets the account token.
///
@property (retain, nonatomic) NSString *accountToken;

///
/// \brief Gets or sets the application ID
///
/// This property gets or sets the application ID.
///
@property (retain, nonatomic) NSString *applicationId;

///
/// \brief Gets or sets the application name
///
/// This property gets or sets the application name.
///
@property (retain, nonatomic) NSString *applicationName;

///
/// \brief Gets or sets the application version
///
/// This property gets or sets the application version.
///
@property (retain, nonatomic) NSString *applicationVersion;

///
/// \brief Gets or sets the StoreCard ID
///
/// This property gets or sets the StoreCard ID.
///
@property (retain, nonatomic) NSString *storeCardID;

///
/// \brief Gets or sets the StoreCard password
///
/// This property gets or sets the StoreCard password.
///
@property (retain, nonatomic) NSString *storeCardPassword;

///
/// \brief Gets or sets the payment processor
///
/// This property gets or sets the payment processor which allows the triPOS mobile SDK to handle processor specific implementation mainly for EMV.
///
@property (nonatomic) VTPPaymentProcessor paymentProcessor;

///
/// \brief Specifies the maximum retries for an auto reversal in case of a communication issue.
///
/// This property sets the maximum number of retiries for an auto reversal during a communication error with Express. Valid values are 1-4.
///
@property (nonatomic) NSUInteger autoReversalRetryLimit;

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

///
/// \brief The time duration after which the transaction would timeout.
///
/// This property gets or sets the timeout duration.
///
@property (nonatomic) NSUInteger expressRequestTimeout;

@end

#endif /* VTPHostConfiguration_h */
