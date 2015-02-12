#ifndef SILICONPITEM_H
#define SILICONPITEM_H

#include "siliconitem.h"
#include "itemtyperegistry.h"

namespace SchemaItem {

class SiliconPItem : public SiliconItem
{
public:
    explicit SiliconPItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit SiliconPItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    ItemType itemType() const { return ItemType::SiliconP; }
};

}

#endif // SILICONPITEM_H
