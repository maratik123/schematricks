#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QGraphicsScene>

class GridScene : public QGraphicsScene
{
    Q_OBJECT
    Q_DISABLE_COPY(GridScene)
public:
    explicit GridScene(qreal gridSize, QObject *parent = nullptr) : QGraphicsScene(parent), _gridSize(gridSize) {}

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    const qreal _gridSize;
};

#endif // GRIDSCENE_H
