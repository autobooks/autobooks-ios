///
/// \file VPDIngenicoRba+CardInput.h
///

#ifndef VPDIngenicoRba_CardInput_h
#define VPDIngenicoRba_CardInput_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#import "VPDCardInput.h"
#import "VPDIngenicoRba.h"

@interface VPDIngenicoRba(CardInput) <VPDCardInput>

-(BOOL)waitForChipCardToBeRemoved:(NSTimeInterval)timeout beep:(BOOL)beep;

-(BOOL)promptToRemoveCard:(NSString *)prompt error:(NSError **)error;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDIngenicoRba_CardInput_h */
