#ifndef VXPHealthcare_h
#define VXPHealthcare_h

#import "VXPBase.h"
#import "VXPHealthcareAccountType.h"

///
/// \file VXPHealthcare.h
///

///
/// \class VXPHealthcare
/// \brief Healthcare class
///
/// This class is used to pass health care information.
///
@interface VXPHealthcare : VXPBase
        
///
/// \brief Health care flag
///
/// If this is set to true, the Healthcare parameters should be submitted.
///
@property (nonatomic) VXPBooleanType HealthcareFlag;

///
/// \brief Health care first account type
///
/// Health care first account type
///
@property (nonatomic) VXPHealthcareAccountType HealthcareFirstAccountType;

///
/// \enum VXPHealthcareAmountType
///
typedef enum _VXPHealthcareAmountType
    {
    /// This field is not used
    VXPHealthcareAmountTypeNotSet = VXPEnumNotSet,
    /// Ledger balance
    VXPHealthcareAmountTypeLedgerBalance = 0,
    /// Available balance
    VXPHealthcareAmountTypeAvailableBalance,
    /// Health care
    VXPHealthcareAmountTypeHealthcare,
    /// Transit
    VXPHealthcareAmountTypeTransit,
    /// Co-payment
    VXPHealthcareAmountTypeCopayment,
    /// Original amount
    VXPHealthcareAmountTypeOriginalAmount,
    /// Partial authroized amount
    VXPHealthcareAmountTypePartialAuthorizedAmount,
    /// Prescription
    VXPHealthcareAmountTypePrescription,
    /// Vision
    VXPHealthcareAmountTypeVision,
    /// Clinic
    VXPHealthcareAmountTypeClinic,
    /// Dental
    VXPHealthcareAmountTypeDental,
    /// Cash over
    VXPHealthcareAmountTypeCashOver,
    /// Original cash over
    VXPHealthcareAmountTypeOriginalCashOver,
    }   VXPHealthcareAmountType;

///
/// \brief Health care first amount type
///
/// Health care first amount type
///
@property (nonatomic) VXPHealthcareAmountType HealthcareFirstAmountType;

///
/// \brief Health care first currency code
///
/// Health care first currency code
///
@property (retain, nonatomic) NSString *HealthcareFirstCurrencyCode;

///
/// \enum VXPHealthcareAmountSign
///
typedef enum _VXPHealthcareAmountSign
    {
    /// This field is not used
    VXPHealthcareAmountSignNotSet = VXPEnumNotSet,
    /// Positive
    VXPHealthcareAmountSignPositive = 0,
    /// Negative
    VXPHealthcareAmountSignNegative,
    }   VXPHealthcareAmountSign;

///
/// \brief Health care first amount sign
///
/// Health care first amount sign
///
@property (nonatomic) VXPHealthcareAmountSign HealthcareFirstAmountSign;

///
/// \brief Health care first amount
///
/// Health care first amount
///
@property (retain, nonatomic) NSDecimalNumber *HealthcareFirstAmount;

///
/// \brief Health care second account type
///
/// Health care second account type
///
@property (nonatomic) VXPHealthcareAccountType HealthcareSecondAccountType;

///
/// \brief Health care second amount type
///
/// Health care second amount type
///
@property (nonatomic) VXPHealthcareAmountType HealthcareSecondAmountType;

///
/// \brief Health care second currency code
///
/// Health care second currency code
///
@property (retain, nonatomic) NSString *HealthcareSecondCurrencyCode;

///
/// \brief Health care second amount sign
///
/// Health care second amount sign
///
@property (nonatomic) VXPHealthcareAmountSign HealthcareSecondAmountSign;

///
/// \brief Health care second amount
///
/// Health care second amount
///
@property (retain, nonatomic) NSDecimalNumber *HealthcareSecondAmount;

///
/// \brief Health care third account type
///
/// Health care third account type
///
@property (nonatomic) VXPHealthcareAccountType HealthcareThirdAccountType;

///
/// \brief Health care third amount type
///
/// Health care third amount type
///
@property (nonatomic) VXPHealthcareAmountType HealthcareThirdAmountType;

///
/// \brief Health care third currency code
///
/// Health care third currency code
///
@property (retain, nonatomic) NSString *HealthcareThirdCurrencyCode;

///
/// \brief Health care third amount sign
///
/// Health care third amount sign
///
@property (nonatomic) VXPHealthcareAmountSign HealthcareThirdAmountSign;

///
/// \brief Health care third amount
///
/// Health care third amount
///
@property (retain, nonatomic) NSDecimalNumber *HealthcareThirdAmount;

///
/// \brief Health care fourth account type
///
/// Health care fourth account type
///
@property (nonatomic) VXPHealthcareAccountType HealthcareFourthAccountType;

///
/// \brief Health care fourth amount type
///
/// Health care fourth amount type
///
@property (nonatomic) VXPHealthcareAmountType HealthcareFourthAmountType;

///
/// \brief Health care fourth currency code
///
/// Health care fourth currency code
///
@property (retain, nonatomic) NSString *HealthcareFourthCurrencyCode;

///
/// \brief Health care fourth amount sign
///
/// Health care fourth amount sign
///
@property (nonatomic) VXPHealthcareAmountSign HealthcareFourthAmountSign;

///
/// \brief Health care fourth amount
///
/// Health care fourth amount
///
@property (retain, nonatomic) NSDecimalNumber *HealthcareFourthAmount;

@end
#endif      //end of VXPPHASE > 1

