///
/// \file VTPPaymentProcessor.h
///

#ifndef VTPPaymentProcessor_h
#define VTPPaymentProcessor_h

///
/// \enum VTPPaymentProcessor
///
typedef enum _VTPPaymentProcessor
{
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPPaymentProcessorMinimum,
#endif
    
    /// Worldpay
    VTPPaymentProcessorWorldpay = _VTPPaymentProcessorMinimum,
    
    /// First Data
    VTPPaymentProcessorFirstData,
    
    /// TSYS
    VTPPaymentProcessorTsys,
    
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    _VTPPaymentProcessorMaximum
#endif
}   VTPPaymentProcessor;

#endif /* VTPPaymentProcessor_h */
