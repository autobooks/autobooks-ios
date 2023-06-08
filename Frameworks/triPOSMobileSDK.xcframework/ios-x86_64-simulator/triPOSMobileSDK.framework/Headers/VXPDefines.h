///
/// \file VXPDefines.h
///

#ifndef VXPDefines_h
#define VXPDefines_h

///
/// \def VXPClassNotSet
/// \brief Class not set
///
/// Indicates that the class is not present in a request or response.
///
#define VXPClassNotSet               nil

///
/// \def VXPStringNotSet
/// \brief String not set
///
/// Indicates that the string is not present in a request or response.
///
#define VXPStringNotSet              (NSString *)VXPClassNotSet

///
/// \def VXPIntegerNotSet
/// \brief Integer not set
///
/// Indicates that the integer is not present in a request or response.
///
#define VXPIntegerNotSet             (NSNumber *)VXPClassNotSet

///
/// \def VXPAmountNotSet
/// \brief Amount not set
///
/// Indicates that the amount is not present in a request or response.
///
#define VXPAmountNotSet              (NSDecimalNumber *)VXPClassNotSet

///
/// \def VXPDateTimeNotSet
/// \brief Date/time not set
///
/// Indicates that the date/time is not present in a request or response.
///
#define VXPDateTimeNotSet            (NSDate *)VXPClassNotSet

///
/// \def VXPEnumNotSet
/// \brief Enumeration not set
///
/// Indicates that the enumeration is not present in a request or response.
///
#define VXPEnumNotSet                INT_MIN

#endif /* VXPDefines_h */
