#include "siliconnitem.h"
#include "layeredcolorhelper.h"
#include "globalconsts.h"

namespace SchemaItem {

SiliconNItem::SiliconNItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconNDef->outline(), siliconNDef->brush(), i, j, cellSize, parent)
{
}

SiliconNItem::SiliconNItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconNDef->outline(), siliconNDef->brush(), gridPos, cellSize, parent)
{
}

}
