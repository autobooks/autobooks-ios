//
//  VPDAppleTapToPay+Token.h
//  PoiDevice
//

#ifndef VPDAppleTapToPay_Token_h
#define VPDAppleTapToPay_Token_h

#import "VPDAppleTapToPay.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface  VPDAppleTapToPay(Token)

-(BOOL)setupToken;

-(void)teardownToken;

-(BOOL)startGetToken;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDAppleTapToPay_Token_h */
