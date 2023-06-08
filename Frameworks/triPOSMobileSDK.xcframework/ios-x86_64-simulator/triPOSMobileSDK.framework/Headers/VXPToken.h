///
/// \file VXPToken.h
///

#ifndef VXPToken_h
#define VXPToken_h

#import "VXPBase.h"
#import "VXPTokenProvider.h"

///
/// \class VXPToken
/// \brief Credentials class
///
/// The Credentials class is required for every transaction and
/// is used to authenticate the sender.
///
@interface VXPToken : VXPBase
        
///
/// \brief Token ID
///
/// Unique Token ID representing the card.
///
@property (retain, nonatomic) NSString *TokenID;

///
/// \brief Token provider
///
/// The token provider.
///
@property (nonatomic) VXPTokenProvider TokenProvider;

///
/// \brief Vault ID
///
/// The merchant vault ID.
///
@property (retain, nonatomic) NSString *VaultID;

///
/// \brief TransArmor provider ID
///
/// The TransArmor provider ID.
///
@property (retain, nonatomic) NSString *TAProviderID;

@end

#endif /* VXPToken_h */
