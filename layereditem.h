#ifndef LAYEREDITEM_H
#define LAYEREDITEM_H

#include "abstractitem.h"
#include <QBrush>
#include <QPen>

namespace SchemaItem {

class LayeredItem : public AbstractItem
{
public:
    explicit LayeredItem(const QPen &pen, const QBrush &brush, int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredItem(const QPen &pen, const QBrush &brush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

}

#endif // LAYEREDITEM_H
