#ifndef LAYEREDSCHEMAITEM_H
#define LAYEREDSCHEMAITEM_H

#include "abstractschemaitem.h"
#include <QBrush>

class LayeredSchemaItem : public AbstractSchemaItem
{
public:
    explicit LayeredSchemaItem(const QBrush &innerBrush, int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredSchemaItem(const QBrush &innerBrush, const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    const QBrush &innerBrush() const { return _innerBrush; }
    void setInnerBrush(const QBrush &innerBrush);
private:
    QBrush _innerBrush;
};

#endif // LAYEREDSCHEMAITEM_H
