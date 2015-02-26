#ifndef LAYEREDCOLORHELPER_H
#define LAYEREDCOLORHELPER_H

#include <QBrush>
#include <QPen>

namespace SchemaItem {

class LayeredColorHelper
{
    QBrush _brush;
    QPen _pen;
    constexpr static qreal ALPHA = 0.75;

public:
    explicit LayeredColorHelper(QColor innerColor, QColor outlineColor) { setPen(outlineColor); setBrush(innerColor); }
    explicit LayeredColorHelper(Qt::GlobalColor innerColor, Qt::GlobalColor outlineColor) { setPen(outlineColor); setBrush(innerColor); }
    explicit LayeredColorHelper(const QBrush &innerBrush, QColor outlineColor) : _brush(innerBrush) { setPen(outlineColor); }
    explicit LayeredColorHelper(Qt::BrushStyle brushStyle, QColor outlineColor) : _brush(brushStyle) { setPen(outlineColor); }
    explicit LayeredColorHelper(const QBrush &innerBrush, Qt::GlobalColor outlineColor) : _brush(innerBrush) { setPen(outlineColor); }
    explicit LayeredColorHelper(Qt::BrushStyle brushStyle, Qt::GlobalColor outlineColor) : _brush(brushStyle) { setPen(outlineColor); }
    const QBrush &brush() const { return _brush; }
    const QPen &pen() const { return _pen; }
    void setPen(const QPen &pen) { _pen = pen; }
    void setPen(QColor outlineColor) { outlineColor.setAlphaF(ALPHA); _pen = outlineColor; }
    void setPen(Qt::GlobalColor outlineColor) { setPen(QColor(outlineColor)); }
    void setBrush(QColor innerColor) { innerColor.setAlphaF(ALPHA); _brush = innerColor; }
    void setBrush(Qt::GlobalColor innerColor) { setBrush(QColor(innerColor)); }
    void setBrush(const QBrush &brush) { _brush = brush; }
};

}

#endif // LAYEREDCOLORHELPER_H
