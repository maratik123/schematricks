#include "viaschemaitem.h"
#include "schemaitemtyperegistry.h"
#include <QPainter>
#include "layeredcolorhelper.h"

namespace {
    const static LayeredColorHelper viaColor(Qt::black, Qt::black);
}

ViaSchemaItem::ViaSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractSchemaItem(i, j, cellSize, parent)
{
    setZValue(SchemaItemLevel::Via);
}

ViaSchemaItem::ViaSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractSchemaItem(gridPos, cellSize, parent)
{
    setZValue(SchemaItemLevel::Via);
}

void ViaSchemaItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(viaColor.outline());
    painter->setBrush(Qt::NoBrush);
    qreal innerMargin = gridSize() * 0.4;
    const QRectF &rect = boundingRect().adjusted(innerMargin, innerMargin, - innerMargin, - innerMargin);
    painter->drawEllipse(rect);
}
