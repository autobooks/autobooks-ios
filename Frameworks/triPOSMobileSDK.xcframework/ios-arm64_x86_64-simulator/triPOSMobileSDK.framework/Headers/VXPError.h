///
/// \file VXPError.h
///

#ifndef VXPError_h
#define VXPError_h

///
/// \enum VXPError
/// Errors for Express messages
///
typedef enum _VXPError
{
    /// No error.
    VXPErrorNone,
    /// Unknown error.
    VXPErrorUnknown,
    /// The transaction completed with a communication error and was successfully reversed.
    VXPErrorReversed,
    /// The transaction completed with a communication error and a reversal is still necessary.
    VXPErrorNeedsReversal,
    /// Unable the serialize the Express request.
    VXPErrorSerializeError,
    /// The transaction completed with a communication error. A reversal is not necessary.
    VXPErrorSendReceiveError,
    /// The HTTPS request returned a non-success error code.
    VXPErrorStatusCodeError,
    /// Unable to  decode the HTTPS response.
    VXPErrorDecodeError,
    /// Unable to deserialize the Express response.
    VXPErrorDeserializeError,
    /// Hosted Payments result is cancelled.
    VXPErrorHostedPaymentsCancelled,
    /// Hosted Payments result is an error.
    VXPErrorHostedPaymentsError,
    /// Host Connection timeout.
    VXPErrorInvalidTimeout,
}   VXPError;

#endif /* VXPError_h */
