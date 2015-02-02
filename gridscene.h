#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QGraphicsScene>

class GridScene : public QGraphicsScene
{
    Q_OBJECT
    Q_DISABLE_COPY(GridScene)
public:
    explicit GridScene(QObject *parent = nullptr) : QGraphicsScene(parent) {}

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif // GRIDSCENE_H
