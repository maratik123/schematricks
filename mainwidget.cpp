#include "mainwidget.h"
#include "utils.h"
#include "ui_mainwidget.h"
#include <QKeyEvent>
#include "gridscene.h"
#include <QGraphicsSimpleTextItem>

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

    scene->addItem(drawTypeItem);
    scene->addItem(showMetalItem);
    drawTypeItem->setPos(0, 0);
    showMetalItem->setPos(0, 20);
    setDrawType(DrawType::SiliconN);
    setShowMetal(true);
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
