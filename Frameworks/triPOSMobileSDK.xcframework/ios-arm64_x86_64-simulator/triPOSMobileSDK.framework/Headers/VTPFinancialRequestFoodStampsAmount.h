//
//  VTPFinancialRequestFoodStampsAmount.h
//  triPOSMobileSDK
//
//  Created on 30/05/22.
//  Copyright © 2022 Worldpay from FIS. All rights reserved.
//

#ifndef VTPFinancialRequestFoodStampsAmount_h
#define VTPFinancialRequestFoodStampsAmount_h

///
/// \protocol VTPFinancialRequestFoodStampsAmount
///
/// \brief The protocol for food stamps amount
///
@protocol VTPFinancialRequestFoodStampsAmount

///
/// \brief Gets or sets the food stamps amount
///
/// Gets or sets the food stamp amount for EBT transactions. This amount should include only the sale amount or refund amount, but not include tip amount, convenience fee amount, or any other amount.
///

@property (retain, nonatomic) NSDecimalNumber *foodStampsAmount;

@end

#endif /* VTPFinancialRequestFoodStampsAmount_h */
