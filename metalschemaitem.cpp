#include "metalschemaitem.h"

namespace {
class ColorDef {
    QColor color;

public:
    ColorDef() : color(Qt::gray) {
        color.setAlphaF(0.7);
    }
    const QColor &getColor() const { return color; }
};

const static ColorDef colorDef;
}

MetalSchemaItem::MetalSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : LayeredSchemaItem(colorDef.getColor(), i, j, cellSize, parent)
{
    setZValue(10);
}

MetalSchemaItem::MetalSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : LayeredSchemaItem(colorDef.getColor(), gridPos, cellSize, parent)
{
    setZValue(10);
}
