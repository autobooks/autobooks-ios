///
/// \file VTPCaPublicKey.h
///

#ifndef VTPCaPublicKey_h
#define VTPCaPublicKey_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \class VTPCaPublicKey
///
/// \brief The CA public key class
///
/// This class defines method and properties for a CA public key.
///
@interface VTPCaPublicKey : NSObject

///
/// \brief Gets or sets the issuer
///
/// This property gets or sets the issuer.
///
@property (retain, nonatomic) NSString *issuer;

///
/// \brief Gets or sets the registered application provider identifier (RID)
///
/// This property gets or sets the registered application provider identifier (RID).
///
@property (retain, nonatomic) NSString *rid;

///
/// \brief Gets or sets the modulus
///
/// This property gets or sets the modulus.
///
@property (retain, nonatomic) NSString *modulus;

///
/// \brief Gets or sets the index
///
/// This property gets or sets the index.
///
@property (nonatomic) unsigned char index;

///
/// \brief Gets or sets the exponent
///
/// This property gets or sets the exponent.
///
@property (nonatomic) unsigned int exponent;

///
/// \brief Gets or sets the SHA-1 hash
///
/// This property gets or sets the SHA-1 hash.
///
@property (retain, nonatomic) NSString *sha1Hash;

///
/// \brief Gets or sets the expiration date.
///
/// This property gets or sets the expiration date
///
@property (retain, nonatomic) NSDate *expirationDate;

///
/// \brief Gets or sets whether this is a test CA public key or not
///
/// This property gets or sets whether this is a test CA public key or not.
///
@property (nonatomic) BOOL isTestKey;

///
/// \brief Create a CA public key object with the specified parameters
///
/// This method creates a CA public key object with the specified parameters.
///
/// \return And initialized VTPCaPublicKey object.
///
+(VTPCaPublicKey *)caPublicKeyWithIssuer:(NSString *)issuer rid:(NSString *)rid modulus:(NSString *)modulus index:(unsigned char)index exponent:(unsigned int)exponent sha1Hash:(NSString *)sha1Hash expirationDate:(NSDate *)expirationDate isTestKey:(BOOL)isTestKey;

///
/// \brief Validate this CA public key
///
/// This method validates this CA public key.
///
/// \param error If the CA public key is not valid, error information is returned in this object. This parameter may be nil.
///
-(BOOL)validate:(NSError **)error;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPCaPublicKey_h */
