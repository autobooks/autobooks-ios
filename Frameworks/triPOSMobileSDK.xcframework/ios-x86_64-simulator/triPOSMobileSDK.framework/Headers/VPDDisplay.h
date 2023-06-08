///
/// \file VPDDisplay.h
///

#ifndef VPDDisplay_h
#define VPDDisplay_h

///
/// \protocol VPDDisplay
///
/// \brief POI display protocol
///
/// The VPDDisplay protocol defines methods a POI display must implement.
///
@protocol VPDDisplay <VPDDevice>

@required

///
/// \brief Display a message
///
/// \param message The message to be displayed.
///
/// \param error A pointer to an NSError. This parameter is only used if an error occurs while displaying the message.
///
/// \return YES if successful, NO otherwise
///
-(BOOL)displayMessage:(NSString *)message error:(NSError **)error;

@end

#endif /* VPDDisplay_h */
