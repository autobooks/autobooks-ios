//
//  VXPTerminalClassificationCode.h
//  triPOSMobileSDK
//
//  Created on 27/01/25.
//  Copyright © 2025 Worldpay from FIS. All rights reserved.
//

#ifndef VXPTerminalClassificationCode_h
#define VXPTerminalClassificationCode_h

///
/// \enum VXPTerminalClassificationCode
///
typedef enum _VXPTerminalClassificationCode
{
    /// This field is not used
    VXPTerminalClassificationCodeNotSet = VXPEnumNotSet,
    /// Default
    VXPTerminalClassificationCodeDefault = 0,
    ///MPOSWithOrWithoutPINPad
    VXPTerminalClassificationCodeMPOSWithOrWithoutPINPad = 1,
    ///MPOSWithPINOnGlass
    VXPTerminalClassificationCodeMPOSWithPINOnGlass = 2,
    ///CPOCNoPinSupport
    VXPTerminalClassificationCodeCPOCNoPinSupport = 3,
    ///CPOCWithPINSupport
    VXPTerminalClassificationCodeCPOCWithPINSupport = 4,
}   VXPTerminalClassificationCode;


#endif /* VXPTerminalClassificationCode_h */
