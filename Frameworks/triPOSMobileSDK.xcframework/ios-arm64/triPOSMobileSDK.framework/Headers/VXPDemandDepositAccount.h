#if VXPPHASE > 1

#ifndef VXPDemandDepositAccount_h
#define VXPDemandDepositAccount_h

#import "VXPBase.h"
#import "VXPDDAAccountType.h"

///
/// \file VXPDemandDepositAccount.h
///

///
/// \class VXPDemandDepositAccount
/// \brief Demand deposit account class.
///
/// The class is used for passing in demand deposit account informtion (i.e. checking account information).
///
@interface VXPDemandDepositAccount : VXPBase
        
///
/// \brief Demand deposit account type
///
/// Demand deposit account type
///
@property (nonatomic) VXPDDAAccountType DDAAccountType;

///
/// \brief Account number
///
/// Acccount number
///
@property (retain, nonatomic) NSString *AccountNumber;

///
/// \brief Routing number
///
/// Routing number
///
@property (retain, nonatomic) NSString *RoutingNumber;

///
/// \brief Check number
///
/// Check number
///
@property (retain, nonatomic) NSString *CheckNumber;

///
/// \enum VXPCheckType
///
typedef enum _VXPCheckType
    {
    /// This field is not used
    VXPCheckTypeNotSet = VXPEnumNotSet,
    /// Personal check
    VXPCheckTypePersonal = 0,
    /// Business check
    VXPCheckTypeBusiness,
    }   VXPCheckType;

///
/// \brief Check type
///
/// Check type
///
@property (nonatomic) VXPCheckType CheckType;

///
/// \brief Truncated account number
///
/// Truncated account number
///
@property (retain, nonatomic) NSString *TruncatedAccountNumber;

///
/// \brief Truncated routing number
///
/// Truncated routing number
///
@property (retain, nonatomic) NSString *TruncatedRoutingNumber;

@end

#endif /* VXPDemandDepositAccount_h */

#endif      //end of VXPPHASE > 1

