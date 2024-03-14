//
//  VTPGiftBalanceTransferRequest.h
//  triPOSMobileSDK
//

#ifndef VTPGiftBalanceTransferRequest_h
#define VTPGiftBalanceTransferRequest_h

///
/// \protocol VTPGiftBalanceTransferRequest
///
/// \brief The protocol for Gift card balance transfer request
///
@protocol VTPGiftBalanceTransferRequest

///
/// \brief Gets or sets the card number of the first source card for balance transfer
///
/// Gets or sets the card number of the first source card for the balance transfer transaction.
///
/// \sa SourceCardNumber2, SourceCardNumber3
///
@property (retain, nonatomic) NSString *sourceCardNumber1;

///
/// \brief Gets or sets the card number of the second source card (if necessary) for balance transfer
///
/// Gets or sets the card number of the first source card for the balance transfer transaction.
///
/// \sa SourceCardNumber1, SourceCardNumber3.
///
@property (retain, nonatomic) NSString *sourceCardNumber2;

///
/// \brief Gets or sets the card number of the thrid source card (if necessary) for balance transfer
///
/// Gets or sets the card number of the first source card for the balance transfer transaction.
///
/// \sa SourceCardNumber1, SourceCardNumber2.
///
@property (retain, nonatomic) NSString *sourceCardNumber3;

@end


#endif /* VTPGiftBalanceTransferRequest_h */
