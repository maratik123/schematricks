#ifndef SILICONPSCHEMAITEM_H
#define SILICONPSCHEMAITEM_H


#include "siliconschemaitem.h"
#include "schemaitemtyperegistry.h"

class SiliconPSchemaItem : public SiliconSchemaItem
{
public:
    explicit SiliconPSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit SiliconPSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    SchemaItemType schemaItemType() const { return SchemaItemType::SiliconP; }
};

#endif // SILICONPSCHEMAITEM_H
