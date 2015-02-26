#ifndef METALITEM_H
#define METALITEM_H

#include "layereditem.h"
#include "itemtyperegistry.h"

namespace SchemaItem {

class MetalItem : public LayeredItem
{
public:
    explicit MetalItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit MetalItem(QPoint gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    ItemType itemType() const { return ItemType::Metal; }
};

}

#endif // METALITEM_H
