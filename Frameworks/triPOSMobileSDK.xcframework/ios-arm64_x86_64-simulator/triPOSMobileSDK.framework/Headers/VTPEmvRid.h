///
/// \file VTPEmvRid.h
///

#ifndef VTPEmvRid_h
#define VTPEmvRid_h

#import "VTPEmvAid.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \class VTPEmvRid
///
/// \brief The EMV RID class
///
/// This class defines the methods and properties for a registered application provider identifier (RID).
///
@interface VTPEmvRid : NSObject

///
/// \brief Gets or sets the registered application provider identifier (RID)
///
/// This property gets or sets the registered application provider identifier (RID).
///
@property (retain, nonatomic) NSString *rid;

///
/// \brief Gets or sets the name
///
/// This property gets or sets the name.
///
@property (retain, nonatomic) NSString *name;

///
/// \brief Gets or sets the target percentage used for random selection
///
/// This property gets or sets the target percentage used for random selection, 0-99.
///
@property (nonatomic) unsigned char randomSelectionTargetPercentage;

///
/// \brief Gets or sets the terminal floor limit
///
/// This property gets or sets the terminal floor limit.
///
@property (retain, nonatomic) NSDecimalNumber *terminalFloorLimit;

///
/// \brief Gets or sets the threshold used for random selection
///
/// This property gets or sets the threshold used for random selection. Must be 0 or a positive value less than TerminalFloorLimit.
///
@property (retain, nonatomic) NSDecimalNumber *randomSelectionThreshold;

///
/// \brief Gets or sets the maximum target percentage used for random selection
///
/// This property gets or sets the maximum target percentage used for random selection, 0-99.
///
@property (nonatomic) unsigned char randomSelectionMaximumTargetPercentage;

///
/// \brief Gets or sets the terminal action code (TAC) default
///
/// This property gets or sets the terminal action code (TAC) default.
///
@property (retain, nonatomic) NSString *terminalActionCodeDefault;

///
/// \brief Gets or sets the terminal action code (TAC) denial
///
/// This property gets or sets the terminal action code (TAC) denial.
///
@property (retain, nonatomic) NSString *terminalActionCodeDenial;

///
/// \brief Gets or sets the terminal action code (TAC) online
///
/// This property gets or sets the terminal action code (TAC) online.
///
@property (retain, nonatomic) NSString *terminalActionCodeOnline;

///
/// \brief Gets or sets the default Transaction Certificate Data Object List (TDOL)
///
/// This property gets or sets the default Transaction Certificate Data Object List (TDOL).
///
@property (retain, nonatomic) NSString *defaultTransactionCertificateDataObjectList;

///
/// \brief Gets or sets the default Dynamic Data Authentication Data Object List (DDOL)
///
/// This property gets or sets the default Dynamic Data Authentication Data Object List (DDOL).
///
@property (retain, nonatomic) NSString *defaultDynamicDataAuthenticationDataObjectList;

///
/// \brief Gets or sets a value indicating whether this AID (RID + PIX) must match exactly the AID in the card
///
/// This property gets or sets a value indicating whether this AID (RID + PIX) must match exactly the AID in the card, including the length, or only match up to the length of this AID (RID + PIX).
///
@property (nonatomic) BOOL applicationPartialMatch;

///
/// \brief Gets or sets a value indication whether a selection prompt will appear for cards with multiple applications
///
/// This property gets or sets a value indication whether a selection prompt will appear for cards with multiple applications.
///
@property (nonatomic) BOOL applicationSelectionPrompt;

///
/// \brief Gets or sets the application identifiers (AID)
///
/// This property gets or sets the application identifiers (AID).
///
@property (retain, nonatomic) NSArray<VTPEmvAid *> *aids;


///
/// \brief Gets or sets the contactless transaction limit
///
/// This property gets or sets the contactless transaction limit.
///
@property (retain, nonatomic) NSDecimalNumber *contactlessTransactionLimit;

///
/// \brief Gets or sets the contactless transaction limit with ODVC
///
/// This property gets or sets the contactless transaction limit with ODVC.
///
@property (retain, nonatomic) NSDecimalNumber *contactlessTransactionLimitOdvc;

///
/// \brief Gets or sets the contactless CVM required limit
///
/// This property gets or sets the contactless CVM required limit.
///
@property (retain, nonatomic) NSDecimalNumber *contactlessCvmRequiredLimit;


///
/// \brief Gets or sets the contactless floor limit
///
/// This property gets or sets the contactless floor limit.
///
@property (retain, nonatomic) NSDecimalNumber *contactlessFloorLimit;


///
/// \brief Validates the configuration.
///
/// This method validates the configuration. While some items may have their values verified, others are only checked to ensure they are not nil and/or empty.
///
/// \param error Pointer to NSError object. If the enable fails, error information is returned in this object. This parameter may be nil.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)validate:(NSError **)error;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTPEmvRid_h */
