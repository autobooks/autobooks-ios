#ifndef XMLDICT_H_
#define XMLDICT_H_

#include "XmlDictUtil.h"


#undef EXTERN
#ifdef XMLDICT_C_
#define EXTERN
#else
#define EXTERN extern
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*
** defines
*/
typedef void *  VXPXMLDICTHANDLE;

#define INVALID_VXPXMLDICTHANDLE    ((VXPXMLDICTHANDLE)-1)

#define IS_VALID_VXPXMLDICTHANDLE   vxpXmlDictIsValidHandle//(h)   (((h) != INVALID_XMLDICTHANDLE && (h) != NULL) ? TRUE : FALSE)


/*
** definitions
*/
#ifndef XMLDICT_C_

EXTERN const char *VXPXMLDICTBOOL_True;
EXTERN const char *VXPXMLDICTBOOL_False;

#endif


typedef struct _VXPXMLATTRDEF
    {
    char        *name;

    char        *value;
    }   VXPXMLATTRDEF, *PVXPXMLATTRDEF;


/*
** prototypes
*/
EXTERN BOOL             vxpXmlDictIsValidHandle(VXPXMLDICTHANDLE xml);

EXTERN VXPXMLDICTHANDLE vxpXmlDictCreate(const char *name, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN void             vxpXmlDictDestroy(VXPXMLDICTHANDLE xml);

EXTERN BOOL             vxpXmlDictAddDict(VXPXMLDICTHANDLE xml, VXPXMLDICTHANDLE dict);
EXTERN BOOL             vxpXmlDictRemoveDict(VXPXMLDICTHANDLE xml, VXPXMLDICTHANDLE dict);

EXTERN VXPXMLDICTHANDLE vxpXmlDictAddClass(VXPXMLDICTHANDLE xml, const char *name, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN VXPXMLDICTHANDLE vxpXmlDictGetClass(VXPXMLDICTHANDLE xml, const char *name);
EXTERN BOOL             vxpXmlDictDeleteClass(VXPXMLDICTHANDLE xml, const char *name);

EXTERN VXPXMLDICTHANDLE vxpXmlDictAddElement(VXPXMLDICTHANDLE xml, const char *name, const char *value, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN VXPXMLDICTHANDLE vxpXmlDictAddElementBool(VXPXMLDICTHANDLE xml, const char *name, BOOL value, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN VXPXMLDICTHANDLE vxpXmlDictAddElementLong(VXPXMLDICTHANDLE xml, const char *name, long value, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN VXPXMLDICTHANDLE vxpXmlDictAddElementUlong(VXPXMLDICTHANDLE xml, const char *name, unsigned long value, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN VXPXMLDICTHANDLE vxpXmlDictAddElementDouble(VXPXMLDICTHANDLE xml, const char *name, double value, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN VXPXMLDICTHANDLE vxpXmlDictAddElementAmount(VXPXMLDICTHANDLE xml, const char *name, double value, const VXPXMLATTRDEF attributes[], int attributeCount);
EXTERN VXPXMLDICTHANDLE vxpXmlDictGetElement(VXPXMLDICTHANDLE xml, const char *name);
EXTERN const char       *vxpXmlDictGetElementString(VXPXMLDICTHANDLE xml, const char *name, const char *defaultValue);
EXTERN BOOL             vxpXmlDictGetElementBool(VXPXMLDICTHANDLE xml, const char *name, BOOL defaultValue);
EXTERN long             vxpXmlDictGetElementLong(VXPXMLDICTHANDLE xml, const char *name, long defaultValue);
EXTERN unsigned long    vxpXmlDictGetElementUlong(VXPXMLDICTHANDLE xml, const char *name, unsigned long defaultValue);
EXTERN double           vxpXmlDictGetElementDouble(VXPXMLDICTHANDLE xml, const char *name, double defaultValue);
EXTERN BOOL             vxpXmlDictDeleteElement(VXPXMLDICTHANDLE xml, const char *name);

EXTERN const char       *vxpXmlDictGetName(VXPXMLDICTHANDLE xml);
EXTERN VXPXMLDICTHANDLE vxpXmlDictGetParent(VXPXMLDICTHANDLE xml);
EXTERN VXPXMLDICTHANDLE vxpXmlDictGetChild(VXPXMLDICTHANDLE xml);
EXTERN VXPXMLDICTHANDLE vxpXmlDictGetSibling(VXPXMLDICTHANDLE xml);

EXTERN BOOL             vxpXmlDictSetValue(VXPXMLDICTHANDLE xml, const char *value);
EXTERN BOOL             vxpXmlDictSetValueBool(VXPXMLDICTHANDLE xml, BOOL value);
EXTERN BOOL             vxpXmlDictSetValueLong(VXPXMLDICTHANDLE xml, long value);
EXTERN BOOL             vxpXmlDictSetValueUlong(VXPXMLDICTHANDLE xml, unsigned long value);
EXTERN BOOL             vxpXmlDictSetValueDouble(VXPXMLDICTHANDLE xml, double value);
EXTERN BOOL             vxpXmlDictSetValueAmount(VXPXMLDICTHANDLE xml, double value);
EXTERN const char       *vxpXmlDictGetValue(VXPXMLDICTHANDLE xml, const char *defaultValue);
EXTERN BOOL             vxpXmlDictGetValueBool(VXPXMLDICTHANDLE xml, BOOL defaultValue);
EXTERN long             vxpXmlDictGetValueLong(VXPXMLDICTHANDLE xml, long defaultValue);
EXTERN unsigned long    vxpXmlDictGetValueUlong(VXPXMLDICTHANDLE xml, unsigned long defaultValue);
EXTERN double           vxpXmlDictGetValueDouble(VXPXMLDICTHANDLE xml, double defaultValue);

EXTERN int              vxpXmlDictGetAttributes(VXPXMLDICTHANDLE xml, PVXPXMLATTRDEF *attributes);

EXTERN BOOL             vxpXmlDictIsRoot(VXPXMLDICTHANDLE xml);
EXTERN BOOL             vxpXmlDictIsClass(VXPXMLDICTHANDLE xml);
EXTERN BOOL             vxpXmlDictIsElement(VXPXMLDICTHANDLE xml);
EXTERN BOOL             vxpXmlDictHasChild(VXPXMLDICTHANDLE xml);
EXTERN BOOL             vxpXmlDictHasValue(VXPXMLDICTHANDLE xml);
EXTERN BOOL             vxpXmlDictHasAttributes(VXPXMLDICTHANDLE xml);

EXTERN int              vxpXmlDictSerialize(VXPXMLDICTHANDLE xml, char **output);
EXTERN VXPXMLDICTHANDLE vxpXmlDictDeserialize(const char *message, int length);

EXTERN void             vxpXmlDictFree(char *output);

#endif /*XMLDICT_H_*/

