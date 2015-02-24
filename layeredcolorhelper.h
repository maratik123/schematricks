#ifndef LAYEREDCOLORHELPER_H
#define LAYEREDCOLORHELPER_H

#include <QBrush>
#include <QPen>

namespace SchemaItem {

class LayeredColorHelper
{
    QBrush _brush;
    QPen _pen;

public:
    explicit LayeredColorHelper(const QColor &innerColor, const QColor &outlineColor) { setPen(outlineColor); setBrush(innerColor); }
    explicit LayeredColorHelper(Qt::GlobalColor innerColor, Qt::GlobalColor outlineColor) { setPen(outlineColor); setBrush(innerColor); }
    explicit LayeredColorHelper(const QBrush &innerBrush, const QColor &outlineColor) : _brush(innerBrush) { setPen(outlineColor); }
    explicit LayeredColorHelper(Qt::BrushStyle brushStyle, const QColor &outlineColor) : _brush(brushStyle) { setPen(outlineColor); }
    explicit LayeredColorHelper(const QBrush &innerBrush, Qt::GlobalColor outlineColor) : _brush(innerBrush) { setPen(outlineColor); }
    explicit LayeredColorHelper(Qt::BrushStyle brushStyle, Qt::GlobalColor outlineColor) : _brush(brushStyle) { setPen(outlineColor); }
    const QBrush &brush() const { return _brush; }
    const QPen &pen() const { return _pen; }
    void setPen(const QColor &outlineColor);
    void setPen(Qt::GlobalColor outlineColor);
    void setBrush(const QColor &innerColor);
private:
    template<class ColorType>
    void setPenGeneric(const ColorType &outlineColor);
};

}

#endif // LAYEREDCOLORHELPER_H
