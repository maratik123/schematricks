#include "siliconitem.h"
#include "itemtyperegistry.h"

namespace SchemaItem {

SiliconItem::SiliconItem(const QPen &outline, const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(outline, innerBrush, i, j, cellSize, parent)
{
    setZValue(ItemLevel::Silicon);
}


SiliconItem::SiliconItem(const QPen &outline, const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(outline, innerBrush, gridPos, cellSize, parent)
{
    setZValue(ItemLevel::Silicon);
}

}
