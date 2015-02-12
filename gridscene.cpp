#include "gridscene.h"
#include <QPainter>
#include <cmath>
#include <QVarLengthArray>
#include "metalitem.h"
#include "siliconnitem.h"
#include "siliconpitem.h"
#include "viaitem.h"

using SchemaItem::MetalItem;
using SchemaItem::SiliconNItem;
using SchemaItem::SiliconPItem;
using SchemaItem::ViaItem;

void GridScene::setGridRect(int i, int j)
{
    setSceneRect(QRectF(0, 0, _gridSize * i, _gridSize * j));
}

MetalItem *GridScene::addMetalItem(int i, int j)
{
    return addSchemaItem(new MetalItem(i, j, _gridSize));
}

MetalItem *GridScene::addMetalItem(const QPoint &gridPos)
{
    return addSchemaItem(new MetalItem(gridPos, _gridSize));
}

SiliconNItem *GridScene::addSiliconNItem(int i, int j)
{
    return addSchemaItem(new SiliconNItem(i, j, _gridSize));
}

SiliconNItem *GridScene::addSiliconNItem(const QPoint &gridPos)
{
    return addSchemaItem(new SiliconNItem(gridPos, _gridSize));
}

SiliconPItem *GridScene::addSiliconPItem(int i, int j)
{
    return addSchemaItem(new SiliconPItem(i, j, _gridSize));
}

SiliconPItem *GridScene::addSiliconPItem(const QPoint &gridPos)
{
    return addSchemaItem(new SiliconPItem(gridPos, _gridSize));
}

ViaItem *GridScene::addViaItem(int i, int j)
{
    return addSchemaItem(new ViaItem(i, j, _gridSize));
}

ViaItem *GridScene::addViaItem(const QPoint &gridPos)
{
    return addSchemaItem(new ViaItem(gridPos, _gridSize));
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
