#include "siliconpitem.h"
#include "layeredcolorhelper.h"

namespace SchemaItem {

namespace {
const static LayeredColorHelper siliconPDef(Qt::yellow, Qt::black);
}

SiliconPItem::SiliconPItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconPDef.outline(), siliconPDef.brush(), i, j, cellSize, parent)
{
}

SiliconPItem::SiliconPItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconPDef.outline(), siliconPDef.brush(), gridPos, cellSize, parent)
{
}

}
