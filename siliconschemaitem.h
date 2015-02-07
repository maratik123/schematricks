#ifndef SILICONSCHEMAITEM_H
#define SILICONSCHEMAITEM_H

#include "layeredschemaitem.h"

class SiliconSchemaItem : public LayeredSchemaItem
{
public:
    explicit SiliconSchemaItem(const QPen &outline, const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit SiliconSchemaItem(const QPen &outline, const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
};

#endif // SILICONSCHEMAITEM_H
