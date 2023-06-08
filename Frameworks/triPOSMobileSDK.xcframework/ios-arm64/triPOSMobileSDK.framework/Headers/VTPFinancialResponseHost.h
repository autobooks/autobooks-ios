///
/// \file VTPFinancialResponseHost.h
///

#ifndef VTPFinancialResponseHost_h
#define VTPFinancialResponseHost_h

#import "VTPHostResponseData.h"

///
/// \protocol VTPFinancialResponseHost
///
@protocol VTPFinancialResponseHost

///
/// \brief Gets the host response
///
/// This property contains data received from the host for an online authorization attempt. NOTE: This property may be nil if an attempt for online authorization failed.
///
/// \sa wasProcessedOnline
///
@property (retain, nonatomic) VTPHostResponseData *host;

@end

#endif /* VTPFinancialResponseHost_h */
