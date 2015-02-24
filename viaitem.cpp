#include "viaitem.h"
#include "itemtyperegistry.h"
#include <QPainter>
#include "layeredcolorhelper.h"
#include "globalconsts.h"

namespace SchemaItem {

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
    painter->setPen(viaDef->pen());
    painter->setBrush(viaDef->brush());
    const qreal innerMargin = gridSize() * 0.4;
    const QRectF &rect = boundingRect().adjusted(innerMargin, innerMargin, - innerMargin, - innerMargin);
    painter->drawEllipse(rect);
}

}
