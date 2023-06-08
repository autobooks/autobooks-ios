///
/// \file VXPBatchQueryType.h
///

#ifndef VXPBatchQueryType_h
#define VXPBatchQueryType_h

///
/// \enum VXPBatchQueryType
///
typedef enum _VXPBatchQueryType
{
    /// This field is not used
    VXPBatchQueryTypeNotSet = VXPEnumNotSet,
    /// Total query
    VXPBatchQueryTypeTotal = 0,
    /// Item query
    VXPBatchQueryTypeItem,
}   VXPBatchQueryType;

#endif /* VXPBatchQueryType_h */
