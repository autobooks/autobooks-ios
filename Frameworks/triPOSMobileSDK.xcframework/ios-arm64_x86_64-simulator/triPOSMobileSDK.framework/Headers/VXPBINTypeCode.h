///
/// \file VXPBINTypeCode.h
///

#ifndef VXPBINTypeCode_h
#define VXPBINTypeCode_h

///
/// \enum VXPBINTypeCode
///
typedef enum _VXPBINTypeCode
{
    /// This field is not used
    VXPBINTypeCodeNotSet = VXPEnumNotSet,
    /// Not found
    VXPBINTypeCodeNotFound = 0,
    /// Debit
    VXPBINTypeCodeDebit,
    /// Health care
    VXPBINTypeCodeHealthCare,
    /// Commercial
    VXPBINTypeCodeCommercial,
    /// Other
    VXPBINTypeCodeOther,
    /// Prepaid debit
    VXPBINTypeCodePrepaidDebit,
}   VXPBINTypeCode;

#endif /* VXPBINTypeCode_h */
