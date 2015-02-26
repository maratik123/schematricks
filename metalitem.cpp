#include "metalitem.h"
#include "layeredcolorhelper.h"
#include "globalconsts.h"

namespace SchemaItem {

MetalItem::MetalItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(metalDef->pen(), metalDef->brush(), i, j, cellSize, parent)
{
    setZValue(ItemLevel::Metal);
}

MetalItem::MetalItem(QPoint gridPos, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(metalDef->pen(), metalDef->brush(), gridPos, cellSize, parent)
{
    setZValue(ItemLevel::Metal);
}

}
