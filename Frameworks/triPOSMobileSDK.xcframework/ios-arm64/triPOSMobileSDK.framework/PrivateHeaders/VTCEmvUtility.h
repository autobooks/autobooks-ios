///
/// \file VTCEmvUtility.h
///

#ifndef VTCEmvUtility_h
#define VTCEmvUtility_h

#import "VTCOfflineProcessingResult.h"
#import "VTCCvmPerformed.h"
#import "VTCTlvUtility.h"
#import "VTPIccCardData.h"
#import "VTCEmvBrand.h"
#import "VTPMarketCode.h"
#import "VTPConfiguration.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS

@interface VTCEmvUtility : NSObject

+(VTCOfflineProcessingResult)getOfflineProcessingResultFromTags:(VTCTlvCollection)tags;

+(VTCCvmPerformed)getCvmPerformedFromTags:(VTCTlvCollection)tags pinVerifiedOffline:(BOOL *)pinVerifiedOffline;

+(BOOL)isIccCardDebit:(VTPIccCardData *)iccCardData;

+(BOOL)isCommonUsDebitAid:(NSString *)aid;

+(VTCEmvBrand)getBrandForAid:(NSString *)aid;

+(BOOL)isSignatureRequiredForNoCvm:(NSString *)aid marketCode:(VTPMarketCode)marketCode transactionAmount:(NSDecimalNumber *)transactionAmount;

+(BOOL)isContactlessMsdSupportedForAid:(NSString *)aid;
+(BOOL)isFastQuickChipSupported:(NSString *)aid;

+(BOOL)doesApplicationUsuageControlAllowCashback:(VTCTlvCollection) tags;

+(BOOL)doesApplicationApplicationUsuageControlAllowCashbackForCountryCodes:(VTCTlvCollection) tags applicationUsuageControl:(NSData *)applicationUsuageControl;

+(BOOL)isDeviceStandardEmvCertifiedForSelectedPaymentPaymentProcesser:(VTPConfiguration*) configuration;

+(BOOL)isDeviceContactlessCertifiedForSelectedPaymentPaymentProcesser:(VTPConfiguration*) configuration;

+(BOOL)isDeviceCashbackCertifiedForSelectedPaymentPaymentProcesser:(VTPConfiguration*) configuration;

+(BOOL)isDeviceQuickChipCertifiedForSelectedPaymentPaymentProcesser:(VTPConfiguration*) configuration;

+(BOOL) isQuickChipEnabled:(VTPConfiguration*) configuration;

+(BOOL)isDiscoverAid:(NSString *)aid;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCEmvUtility_h */
