#include "siliconnitem.h"
#include "layeredcolorhelper.h"
#include "globalconsts.h"

namespace SchemaItem {

SiliconNItem::SiliconNItem(int i, int j, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconNDef->pen(), siliconNDef->brush(), i, j, cellSize, parent)
{
}

SiliconNItem::SiliconNItem(QPoint gridPos, qreal cellSize, QGraphicsItem *parent)
    : SiliconItem(siliconNDef->pen(), siliconNDef->brush(), gridPos, cellSize, parent)
{
}

}
