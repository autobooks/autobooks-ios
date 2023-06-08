///
/// \file VTPEmvData.h
///

#ifndef VTPEmvData_h
#define VTPEmvData_h

#import <Foundation/Foundation.h>

#import "VTCTlvUtility.h"

///
/// \brief The definition for EMV data returned in a response
///
@interface VTPEmvData : NSObject

///
/// \brief Gets the application identifier
///
/// This property gets the application identifier (AID) as described in ISO/IEC 7816-5.
///
@property (retain, nonatomic, readonly) NSString *applicationIdentifier;

///
/// \brief Gets the application label associated with the AID
///
/// This property gets the application label associated with the AID as described in ISO/IEC 7816-5
///
@property (retain, nonatomic, readonly) NSString *applicationLabel;

///
/// \brief Gets the application preferred name associated with the AID
///
/// This property gets the application preferred name associated with the AID as described in ISO/IEC 7816-5
///
@property (retain, nonatomic, readonly) NSString *applicationPreferredName;

///
/// \brief Gets the EMV cryptogram type and value.
///
/// This property gets the EMV cryptogram type and value. It is a preferred best practice to include this data element on the receipt, but is not mandatory. This field contains cryptogram type followed by the cryptogram value.
///
@property (retain, nonatomic, readonly) NSString *cryptogram;

///
/// \brief Gets the application transaction counter (Tag 0x9F36)
///
/// This property gets the application transaction counter (Tag 0x9F36).
///
@property (retain, nonatomic, readonly) NSString *applicationTransactionCounter;

///
/// \brief Gets a collection of name/value pairs of additional EMV tags that are required to be printed on the receipt
///
/// This property gets a collection of name/value pairs of additional EMV tags that are required to be printed on the receipt.
///
@property (retain, nonatomic, readonly) NSArray<NSString *> *tags;

///
/// \brief Gets the code table index for displaying the Application Preferred Name
///
/// This property get the code table index for displaying the Application Preferred Name as described in ISO/IEC 8859.
///
@property (retain, nonatomic, readonly) NSString *issuerCodeTableIndex;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

-(instancetype)initWithTags:(VTCTlvCollection)tags isApproved:(BOOL)isApproved;

+(VTPEmvData *)emvDataWithTags:(VTCTlvCollection)tags isApproved:(BOOL)isApproved;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

@end

#endif /* VTPEmvData_h */
