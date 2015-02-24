#include "layeredcolorhelper.h"

namespace SchemaItem {

template<class ColorType>
void LayeredColorHelper::setPenGeneric(const ColorType &outlineColor) {
    QColor _outlineColor(outlineColor);
    _outlineColor.setAlphaF(0.7);
    _pen = _outlineColor;
}

void LayeredColorHelper::setPen(const QColor &outlineColor)
{
    setPenGeneric(outlineColor);
}

void LayeredColorHelper::setPen(Qt::GlobalColor outlineColor)
{
    setPenGeneric(outlineColor);
}

void LayeredColorHelper::setBrush(const QColor &innerColor)
{
    QColor _innerColor(innerColor);
    _innerColor.setAlphaF(0.7);
    _brush = _innerColor;
}

}
