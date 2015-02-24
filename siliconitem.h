#ifndef SILICONITEM_H
#define SILICONITEM_H

#include "layereditem.h"

namespace SchemaItem {

class SiliconItem : public LayeredItem
{
public:
    explicit SiliconItem(const QPen &pen, const QBrush &brush, int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit SiliconItem(const QPen &pen, const QBrush &brush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
};

}

#endif // SILICONITEM_H
