///
/// \file VXPEBT.h
///

#ifndef VXPEBT_h
#define VXPEBT_h

#import "VXPBase.h"
#import "VXPEBTTypeIndex.h"

///
/// \class VXPEBT
/// \brief EBT class
///
/// The EBT class is required for every transaction and
/// is used to authenticate the sender.
///
@interface VXPEBT : VXPBase
        
///
/// \brief Type index
///
/// The EBT type index. Required for all EBT transactions.
///
@property (nonatomic) VXPEBTTypeIndex EBTTypeIndex;

///
/// \brief Voucher number
///
/// The EBT voucher number. Required for EBT voucher transactions
///
@property (retain, nonatomic) NSString *VoucherNumber;

@end

#endif /* VXPEBT_h */
