///
/// \file VXPExtendedParameters.h
///

#ifndef VXPExtendedParameters_h
#define VXPExtendedParameters_h

#import "VXPBase.h"

#import "VXPPaymentAccount.h"
#import "VXPScheduledTask.h"
#import "VXPHealthcare.h"
#import "VXPAutoRental.h"
#import "VXPLodging.h"
#import "VXPToken.h"

///
/// \class VXPExtendedParameters
///
/// \brief ExtendedParameters class
///
@interface VXPExtendedParameters : VXPBase
        
///
/// \brief PaymentAccount class
///
/// The PaymentAccount class is used for PASS transactions.
///
@property (retain, nonatomic) VXPPaymentAccount *PaymentAccount;

#if VXPPHASE > 1
///
/// \brief ScheduledTask class
///
/// The ScheduledTask class is used to schedule transaction.
///
@property (retain, nonatomic) VXPScheduledTask *ScheduledTask;
#endif      //end of VXPPHASE > 1

///
/// \brief Healthcare class
///
@property (retain, nonatomic) VXPHealthcare *Healthcare;
#endif      //end of VXPPHASE > 1

#ifdef VXPAutoRental // not in phase 1
                        ///
                        /// \brief AutoRental class
                        ///
                        /// The AutoRental class is requred for auto rental industry transactions and
                        /// is used to identify auto rental transaction details. This methods is used
                        /// on the TSYS and FDC platforms only.
                        ///
@property (retain, nonatomic) VXPAutoRental *AutoRental;
#endif                  // end of VXPAutoRental

#if VXPPHASE > 1
///
/// \brief Lodging class
///
@property (retain, nonatomic) VXPLodging *Lodging;
#endif      //end of VXPPHASE > 1

///
/// \brief Token class
///
/// The token class used for token transactions.
///
@property (retain, nonatomic) VXPToken *Token;

@end
