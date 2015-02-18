#include "metalitem.h"
#include "layeredcolorhelper.h"
#include "globalconsts.h"

namespace SchemaItem {

MetalItem::MetalItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(metalDef->outline(), metalDef->brush(), i, j, cellSize, parent)
{
    setZValue(ItemLevel::Metal);
}

MetalItem::MetalItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(metalDef->outline(), metalDef->brush(), gridPos, cellSize, parent)
{
    setZValue(ItemLevel::Metal);
}

}
