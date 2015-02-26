#ifndef LAYEREDITEM_H
#define LAYEREDITEM_H

#include "abstractitem.h"
#include <QBrush>
#include <QPen>

namespace SchemaItem {

class LayeredItem : public AbstractItem
{
public:
    enum BridgeDirection {
        NoBridge = 0x0,
        Up = 0x1,
        Down = 0x2,
        Left = 0x4,
        Right = 0x8
    };

    Q_DECLARE_FLAGS(BridgeDirections, BridgeDirection)

    explicit LayeredItem(const QPen &pen, const QBrush &brush, int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit LayeredItem(const QPen &pen, const QBrush &brush, QPoint gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    const BridgeDirections &bridgeDirections() const { return _bridgeDirections; }
    void setBridgeDirections(BridgeDirections bridgeDirections) { _bridgeDirections = bridgeDirections; }

protected:
    void schemaPaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

private:
    BridgeDirections _bridgeDirections;
};

}

Q_DECLARE_OPERATORS_FOR_FLAGS(SchemaItem::LayeredItem::BridgeDirections)

#endif // LAYEREDITEM_H
