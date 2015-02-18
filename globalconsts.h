#ifndef GLOBALCONSTS
#define GLOBALCONSTS

#ifdef DEFINE_VARIABLES
#define EXTERN /* nothing */
#else
#define EXTERN extern
#endif /* DEFINE_VARIABLES */

namespace SchemaItem {
class LayeredColorHelper;

EXTERN LayeredColorHelper *metalDef;
EXTERN LayeredColorHelper *siliconNDef;
EXTERN LayeredColorHelper *siliconPDef;
EXTERN LayeredColorHelper *viaDef;

}

#endif // GLOBALCONSTS
