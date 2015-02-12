#ifndef LAYEREDITEM_H
#define LAYEREDITEM_H

#include "abstractitem.h"
#include <QBrush>
#include <QPen>

namespace SchemaItem {

class LayeredItem : public AbstractItem
{
public:
    explicit LayeredItem(const QPen &outline, const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredItem(const QPen &outline, const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    const QBrush &innerBrush() const { return _innerBrush; }
    void setInnerBrush(const QBrush &innerBrush);
    void setOutline(const QPen &outline);
    const QPen &outline() const { return _outline; }
private:
    QBrush _innerBrush;
    QPen _outline;
};

}

#endif // LAYEREDITEM_H
