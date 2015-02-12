#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QGraphicsScene>

namespace SchemaItem {
class MetalItem;
class SiliconNItem;
class SiliconPItem;
class ViaItem;
}

class GridScene : public QGraphicsScene
{
    Q_OBJECT
    Q_DISABLE_COPY(GridScene)
public:
    explicit GridScene(qreal gridSize, QObject *parent = nullptr) : QGraphicsScene(parent), _gridSize(gridSize) {}
    qreal gridSize() const { return _gridSize; }
    void setGridRect(int i, int j);
    SchemaItem::MetalItem *addMetalItem(int i, int j);
    SchemaItem::MetalItem *addMetalItem(const QPoint &gridPos);
    SchemaItem::SiliconNItem *addSiliconNItem(int i, int j);
    SchemaItem::SiliconNItem *addSiliconNItem(const QPoint &gridPos);
    SchemaItem::SiliconPItem *addSiliconPItem(int i, int j);
    SchemaItem::SiliconPItem *addSiliconPItem(const QPoint &gridPos);
    SchemaItem::ViaItem *addViaItem(int i, int j);
    SchemaItem::ViaItem *addViaItem(const QPoint &gridPos);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    const qreal _gridSize;
    template<class Item>
    Item *addSchemaItem(Item *item);
};

#endif // GRIDSCENE_H
