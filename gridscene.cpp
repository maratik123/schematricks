#include "gridscene.h"
#include <QPainter>
#include <cmath>
#include <QVarLengthArray>

void GridScene::setGridRect(int i, int j)
{
    setSceneRect(QRectF(0, 0, _gridSize * i, _gridSize * j));
}

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QRectF interRect = rect.intersected(sceneRect());
    auto left =  interRect.left() - std::remainder(interRect.left(), _gridSize);
    auto top =  interRect.top() - std::remainder(interRect.top(), _gridSize);

    QVarLengthArray<QLineF> lines;

    for(auto x = left; x < interRect.right() || qFuzzyCompare(x, interRect.right()); x += _gridSize)
        lines.append(QLineF(x, interRect.top(), x, interRect.bottom()));
    for(auto y = top; y < interRect.bottom() || qFuzzyCompare(y, interRect.bottom()); y += _gridSize)
        lines.append(QLineF(interRect.left(), y, interRect.right(), y));

    painter->drawLines(lines.constData(), lines.size());
}
