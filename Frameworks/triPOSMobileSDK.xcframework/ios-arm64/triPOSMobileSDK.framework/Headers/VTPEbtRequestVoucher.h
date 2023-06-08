///
/// \file VTPEbtRequestVoucher.h
///

#ifndef VTPEbtRequestVoucher_h
#define VTPEbtRequestVoucher_h

///
/// \protocol VTPEbtRequestVoucher
///
/// \brief The protocol for EBT Request Voucher
///
@protocol VTPEbtRequestVoucher

///
/// \brief Gets or sets the voucher number
///
/// Gets or sets the voucher number for the transaction.
///
/// \sa voucherNumber.
///
@property (retain, nonatomic) NSString *voucherNumber;

///
/// \brief Gets or sets the approval number for the transaction.
///
/// Gets or sets the approval number for the transaction.
///
/// \sa approvalNumber.
///
@property (retain, nonatomic) NSString *approvalNumber;



@end


#endif /* VTPEbtRequestVoucher_h */
