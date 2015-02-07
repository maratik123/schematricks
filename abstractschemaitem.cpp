#include "abstractschemaitem.h"
#include "utils.h"

AbstractSchemaItem::AbstractSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : QAbstractGraphicsShapeItem(parent), _cellSize(cellSize)
{
    setGridPos(i, j);
}

AbstractSchemaItem::AbstractSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : QAbstractGraphicsShapeItem(parent), _cellSize(cellSize)
{
    setGridPos(gridPos);
}

void AbstractSchemaItem::setI(int i)
{
    auto checker = [this, i] { return _gridPos.x() == i; };
    auto updater = [this, i]() mutable { _gridPos.setX(i); };
    setGridPos(checker, updater);
}

void AbstractSchemaItem::setJ(int j)
{
    auto checker = [this, j] { return _gridPos.y() == j; };
    auto updater = [this, j]() mutable { _gridPos.setY(j); };
    setGridPos(checker, updater);
}

void AbstractSchemaItem::setGridPos(const QPoint &gridPos)
{
    auto checker = [this, &gridPos] { return _gridPos == gridPos; };
    auto updater = [this, &gridPos]() mutable { _gridPos = gridPos; };
    setGridPos(checker, updater);
}

template<class Checker, class Updater>
void AbstractSchemaItem::setGridPos(const Checker &checker, Updater &updater)
{
    if(checker())
        return;
    prepareGeometryChange();
    updater();
    update();
}
