#include "mainwidget.h"
#include "utils.h"
#include "ui_mainwidget.h"
#include <QKeyEvent>
#include "gridscene.h"
#include <QGraphicsSimpleTextItem>
#include "metalschemaitem.h"
#include "siliconnschemaitem.h"
#include "siliconpschemaitem.h"

namespace {
    static const int gridSize = 20;
}

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    _drawType(DrawType::Nothing),
    _isShowMetal(false),
    scene(new GridScene(gridSize, this)),
    drawTypeItem(new QGraphicsSimpleTextItem()),
    showMetalItem(new QGraphicsSimpleTextItem())
{
    ui->setupUi(this);

    ui->schemaView->setScene(scene);

    scene->setGridRect(20, 20);

    scene->addItem(drawTypeItem);
    scene->addItem(showMetalItem);
    drawTypeItem->setPos(0, 0);
    showMetalItem->setPos(0, 20);
    setDrawType(DrawType::SiliconN);
    setShowMetal(true);
    scene->addItem(new MetalSchemaItem(0, 1, gridSize));
    scene->addItem(new MetalSchemaItem(0, 0, gridSize));
    scene->addItem(new MetalSchemaItem(5, 5, gridSize));
    scene->addItem(new MetalSchemaItem(5, 6, gridSize));
    scene->addItem(new MetalSchemaItem(5, 7, gridSize));
    scene->addItem(new SiliconNSchemaItem(5, 6, gridSize));
    scene->addItem(new SiliconPSchemaItem(5, 7, gridSize));
    scene->addItem(new SiliconNSchemaItem(6, 6, gridSize));
    scene->addItem(new SiliconPSchemaItem(6, 7, gridSize));
}

void MainWidget::setShowMetal(bool showMetal)
{
    if(_isShowMetal == showMetal)
        return;
    _isShowMetal = showMetal;
    emit showMetalChanged(showMetal);
    showMetalItem->setText(showMetal ? tr("Show metal") : tr("Hide metal"));
}

MainWidget::~MainWidget()
{
    delete ui;
}

QString MainWidget::drawType2String() const {
    switch(_drawType) {
    case DrawType::AddVia:
        return tr("AddVia");
    case DrawType::DeleteMetal:
        return tr("DeleteMetal");
    case DrawType::DeleteSilicon:
        return tr("DeleteSilicon");
    case DrawType::Metal:
        return tr("Metal");
    case DrawType::Select:
        return tr("Select");
    case DrawType::SiliconN:
        return tr("SiliconN");
    case DrawType::SiliconP:
        return tr("SiliconP");
    default:
        return tr("Unknown draw type");
    }
}

void MainWidget::setDrawType(MainWidget::DrawType drawType)
{
    if(drawType == _drawType)
        return;
    _drawType = drawType;
    emit drawTypeChanged(drawType);
    drawTypeItem->setText(drawType2String());
}
