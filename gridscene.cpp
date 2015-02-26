#include "gridscene.h"
#include <QPainter>
#include <cmath>
#include <QVarLengthArray>
#include "metalitem.h"
#include "siliconnitem.h"
#include "siliconpitem.h"
#include "viaitem.h"

namespace SI = SchemaItem;

namespace {

template<class Item>
static Item *addSchemaItem(GridScene *scene, Item *item)
{
    scene->addItem(item);
    return item;
}

}

void GridScene::setGridRect(int i, int j)
{
    setSceneRect(QRectF(0, 0, _gridSize * i, _gridSize * j));
}

SI::MetalItem *GridScene::addMetalItem(int i, int j)
{
    return addSchemaItem(this, new SI::MetalItem(i, j, _gridSize));
}

SI::MetalItem *GridScene::addMetalItem(QPoint gridPos)
{
    return addSchemaItem(this, new SI::MetalItem(gridPos, _gridSize));
}

SI::SiliconNItem *GridScene::addSiliconNItem(int i, int j)
{
    return addSchemaItem(this, new SI::SiliconNItem(i, j, _gridSize));
}

SI::SiliconNItem *GridScene::addSiliconNItem(QPoint gridPos)
{
    return addSchemaItem(this, new SI::SiliconNItem(gridPos, _gridSize));
}

SI::SiliconPItem *GridScene::addSiliconPItem(int i, int j)
{
    return addSchemaItem(this, new SI::SiliconPItem(i, j, _gridSize));
}

SI::SiliconPItem *GridScene::addSiliconPItem(QPoint gridPos)
{
    return addSchemaItem(this, new SI::SiliconPItem(gridPos, _gridSize));
}

SI::ViaItem *GridScene::addViaItem(int i, int j)
{
    return addSchemaItem(this, new SI::ViaItem(i, j, _gridSize));
}

SI::ViaItem *GridScene::addViaItem(QPoint gridPos)
{
    return addSchemaItem(this, new SI::ViaItem(gridPos, _gridSize));
}

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    const QRectF &interRect = rect.intersected(sceneRect());
    const qreal left = interRect.left() - std::remainder(interRect.left(), _gridSize);
    const qreal top = interRect.top() - std::remainder(interRect.top(), _gridSize);

    QVarLengthArray<QLineF> lines;

    for(auto x = left; x < interRect.right() || qFuzzyCompare(x, interRect.right()); x += _gridSize)
        lines.append(QLineF(x, interRect.top(), x, interRect.bottom()));
    for(auto y = top; y < interRect.bottom() || qFuzzyCompare(y, interRect.bottom()); y += _gridSize)
        lines.append(QLineF(interRect.left(), y, interRect.right(), y));

    painter->drawLines(lines.constData(), lines.size());
}
