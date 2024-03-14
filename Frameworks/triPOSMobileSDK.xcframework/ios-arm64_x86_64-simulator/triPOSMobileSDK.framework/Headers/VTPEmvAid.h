///
/// \file VTPEmvAid.h
///

#ifndef VTPEmvAid_h
#define VTPEmvAid_h


#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \class VTPEmvAid
///
/// \brief The EMV AID class
///
/// This class defines the methods and properties for an EMV application identifier (AID).
///
@interface VTPEmvAid : NSObject

///
/// \brief Gets or sets the proprietary application identifier extension (PIX)
///
/// This property gets or sets the proprietary application identifier extension (PIX).
///
@property (retain, nonatomic) NSString *pix;

///
/// \brief Gets or sets this AID's name
///
/// This property gets or sets this AID's name.
///
@property (retain, nonatomic) NSString *name;

///
/// \brief Gets or sets the application version number
///
/// This property gets or sets the application version number.
///
@property (retain, nonatomic) NSString *applicationVersionNumber;

///
/// \brief Create an AID
///
/// The method creates an AID using the provided information.
///
/// \param pix The proprietary application identifier extension (PIX).
///
/// \param name The AID's name.
///
/// \param applicationVersionNumber The application version number.
///
/// \return And initialized VTPEmvAid object.
///
+(VTPEmvAid *)aidWithPix:(NSString *)pix name:(NSString *)name applicationVersionNumber:(NSString *)applicationVersionNumber;

/// \brief Validates the configuration.
///
/// This method validates the configuration. While some items may have their values verified, others are only checked to ensure they are not nil and/or empty.
///
/// \param error Pointer to NSError object. If the enable fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)validate:(NSError **)error;

@end

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEmvAid_h */
