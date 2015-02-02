#include "gridscene.h"

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = 25;
    int ileft = static_cast<int>(rect.left());
    int itop = static_cast<int>(rect.top());
    qreal left =  ileft - ileft % gridSize;
    qreal top =  itop - itop % gridSize;
}
