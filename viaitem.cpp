#include "viaitem.h"
#include "itemtyperegistry.h"
#include <QPainter>
#include "layeredcolorhelper.h"

namespace SchemaItem {

namespace {
    const static LayeredColorHelper viaDef(Qt::NoBrush, Qt::black);
}

ViaItem::ViaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(i, j, cellSize, parent)
{
    setZValue(ItemLevel::Via);
}

ViaItem::ViaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(gridPos, cellSize, parent)
{
    setZValue(ItemLevel::Via);
}

void ViaItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(viaDef.outline());
    painter->setBrush(viaDef.brush());
    qreal innerMargin = gridSize() * 0.4;
    const QRectF &rect = boundingRect().adjusted(innerMargin, innerMargin, - innerMargin, - innerMargin);
    painter->drawEllipse(rect);
}

}
