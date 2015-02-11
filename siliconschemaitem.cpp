#include "siliconschemaitem.h"
#include "schemaitemtyperegistry.h"

SiliconSchemaItem::SiliconSchemaItem(const QPen &outline, const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent)
    : LayeredSchemaItem(outline, innerBrush, i, j, cellSize, parent)
{
    setZValue(SchemaItemLevel::Silicon);
}


SiliconSchemaItem::SiliconSchemaItem(const QPen &outline, const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : LayeredSchemaItem(outline, innerBrush, gridPos, cellSize, parent)
{
    setZValue(SchemaItemLevel::Silicon);
}
