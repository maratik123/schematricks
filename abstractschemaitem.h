#ifndef ABSTRACTSCHEMAITEM_H
#define ABSTRACTSCHEMAITEM_H

#include <QAbstractGraphicsShapeItem>

enum class SchemaItemType;

class AbstractSchemaItem : public QAbstractGraphicsShapeItem
{
    Q_DISABLE_COPY(AbstractSchemaItem)

public:
    explicit AbstractSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    explicit AbstractSchemaItem(const QPoint &gridPos, qreal cellSize, QGraphicsItem *parent = nullptr);
    qreal gridSize() const { return _cellSize; }

    int type() const { return static_cast<int>(schemaItemType()); }
    int i() const { return _gridPos.x(); }
    int j() const { return _gridPos.y(); }
    const QPoint &gridPos() const { return _gridPos; }
    void setI(int i);
    void setJ(int j);
    void setGridPos(const QPoint &gridPos);
    void setGridPos(int i, int j) { setGridPos(QPoint(i, j)); }

    virtual SchemaItemType schemaItemType() const = 0;

    QRectF boundingRect() const { return QRectF(QPointF(_gridPos) * _cellSize, QSizeF(_cellSize, _cellSize)); }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;

private:
    void updateBoundingRect();
    template<class Checker, class Updater>
    void setGridPos(Checker checker, Updater updater);

    const qreal _cellSize;
    QPoint _gridPos;
};

#endif // ABSTRACTSCHEMAITEM_H
