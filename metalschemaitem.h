#ifndef METALSCHEMAITEM_H
#define METALSCHEMAITEM_H

#include "abstractschemaitem.h"
#include "schemaitemtyperegistry.h"

class MetalSchemaItem : public AbstractSchemaItem
{
public:
    explicit MetalSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr) : AbstractSchemaItem(i, j, cellSize, parent) {}

};

#endif // METALSCHEMAITEM_H
