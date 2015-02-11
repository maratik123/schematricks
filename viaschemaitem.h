#ifndef VIASCHEMAITEM_H
#define VIASCHEMAITEM_H

#include "abstractschemaitem.h"
#include "schemaitemtyperegistry.h"

class ViaSchemaItem : public AbstractSchemaItem
{
public:
    explicit ViaSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit ViaSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    SchemaItemType schemaItemType() const { return SchemaItemType::Via; }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif // VIASCHEMAITEM_H
