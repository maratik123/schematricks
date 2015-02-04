#include "gridscene.h"
#include <QPainter>
#include <cmath>

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    auto left =  rect.left() - std::remainder(rect.left(), _gridSize);
    auto top =  rect.top() - std::remainder(rect.top(), _gridSize);

    QVarLengthArray<QLineF> lines;

    for(auto x = left; x < rect.right(); x += _gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for(auto y = top; y < rect.bottom(); y += _gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->drawLines(lines.constData(), lines.size());
}
