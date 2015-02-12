#include "layeredcolorhelper.h"

namespace SchemaItem {

template<class ColorType>
void LayeredColorHelper::setOutlineGeneric(const ColorType &outlineColor) {
    QColor _outlineColor(outlineColor);
    _outlineColor.setAlphaF(0.7);
    _outline = _outlineColor;
}

void LayeredColorHelper::setOutline(const QColor &outlineColor)
{
    setOutlineGeneric(outlineColor);
}

void LayeredColorHelper::setOutline(Qt::GlobalColor outlineColor)
{
    setOutlineGeneric(outlineColor);
}

void LayeredColorHelper::setBrush(const QColor &innerColor)
{
    QColor _innerColor(innerColor);
    _innerColor.setAlphaF(0.7);
    _brush = _innerColor;
}

}
