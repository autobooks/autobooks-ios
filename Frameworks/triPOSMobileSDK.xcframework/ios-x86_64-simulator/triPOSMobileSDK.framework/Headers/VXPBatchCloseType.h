///
/// \file VXPBatchCloseType.h
///

#ifndef VXPBatchCloseType_h
#define VXPBatchCloseType_h

///
/// \enum VXPBatchCloseType
///
typedef enum _VXPBatchCloseType
{
    /// This field is not used
    VXPBatchCloseTypeNotSet = VXPEnumNotSet,
    /// Regular close
    VXPBatchCloseTypeRegular = 0,
    /// Force close
    VXPBatchCloseTypeForce,
}   VXPBatchCloseType;

#endif /* VXPBatchCloseType_h */
