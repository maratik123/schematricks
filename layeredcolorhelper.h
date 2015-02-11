#ifndef LAYEREDCOLORHELPER_H
#define LAYEREDCOLORHELPER_H

#include <QBrush>
#include <QPen>

class LayeredColorHelper
{
    QBrush _brush;
    QPen _outline;

public:
    explicit LayeredColorHelper(const QColor &innerColor, const QColor &outlineColor) { setOutline(outlineColor); setBrush(innerColor); }
    explicit LayeredColorHelper(Qt::GlobalColor innerColor, Qt::GlobalColor outlineColor) { setOutline(outlineColor); setBrush(innerColor); }
    explicit LayeredColorHelper(const QBrush &innerBrush, const QColor &outlineColor) : _brush(innerBrush) { setOutline(outlineColor); }
    explicit LayeredColorHelper(Qt::BrushStyle brushStyle, const QColor &outlineColor) : _brush(brushStyle) { setOutline(outlineColor); }
    const QBrush &brush() const { return _brush; }
    const QPen &outline() const { return _outline; }
    void setOutline(const QColor &outlineColor);
    void setBrush(const QColor &innerColor);
};

#endif // LAYEREDCOLORHELPER_H
