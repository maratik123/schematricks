#include "layeredcolorhelper.h"

namespace SchemaItem {

namespace {

const static qreal ALPHA = 0.75;

}

template<class ColorType>
void LayeredColorHelper::setPenGeneric(const ColorType &outlineColor) {
    QColor _outlineColor(outlineColor);
    _outlineColor.setAlphaF(ALPHA);
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
    _innerColor.setAlphaF(ALPHA);
    _brush = _innerColor;
}

}
