#include "siliconpitem.h"
#include "layeredcolorhelper.h"
#include "globalconsts.h"

namespace SchemaItem {

SiliconPItem::SiliconPItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconPDef->pen(), siliconPDef->brush(), i, j, cellSize, parent)
{
}

SiliconPItem::SiliconPItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconPDef->pen(), siliconPDef->brush(), gridPos, cellSize, parent)
{
}

}
