#include "gridscene.h"
#include <QPainter>
#include <cmath>
#include <QVarLengthArray>

namespace {
    thread_local QVarLengthArray<QLineF> lines;
}

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    qreal left =  rect.left() - std::remainder(rect.left(), _gridSize);
    qreal top =  rect.top() - std::remainder(rect.top(), _gridSize);

    lines.clear();

    for(qreal x = left; x < rect.right(); x += _gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for(qreal y = top; y < rect.bottom(); y += _gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    painter->drawLines(lines.constData(), lines.size());
}
