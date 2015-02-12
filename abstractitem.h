#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QAbstractGraphicsShapeItem>

namespace SchemaItem {

enum class ItemType;

class AbstractItem : public QAbstractGraphicsShapeItem
{
    Q_DISABLE_COPY(AbstractItem)

public:
    explicit AbstractItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit AbstractItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    qreal gridSize() const { return _cellSize; }

    int type() const { return static_cast<int>(itemType()); }
    int i() const { return _gridPos.x(); }
    int j() const { return _gridPos.y(); }
    const QPoint &gridPos() const { return _gridPos; }
    void setI(int i);
    void setJ(int j);
    void setGridPos(const QPoint &gridPos);
    void setGridPos(int i, int j) { setGridPos(QPoint(i, j)); }

    virtual ItemType itemType() const = 0;

    QRectF boundingRect() const { return QRectF(QPointF(_gridPos) * _cellSize, QSizeF(_cellSize, _cellSize)); }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;

private:
    template<class Checker, class Updater>
    void setGridPos(const Checker &checker, Updater &updater);

    const qreal _cellSize;
    QPoint _gridPos;
};

template<class Checker, class Updater>
void AbstractItem::setGridPos(const Checker &checker, Updater &updater)
{
    if(checker())
        return;
    prepareGeometryChange();
    updater();
    update();
}

}

#endif // ABSTRACTITEM_H
