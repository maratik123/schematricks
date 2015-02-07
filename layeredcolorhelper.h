#ifndef LAYEREDCOLORHELPER_H
#define LAYEREDCOLORHELPER_H

#include <QBrush>
#include <QPen>

class LayeredColorHelper
{
    QBrush _brush;
    QPen _outline;

public:
    explicit LayeredColorHelper(QColor innerColor, QColor outlineColor);
    const QBrush &brush() const { return _brush; }
    const QPen &outline() const { return _outline; }
};

#endif // LAYEREDCOLORHELPER_H
