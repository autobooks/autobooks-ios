///
/// \file VXP+Connection.h
///

#ifndef VXP_Connection_h
#define VXP_Connection_h

#import "VXP.h"

///
/// \category VXP(Connection)
///
/// \brief The VXP category that contains connection checking functionality
///
/// This category contains connection checking functionality.
///
@interface VXP(Connection)

///
/// \brief Gets whether Express is available as of the last call to Express
///
/// This method gets whether Express is available as of the last call to Express.
///
+(BOOL)isExpressAvailable;

+(BOOL)startMonitoringForExpressToBecomeAvailable:(BOOL)testCertification application:(VXPApplication *)application credentials:(VXPCredentials *)credentials;

+(BOOL)startMonitoringForExpressToBecomeAvailable:(BOOL)testCertification application:(VXPApplication *)application credentials:(VXPCredentials *)credentials overrideURL:(NSURL *)overrideURL;

@end



#endif /* VXP_Connection_h */
