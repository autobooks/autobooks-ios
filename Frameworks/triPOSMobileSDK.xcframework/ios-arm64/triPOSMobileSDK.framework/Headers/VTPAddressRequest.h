///
/// \file VTPAddressRequest.h
///

#ifndef VTPAddressRequest_h
#define VTPAddressRequest_h

///
/// \protocol VTPAddressRequest
///
/// \brief The protocol for financial requests with billing email.
///
@protocol VTPAddressRequest

///
/// \brief Gets or sets the billing emil
///
/// Gets or sets the billing email.
///
@property (retain, nonatomic) NSString *billingEmail;

@end


#endif /* VTPAddressRequest_h */
