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
    explicit AbstractItem(QPoint gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    qreal gridSize() const { return _cellSize; }

    int type() const { return static_cast<int>(itemType()); }
    int i() const { return _gridPos.x(); }
    int j() const { return _gridPos.y(); }
    const QPoint &gridPos() const { return _gridPos; }
    void setI(int i);
    void setJ(int j);
    void setGridPos(QPoint gridPos);
    void setGridPos(int i, int j) { setGridPos(QPoint(i, j)); }

    virtual ItemType itemType() const = 0;

    QRectF boundingRect() const { return QRectF(QPointF(_gridPos) * _cellSize, QSizeF(_cellSize, _cellSize)); }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

protected:
    virtual void schemaPaint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;

private:
    const qreal _cellSize;
    QPoint _gridPos;
};

}

#endif // ABSTRACTITEM_H
