#include "siliconnitem.h"
#include "layeredcolorhelper.h"

namespace SchemaItem {

namespace {
const static LayeredColorHelper siliconNDef(Qt::red, Qt::black);
}

SiliconNItem::SiliconNItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconNDef.outline(), siliconNDef.brush(), i, j, cellSize, parent)
{
}

SiliconNItem::SiliconNItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconNDef.outline(), siliconNDef.brush(), gridPos, cellSize, parent)
{
}

}
