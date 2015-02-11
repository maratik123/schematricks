#include "metalschemaitem.h"
#include "layeredcolorhelper.h"

namespace {
const static LayeredColorHelper metalDef(Qt::gray, Qt::black);
}

MetalSchemaItem::MetalSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : LayeredSchemaItem(metalDef.outline(), metalDef.brush(), i, j, cellSize, parent)
{
    setZValue(SchemaItemLevel::Metal);
}

MetalSchemaItem::MetalSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : LayeredSchemaItem(metalDef.outline(), metalDef.brush(), gridPos, cellSize, parent)
{
    setZValue(SchemaItemLevel::Metal);
}
