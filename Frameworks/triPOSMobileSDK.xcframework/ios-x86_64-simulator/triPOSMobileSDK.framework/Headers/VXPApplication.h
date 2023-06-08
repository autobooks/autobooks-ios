///
/// \file VXPApplication.h
///

#ifndef VXPApplication_h
#define VXPApplication_h

#import "VXPBase.h"
    
///
/// \class VXPApplication

/// \brief Application class
///
/// The Application class is required for every transaction and is used to uniquely identify the sending application.
///
@interface VXPApplication : VXPBase

///
/// \brief Application ID
///
/// Unique application identifier. This value is assigned by Worldpay Integrated Payments.
///
@property (retain, nonatomic) NSString *ApplicationID;

///
/// \brief Application name
///
/// Name of the application.
///
@property (retain, nonatomic) NSString *ApplicationName;

///
/// \brief Application version
///
/// Version of the application.
///
@property (retain, nonatomic) NSString *ApplicationVersion;

///
/// \brief Integration Type
///
/// Integration type of this application.  It will ALWAYS be 5 (TriPosMobileIos)
/// It should only be sent for transaction services.
///
@property (strong, nonatomic) NSString *IntegrationType;

///
/// \brief Returns an initialized VXPApplication object
///
/// This returns an EpxExpApplication object initialized with the supplied information.
///
/// \param applicationID Application ID.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param applicationName Application name.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param applicationVersion Application version.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \return An initialized VXPApplication object.
///
-(instancetype)initWithValues:(NSString *)applicationID applicationName:(NSString *)applicationName applicationVersion:(NSString *)applicationVersion;

///
/// \brief Creates and returns an initialized VXPApplication object
///
/// This creates and returns an EpxExpApplication object initialized with the supplied information.
///
/// \param applicationID Application ID.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param applicationName Application name.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \param applicationVersion Application version.
/// This parameter may be nil, but it must be set before processing the transaction.
///
/// \return An initialized VXPApplication object.
///
+(VXPApplication *)applicationWithValues:(NSString *)applicationID applicationName:(NSString *)applicationName applicationVersion:(NSString *)applicationVersion;

@end

#endif /* VXPApplication_h */
