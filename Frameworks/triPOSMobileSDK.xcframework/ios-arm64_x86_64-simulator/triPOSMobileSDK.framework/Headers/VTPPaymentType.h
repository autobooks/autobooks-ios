///
/// \file VTPPaymentType.h
///

#ifndef VTPPaymentType_h
#define VTPPaymentType_h

///
/// \enum VTPPaymentType
///
typedef enum _VTPPaymentType
{
    /// Unknown
    VTPPaymentTypeUnknown,
    /// Credit
    VTPPaymentTypeCredit,
    /// Debit
    VTPPaymentTypeDebit,
    /// GiftCard
    VTPPaymentTypeGiftCard,
    //EBT
    VTPPaymentTypeEbt,
    /// HostedPayments
    VTPPaymentTypeHostedPayments,
}   VTPPaymentType;

#endif /* VTPPaymentType_h */
