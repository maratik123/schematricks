#include "layeredschemaitem.h"
#include <QPainter>

LayeredSchemaItem::LayeredSchemaItem(const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractSchemaItem(i, j, cellSize, parent)
{
    setInnerBrush(innerBrush);
}

LayeredSchemaItem::LayeredSchemaItem(const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractSchemaItem(gridPos, cellSize, parent)
{
    setInnerBrush(innerBrush);
}

LayeredSchemaItem::LayeredSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractSchemaItem(i, j, cellSize, parent)
{

}

LayeredSchemaItem::LayeredSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractSchemaItem(gridPos, cellSize, parent)
{

}

void LayeredSchemaItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::black);
    painter->setBrush(_innerBrush);
    qreal innerMargin = gridSize() * 0.1;
    const QRectF &rect = boundingRect().adjusted(innerMargin, innerMargin, - innerMargin, - innerMargin);
    painter->drawRect(rect);
}

void LayeredSchemaItem::setInnerBrush(const QBrush &innerBrush)
{
    if(_innerBrush == innerBrush)
        return;
    _innerBrush = innerBrush;
    update();
}
