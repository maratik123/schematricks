#include "siliconnschemaitem.h"
#include "layeredcolorhelper.h"

namespace {
const static LayeredColorHelper siliconNDef(Qt::red, Qt::black);
}

SiliconNSchemaItem::SiliconNSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : SiliconSchemaItem(siliconNDef.outline(), siliconNDef.brush(), i, j, cellSize, parent)
{
}

SiliconNSchemaItem::SiliconNSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : SiliconSchemaItem(siliconNDef.outline(), siliconNDef.brush(), gridPos, cellSize, parent)
{
}
