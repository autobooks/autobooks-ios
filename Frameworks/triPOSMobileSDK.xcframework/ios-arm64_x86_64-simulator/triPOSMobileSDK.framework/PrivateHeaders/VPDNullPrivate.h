///
/// \file VPDNullPrivate.h
///

#ifndef VPDNullPrivate_h
#define VPDNullPrivate_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifndef VPDNull_h
@class VPDNull;
#endif

#ifndef VTPCardData_h
@class VTPCardData;
#endif

#ifndef VTPBluetoothDevice_h
@class VTPBluetoothDevice;
#endif

@protocol VPDNullPrivate

@property (nonatomic) int cardInputCapabilityReturn;

@property (retain, nonatomic) NSMutableArray<VTPCardData *> *cardInputReturns;

@property (nonatomic) NSInteger numberOfChoicesAllowedReturn;

@property (retain, nonatomic) NSMutableArray<NSNumber *> *choiceInputReturns;

@property (retain, nonatomic) NSMutableArray<NSString *> *keyboardInputReturns;

@property (retain, nonatomic) NSMutableArray<NSString *> *pinInputReturns;

@property (retain, nonatomic) NSMutableArray<NSNumber *> *yesNoInputReturns;

@property (retain, nonatomic) NSMutableArray<VTPBluetoothDevice *> *deviceScanResultReturns;

@end

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VPDNullPrivate_h */
