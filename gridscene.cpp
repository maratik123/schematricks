#include "gridscene.h"
#include <QPainter>

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = 25;
    int ileft = static_cast<int>(rect.left());
    int itop = static_cast<int>(rect.top());
    qreal left =  ileft - ileft % gridSize;
    qreal top =  itop - itop % gridSize;

    QVarLengthArray<QLineF> lines;

    for(qreal x = left; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for(qreal y = top; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->drawLines(lines.constData(), lines.size());
}
