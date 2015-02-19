#define DEFINE_VARIABLES
#include "globalconsts.h"
#undef DEFINE_VARIABLES

#include "layeredcolorhelper.h"

namespace {

namespace SI = SchemaItem;

class InitGlobalConsts {
public:
    InitGlobalConsts() {
        SI::metalDef = new SI::LayeredColorHelper(Qt::gray, Qt::black);
        SI::siliconNDef = new SI::LayeredColorHelper(Qt::red, Qt::black);
        SI::siliconPDef = new SI::LayeredColorHelper(Qt::yellow, Qt::black);
        SI::viaDef = new SI::LayeredColorHelper(Qt::NoBrush, Qt::black);
    }
    ~InitGlobalConsts() {
        delete SI::viaDef;
        delete SI::siliconPDef;
        delete SI::siliconNDef;
        delete SI::metalDef;
    }
};

const static InitGlobalConsts initGlobalConsts;
}
