///
/// \file VXPPaging.h
///

#ifndef VXPPaging_h
#define VXPPaging_h

#import "VXPBase.h"

///
/// \class VXPPaging
/// \brief Paging class
///
/// The Paging class is optional with the PaymentAccountQueryTokenReport request.
///
@interface VXPPaging : VXPBase
        
///
/// \brief Page
///
/// PASS token report page number.
///
@property (retain, nonatomic) NSNumber *Page;

@end

#endif /* VXPPaging_h */
