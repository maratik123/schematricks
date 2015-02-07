#ifndef LAYEREDSCHEMAITEM_H
#define LAYEREDSCHEMAITEM_H

#include "abstractschemaitem.h"
#include <QBrush>
#include <QPen>

class LayeredSchemaItem : public AbstractSchemaItem
{
public:
    explicit LayeredSchemaItem(const QPen &outline, const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredSchemaItem(const QPen &outline, const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    const QBrush &innerBrush() const { return _innerBrush; }
    void setInnerBrush(const QBrush &innerBrush);
    void setOutline(const QPen &outline);
    const QPen &outline() const { return _outline; }
private:
    QBrush _innerBrush;
    QPen _outline;
};

#endif // LAYEREDSCHEMAITEM_H
