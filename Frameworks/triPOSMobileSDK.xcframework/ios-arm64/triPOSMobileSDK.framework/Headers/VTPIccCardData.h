///
/// \file VTPIccCardData.h
///

#ifndef VTPIccCardData_h
#define VTPIccCardData_h

#import "VTPCardData.h"
#import "VTCTlvUtility.h"
#import "VPDSignatureRequired.h"

///
/// \class VTPIccCardData
///
/// \brief The ICC card data class
///
/// The ICC card data class.
///
@interface VTPIccCardData : VTPCardData

///
/// \brief Gets or sets the tags
///
/// This property gets or sets the tags.
///
@property (retain, nonatomic) VTCTlvCollection tags;

///
/// \brief Gets the cryptogram
///
/// This property gets the cryptogram.
///
@property (retain, nonatomic, readonly) NSString *cryptogram;

///
/// \brief Gets the issuer code table index
///
/// This property gets the issuer code table index.
///
@property (retain, nonatomic, readonly) NSString *issuerCodeTableIndex;

///
/// \brief Gets the account number
///
/// This property gets the account number.
///
@property (retain, nonatomic, readonly) NSString *accountNumber;

///
/// \brief Gets the application identifier
///
/// This property gets the application identifier.
///
@property (retain, nonatomic, readonly) NSString *applicationIdentifier;

///
/// \brief Gets the application label
///
/// This property gets the application label.
///
@property (retain, nonatomic, readonly) NSString *applicationLabel;

///
/// \brief Gets the application preferred name
///
/// This property gets teh application preferred name.
///
@property (retain, nonatomic, readonly) NSString *applicationPreferredName;

///
/// \brief Gets the cardholder name
///
/// This property gets the cardholder name.
///
@property (retain, nonatomic, readonly) NSString *cardholderName;

///
/// \brief Gets the track 2 equivalent data
///
/// This property gets the track 2 equivalent data.
///
@property (retain, nonatomic, readonly) NSString *track2EquivalentData;

///
/// \brief Gets the service code
///
/// This property gets the service code.
///
@property (retain, nonatomic, readonly) NSString *serviceCode;

///
/// \brief Gets the application transaction counter (Tag 0x9F36)
///
/// This property gets the application transaction counter (Tag 0x9F36).
///
@property (retain, nonatomic, readonly) NSString *applicationTransactionCounter;

///
/// \brief  Gets the signature required status
///
/// Gets the Signature Required status returned from the Terminal.
///
@property (assign, nonatomic) VPDSignatureRequired isSignatureRequired;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

-(instancetype)initWithTags:(VTCTlvCollection)tags;

+(VTPIccCardData *)iccCardDataWithTags:(VTCTlvCollection)tags;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPIccCardData_h */
