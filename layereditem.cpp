#include "layereditem.h"
#include <QPainter>

namespace SchemaItem {

LayeredItem::LayeredItem(const QPen &pen, const QBrush &brush, int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(i, j, cellSize, parent)
{
    setPen(pen);
    setBrush(brush);
}

LayeredItem::LayeredItem(const QPen &pen, const QBrush &brush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(gridPos, cellSize, parent)
{
    setPen(pen);
    setBrush(brush);
}

void LayeredItem::schemaPaint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    const qreal innerMargin = gridSize() * 0.1;
    const QRectF &rect = boundingRect().adjusted(innerMargin, innerMargin, - innerMargin, - innerMargin);
    painter->drawRect(rect);
}

}
