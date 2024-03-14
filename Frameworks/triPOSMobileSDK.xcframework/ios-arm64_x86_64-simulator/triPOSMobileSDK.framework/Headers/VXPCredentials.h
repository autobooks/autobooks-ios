///
/// \file VXPCredentials.h
///

#ifndef VXPCredentials_h
#define VXPCredentials_h

#import "VXPBase.h"

///
/// \class VXPCredentials
/// \brief Credentials class
///
/// The Credentials class is required for every transaction and
/// is used to authenticate the sender.
///
@interface VXPCredentials : VXPBase
        
///
/// \brief Account ID
///
/// Unique account ID. Assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *AccountID;

///
/// \brief Account token
///
/// Secret token used for authentication. Assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *AccountToken;

///
/// \brief Acceptor ID
///
/// Unique merchant account identifier. Assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *AcceptorID;

///
/// \brief New account token.
///
/// New secret token used for authentication. Assigned by Worldpay Integrated Payments
///
@property (retain, nonatomic) NSString *NewAccountToken;

///
/// \brief Returns and initialized VXPCredentials object
///
/// This method returns an initialized VXPCredentials object initialized with the supplied information.
///
/// \param accountID Unique account ID.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param accountToken Secret token used for authentication.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param acceptorID Unique merchant account identifier.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \return An initialized VXPCredentials object.
///
-(instancetype)initWithValues:(NSString *)accountID accountToken:(NSString *)accountToken acceptorID:(NSString *)acceptorID;

///
/// \brief Creates and returns and initialized VXPCredentials object
///
/// This method creates and returns an initialized VXPCredentials object initialized with the supplied information.
///
/// \param accountID Unique account ID.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param accountToken Secret token used for authentication.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param acceptorID Unique merchant account identifier.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \return An initialized VXPCredentials object.
///
+(VXPCredentials *)credentialsWithValues:(NSString *)accountID accountToken:(NSString *)accountToken acceptorID:(NSString *)acceptorID;

@end

#endif /* VXPCredentials_h */
