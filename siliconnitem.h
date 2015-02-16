#ifndef SILICONNITEM_H
#define SILICONNITEM_H

#include "siliconitem.h"
#include "itemtyperegistry.h"

namespace SchemaItem {

class SiliconNItem : public SiliconItem
{
public:
    explicit SiliconNItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit SiliconNItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);

    ItemType itemType() const { return ItemType::SiliconN; }
};

}

#endif // SILICONNITEM_H
