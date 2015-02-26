#include "siliconitem.h"
#include "itemtyperegistry.h"

namespace SchemaItem {

SiliconItem::SiliconItem(const QPen &pen, const QBrush &brush, int i, int j, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(pen, brush, i, j, cellSize, parent)
{
    setZValue(ItemLevel::Silicon);
}


SiliconItem::SiliconItem(const QPen &pen, const QBrush &brush, QPoint gridPos, qreal cellSize, QGraphicsItem *parent)
    : LayeredItem(pen, brush, gridPos, cellSize, parent)
{
    setZValue(ItemLevel::Silicon);
}

}
