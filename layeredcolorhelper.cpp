#include "layeredcolorhelper.h"

LayeredColorHelper::LayeredColorHelper(QColor innerColor, QColor outlineColor)
{
    innerColor.setAlphaF(0.7);
    outlineColor.setAlphaF(0.7);
    _brush = innerColor;
    _outline = outlineColor;
}
