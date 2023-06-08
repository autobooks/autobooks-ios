#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef XMLDICTUTIL_H_
#define XMLDICTUTIL_H_


#include <objc/objc.h>


#undef EXTERN
#ifdef XMLDICTUTIL_C_
#define EXTERN
#else
#define EXTERN extern
#endif


/*
** defines
*/


/*
** definitions
*/


/*
** prototypes
*/
EXTERN void             *vxpXmlMalloc(size_t size);
EXTERN void             *vxpXmlCalloc(size_t nmemb, size_t size);
EXTERN void             *vxpXmlRealloc(void *ptr, size_t size);
EXTERN void             vxpXmlFree(void *ptr);
EXTERN int              vxpXmlCompareNoCase(const char *s1, const char *s2);
EXTERN int              vxpXmlCompareNoCaseCount(const char *s1, const char *s2, int count);
EXTERN BOOL             vxpXmlStringToBool(const char *string, int length);
EXTERN unsigned long    vxpXmlStringToUlong(const char *string, int length);
EXTERN double           vxpXmlStringToDouble(const char *string, int length);
EXTERN int              vxpXmlToBase64Length(const void *data, int dataLength);
EXTERN int              vxpXmlToBase64(const void *data, int dataLength, char *base64, int base64Size);
EXTERN int              vxpXmlFromBase64(const char *base64, int base64Length, void *data, int dataSize);
EXTERN int              vxpXmlToEscapedLength(const char *data, int dataLength);
EXTERN int              vxpXmlToEscaped(const char *data, int dataLength, char *escaped, int escapedSize);
EXTERN int              vxpXmlFromEscaped(const char *escaped, int escapedLength, char *data, int dataSize);


#endif /*XMLDICTUTIL_H_*/


