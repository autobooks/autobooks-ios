//
//  VPDPairingConfirmationCallback_h.h
//  triPOSMobileSDK
//
//  Created on 06/09/22.
//  Copyright © 2022 Worldpay from FIS. All rights reserved.
//

#ifndef VPDPairingConfirmationCallback_h
#define VPDPairingConfirmationCallback_h

@protocol VPDPairingConfirmationCallback

@required
/**
 * This method restarts the LED sequence on the card reader and triggers the method
 */
-(void) restartLedPairingSequence;

/**
 * Invoking this method indicates that LED pairing sequence is confirmed by the user.
 */
-(void) confirm;

/**
 * Invoking this method cancels the pairing process.
 */
-(void) cancel;

@end

#endif /* VPDPairingConfirmationCallback_h */
