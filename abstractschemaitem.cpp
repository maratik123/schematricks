#include "abstractschemaitem.h"
#include "utils.h"


AbstractSchemaItem::AbstractSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : QGraphicsRectItem(parent), _cellSize(cellSize), _i(i), _j(j)
{
    setRect(QRectF(i * cellSize, j * cellSize, cellSize, cellSize));
}
