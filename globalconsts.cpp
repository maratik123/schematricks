#define DEFINE_VARIABLES
#include "globalconsts.h"
#undef DEFINE_VARIABLES

#include "layeredcolorhelper.h"

namespace {

class InitGlobalConsts {
public:
    InitGlobalConsts() {
        SchemaItem::metalDef = new SchemaItem::LayeredColorHelper(Qt::gray, Qt::black);
        SchemaItem::siliconNDef = new SchemaItem::LayeredColorHelper(Qt::red, Qt::black);
        SchemaItem::siliconPDef = new SchemaItem::LayeredColorHelper(Qt::yellow, Qt::black);
        SchemaItem::viaDef = new SchemaItem::LayeredColorHelper(Qt::NoBrush, Qt::black);
    }
    ~InitGlobalConsts() {
        delete SchemaItem::viaDef;
        delete SchemaItem::siliconPDef;
        delete SchemaItem::siliconNDef;
        delete SchemaItem::metalDef;
    }
};

const static InitGlobalConsts initGlobalConsts;
}
