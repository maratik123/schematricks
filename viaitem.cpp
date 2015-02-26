#include "viaitem.h"
#include "itemtyperegistry.h"
#include <QPainter>
#include "layeredcolorhelper.h"
#include "globalconsts.h"

namespace SchemaItem {

ViaItem::ViaItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(i, j, cellSize, parent)
{
    setPen(viaDef->pen());
    setBrush(viaDef->brush());
    setZValue(ItemLevel::Via);
}

ViaItem::ViaItem(QPoint gridPos, qreal cellSize, QGraphicsItem *parent)
    : AbstractItem(gridPos, cellSize, parent)
{
    setPen(viaDef->pen());
    setBrush(viaDef->brush());
    setZValue(ItemLevel::Via);
}

void ViaItem::schemaPaint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    const qreal innerMargin = gridSize() * 0.4;
    const QRectF &rect = boundingRect().adjusted(innerMargin, innerMargin, - innerMargin, - innerMargin);
    painter->drawEllipse(rect);
}

}
