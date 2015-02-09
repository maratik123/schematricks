#ifndef SILICONNSCHEMAITEM_H
#define SILICONNSCHEMAITEM_H

#include "siliconschemaitem.h"
#include "schemaitemtyperegistry.h"

class SiliconNSchemaItem : public SiliconSchemaItem
{
public:
    explicit SiliconNSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit SiliconNSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    SchemaItemType schemaItemType() const { return SchemaItemType::SiliconN; }
};

#endif // SILICONNSCHEMAITEM_H
