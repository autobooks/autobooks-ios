//
//  VTPDebitAccountType.h
//  triPOSMobileSDK
//
//  Created on 10/13/23.
//  Copyright © 2023 Worldpay from FIS. All rights reserved.
//

#ifndef VTPDebitAccountType_h
#define VTPDebitAccountType_h

typedef enum _VTPDebitAccountType
{
    /// Checking
    VTPDebitAccountTypeNone = -1,
    VTPDebitAccountTypeChecking = 0,
    /// Savings
    VTPDebitAccountTypeSavings = 1
}   VTPDebitAccountType;

#endif /* VTPDebitAccountType_h */
