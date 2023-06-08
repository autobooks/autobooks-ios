///
/// \file VTCFinancialTrackDataParseStatus.h
///

#ifndef VTCFinancialTrackDataParseStatus_h
#define VTCFinancialTrackDataParseStatus_h

#ifndef DOXYGEN_SHOULD_SKIP_THIS

///
/// \enum VTCFinancialTrackDataParseStatus
/// Card data parse errors
///
typedef enum _VTCFinancialTrackDataParseStatus
{
    /// Success
    VTCFinancialTrackDataParseStatusSuccess,
    /// Unknown error
    VTCFinancialTrackDataParseStatusUnknown,
    /// Track empty
    VTCFinancialTrackDataParseStatusTrackEmpty,
    /// Invalid size
    VTCFinancialTrackDataParseStatusInvalidSize,
    /// Invalid account
    VTCFinancialTrackDataParseStatusInvalidAccountNumber,
    /// Invalid name
    VTCFinancialTrackDataParseStatusInvalidName,
    /// Separator error
    VTCFinancialTrackDataParseStatusSeparatorError,
}   VTCFinancialTrackDataParseStatus;

#endif /* !DOXYGEN_SHOULD_SKIP_THIS */

#endif /* VTCFinancialTrackDataParseStatus_h */
