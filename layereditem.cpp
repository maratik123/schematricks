#include "layereditem.h"
#include <QPainter>

namespace SchemaItem {

LayeredItem::LayeredItem(const QPen &outline, const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(i, j, cellSize, parent)
{
    setOutline(outline);
    setInnerBrush(innerBrush);
}

LayeredItem::LayeredItem(const QPen &outline, const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(gridPos, cellSize, parent)
{
    setOutline(outline);
    setInnerBrush(innerBrush);
}

LayeredItem::LayeredItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(i, j, cellSize, parent)
{

}

LayeredItem::LayeredItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(gridPos, cellSize, parent)
{

}

void LayeredItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(_outline);
    painter->setBrush(_innerBrush);
    const qreal innerMargin = gridSize() * 0.1;
    const QRectF &rect = boundingRect().adjusted(innerMargin, innerMargin, - innerMargin, - innerMargin);
    painter->drawRect(rect);
}

void LayeredItem::setInnerBrush(const QBrush &innerBrush)
{
    _innerBrush = innerBrush;
    update();
}

void LayeredItem::setOutline(const QPen &outline)
{
    _outline = outline;
    update();
}

}
