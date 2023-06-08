///
/// \file VXPBIN.h
///

#ifndef VXPBIN_h
#define VXPBIN_h

#import "VXPBase.h"
#import "VXPBINTypeCode.h"

///
/// \class VXPBIN
/// \brief BIN class
///
/// The BIN class is used when performing BINQuery requests.
///
@interface VXPBIN : VXPBase
        
///
/// \brief BIN type code
///
/// BIN type code.
///
@property (nonatomic) VXPBINTypeCode BINTypeCode;

///
/// \brief BIN type value
///
/// BIN type value.
///
@property (retain, nonatomic) NSString *BINTypeValue;

///
/// \brief BIN decorator
///
/// BIN decorator.
///
@property (retain, nonatomic) NSString *BINDecorator;

@end

#endif /* VXPBIN_h */
