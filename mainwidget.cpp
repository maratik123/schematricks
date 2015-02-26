#include "mainwidget.h"
#include "utils.h"
#include "ui_mainwidget.h"
#include <QKeyEvent>
#include "gridscene.h"
#include <QGraphicsSimpleTextItem>

namespace {
    static constexpr int gridSize = 20;
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

    scene->addMetalItem(0, 1);
    scene->addMetalItem(0, 0);
    scene->addMetalItem(5, 5);
    scene->addMetalItem(5, 6);
    scene->addMetalItem(5, 7);
    scene->addSiliconNItem(5, 6);
    scene->addSiliconPItem(5, 7);
    scene->addSiliconNItem(6, 6);
    scene->addSiliconPItem(6, 7);
    scene->addMetalItem(7, 5);
    scene->addMetalItem(7, 6);
    scene->addMetalItem(7, 7);
    scene->addSiliconNItem(7, 6);
    scene->addSiliconPItem(7, 7);
    scene->addSiliconNItem(8, 6);
    scene->addSiliconPItem(8, 7);
    scene->addViaItem(7, 5);
    scene->addViaItem(7, 6);
    scene->addViaItem(7, 7);
    scene->addViaItem(8, 6);
    scene->addViaItem(8, 7);
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
