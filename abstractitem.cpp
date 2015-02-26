#include "abstractitem.h"
#include "utils.h"
#include <QPainter>

namespace SchemaItem {

AbstractItem::AbstractItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : QAbstractGraphicsShapeItem(parent), _cellSize(cellSize)
{
    setGridPos(i, j);
}

AbstractItem::AbstractItem(QPoint gridPos, qreal cellSize, QGraphicsItem *parent)
    : QAbstractGraphicsShapeItem(parent), _cellSize(cellSize)
{
    setGridPos(gridPos);
}

void AbstractItem::setI(int i)
{
    if(_gridPos.x() == i)
        return;
    prepareGeometryChange();
    _gridPos.setX(i);
    update();
}

void AbstractItem::setJ(int j)
{
    if(_gridPos.y() == j)
        return;
    prepareGeometryChange();
    _gridPos.setY(j);
    update();
}

void AbstractItem::setGridPos(QPoint gridPos)
{
    if(_gridPos == gridPos)
        return;
    prepareGeometryChange();
    _gridPos = gridPos;
    update();
}

void AbstractItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    schemaPaint(painter, option, widget);
}

}
