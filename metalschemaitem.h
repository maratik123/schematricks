#ifndef METALSCHEMAITEM_H
#define METALSCHEMAITEM_H

#include "layeredschemaitem.h"
#include "schemaitemtyperegistry.h"

class MetalSchemaItem : public LayeredSchemaItem
{
public:
    explicit MetalSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit MetalSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    SchemaItemType schemaItemType() const { return SchemaItemType::Metal; }
};

#endif // METALSCHEMAITEM_H
