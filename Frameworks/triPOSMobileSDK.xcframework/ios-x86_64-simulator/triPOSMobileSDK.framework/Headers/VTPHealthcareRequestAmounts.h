//
//  VTPHealthcareRequestAmounts.h
//  triPOSMobileSDK
//
//  Created on 09/08/22.
//  Copyright © 2022 Worldpay from FIS. All rights reserved.
//

#ifndef VTPHealthcareRequestAmounts_h
#define VTPHealthcareRequestAmounts_h

///
///\protocol VTPHealthcareRequestAmounts
///
/// \brief The protocol for healthcare amounts in Request
///
@protocol VTPHealthcareRequestAmounts 

///
/// \brief Gets or sets the clinic amount
///
/// Gets or sets the clinic amount for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *clinicAmount;

///
/// \brief Gets or sets the dental amount
///
/// Gets or sets the dental amount for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *dentalAmount;

///
/// \brief Gets or sets the prescription amount
///
/// Gets or sets the prescription amount for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *prescriptionAmount;

///
/// \brief Gets or sets the vision amount
///
/// Gets or sets the vision amount for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *visionAmount;

///
/// \brief Gets or sets the total amount
///
/// Gets or sets the total amount for the transaction.
///
@property (retain, nonatomic) NSDecimalNumber *totalHealthcareAmount;

@end

#endif /* VTPHealthcareRequestAmounts_h */
