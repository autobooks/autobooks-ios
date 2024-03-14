//
//  VPDDccInput.h
//  triPOSMobileSDK
//
//  Created on 22/06/23.
//  Copyright © 2023 Worldpay from FIS. All rights reserved.
//

#ifndef VPDDccInput_h
#define VPDDccInput_h

#import "VPDDevice.h"

///
/// \brief Block definition for completionHandler parameter of the enable methods
///
/// \param choice The DCC confirmation response
///
/// \sa enableDccInput, enable DCC confirmation with choices
typedef void (^VPDDccInputCompletionHandler)(NSNumber *selection);


///
/// \protocol VPDDCC
///
/// \brief POI display DCC confirmation protocol
///
/// The VPDDCC protocol defines methods a POI display must implement to confirm DCC offer.
///
@protocol VPDDccInput <VPDDevice>

@required

///
/// \brief Displays the DCC confirmation details
///
/// \param foreignTransactionAmount The foreign transaction amount from the DCC offer
///
/// \param foriegnCurrencyCode The currency code for the foreign transaction amount
///
/// \param conversionRate The conversion rate from the DCC offer
///
/// \param transactionCurrencyCode The currency code for the transaction
///
/// \param completionHandler The completion handler used when the DCC confimration response provided on the PED device
///
/// \param errorHandler A VPDErrorHandler used to return any errors
///
/// \return YES if successful, NO otherwise
///
-(BOOL)displayDccConfirmation:(NSString *)foreignTransactionAmount foreignCurrencyCode: (NSString *)foreignCurrencyCode conversionRate: (NSString *) conversionRate transactionCurrencyCode:(NSString *)transactionCurrencyCode completionHandler:(VPDDccInputCompletionHandler)completionHandler errorHandler:(VPDErrorHandler)errorHandler;

@end

#endif /* VPDDccInput_h */

