///
/// \file VXPBooleanType.h
///

#ifndef VXPBooleanType_h
#define VXPBooleanType_h

#import "VXPDefines.h"

///
/// \enum VXPBooleanType
///
typedef enum _VXPBooleanType
{
    /// This field is not used
    VXPBooleanTypeNotSet = VXPEnumNotSet,
    /// Null
    VXPBooleanTypeNull = -1,
    /// False
    VXPBooleanTypeFalse,
    /// True
    VXPBooleanTypeTrue,
}   VXPBooleanType;

#endif /* VXPBooleanType_h */
