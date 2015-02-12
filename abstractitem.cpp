#include "abstractitem.h"
#include "utils.h"

namespace SchemaItem {

AbstractItem::AbstractItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : QAbstractGraphicsShapeItem(parent), _cellSize(cellSize)
{
    setGridPos(i, j);
}

AbstractItem::AbstractItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : QAbstractGraphicsShapeItem(parent), _cellSize(cellSize)
{
    setGridPos(gridPos);
}

void AbstractItem::setI(int i)
{
    const auto &checker = [this, i] { return _gridPos.x() == i; };
    auto updater = [this, i]() mutable { _gridPos.setX(i); };
    setGridPos(checker, updater);
}

void AbstractItem::setJ(int j)
{
    const auto &checker = [this, j] { return _gridPos.y() == j; };
    auto updater = [this, j]() mutable { _gridPos.setY(j); };
    setGridPos(checker, updater);
}

void AbstractItem::setGridPos(const QPoint &gridPos)
{
    const auto &checker = [this, &gridPos] { return _gridPos == gridPos; };
    auto updater = [this, &gridPos]() mutable { _gridPos = gridPos; };
    setGridPos(checker, updater);
}

}
