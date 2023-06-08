///
/// \file VXP+UrlSession.h
///

#ifndef VXP_UrlSession_h
#define VXP_UrlSession_h

#import "VXP.h"

///
/// \category VXP(UrlSession)
///
/// \brief The VXP category that contains UrlSession handling
///
/// This category contains UrlSession handling functionality.
///
@interface VXP(UrlSession)

///
/// \brief Gets the URL session for Express HTTP communcation.
///
/// This method gets the URL session for Express HTTP communication.
///
-(NSURLSession *)getUrlSession:(NSString *)host testCertification:(BOOL)testCertification;

@end



#endif /* VXP_UrlSession_h */
