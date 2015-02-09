#include "siliconpschemaitem.h"
#include "layeredcolorhelper.h"

namespace {
const static LayeredColorHelper siliconPDef(Qt::yellow, Qt::black);
}

SiliconPSchemaItem::SiliconPSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : SiliconSchemaItem(siliconPDef.outline(), siliconPDef.brush(), i, j, cellSize, parent)
{
}

SiliconPSchemaItem::SiliconPSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : SiliconSchemaItem(siliconPDef.outline(), siliconPDef.brush(), gridPos, cellSize, parent)
{
}
