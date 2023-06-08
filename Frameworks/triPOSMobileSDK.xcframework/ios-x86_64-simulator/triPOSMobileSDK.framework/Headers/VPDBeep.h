///
/// \file VPDBeep.h
///

#ifndef VPDBeep_h
#define VPDBeep_h

///
/// \protocol VPDBeep
///
/// \brief POI beep protocol
///
/// The VPDBeep protocol defines methods a POI display input must implement.
///
@protocol VPDBeep <VPDDevice>

@required

///
/// \brief Sounds an error beep on the POI device.
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while displaying the message.
///
/// \return YES if successful, NO otherwise.
///
-(BOOL)errorBeep:(NSError **)error;

@end

#endif /* VPDBeep_h */
