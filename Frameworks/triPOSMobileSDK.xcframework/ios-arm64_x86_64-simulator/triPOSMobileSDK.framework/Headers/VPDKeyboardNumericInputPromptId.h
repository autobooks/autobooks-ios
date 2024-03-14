///
/// \file VPDKeyboardNumericInputPromptId.h
///

#ifndef VPDKeyboardNumericInputPromptId_h
#define VPDKeyboardNumericInputPromptId_h

///
/// \enum VPDKeyboardNumericInputPromptId
///
typedef enum _VPDKeyboardNumericInputPromptId
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDKeyboardNumericInputPromptIdMinimum,
#endif

    /// Postal code entry
    VPDKeyboardNumericInputPromptIdPostalCode = _VPDKeyboardNumericInputPromptIdMinimum,
    /// Cashback entry, whole dollar amounts only
    VPDKeyboardNumericInputPromptIdCashback,
    /// Tip entry
    VPDKeyboardNumericInputPromptIdTip,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VPDKeyboardNumericInputPromptIdMaximum
#endif
}   VPDKeyboardNumericInputPromptId;

#endif /* VPDKeyboardNumericInputPromptId_h */
