#ifndef VIAITEM_H
#define VIAITEM_H

#include "abstractitem.h"
#include "itemtyperegistry.h"

namespace SchemaItem {

class ViaItem : public AbstractItem
{
public:
    explicit ViaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit ViaItem(QPoint gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    ItemType itemType() const { return ItemType::Via; }

protected:
    void schemaPaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

}

#endif // VIAITEM_H
