#include "mainwidget.h"
#include "utils.h"
#include "ui_mainwidget.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    _drawType(DrawType::SiliconN),
    _isShowMetal(true),
    scene(new QGraphicsScene(this)),
    drawTypeItem(new QGraphicsSimpleTextItem()),
    showMetalItem(new QGraphicsSimpleTextItem())
{
    ui->setupUi(this);

    ui->schemaView->setScene(scene);

    scene->addItem(drawTypeItem);
    scene->addItem(showMetalItem);
    drawTypeItem->setPos(0, 0);
    showMetalItem->setPos(0, 20);
}

void MainWidget::setShowMetal(bool showMetal)
{
    if(_isShowMetal == showMetal)
        return;
    _isShowMetal = showMetal;
    emit showMetalChanged(showMetal);
    drawTypeItem->setText(showMetal ? tr("Show metal") : tr("Hide metal"));
}

void MainWidget::selectSelect(bool toggle)
{
    if(toggle)
        setDrawType(DrawType::Select);
}

void MainWidget::addViaSelect(bool toggle)
{
    if(toggle)
        setDrawType(DrawType::AddVia);
}

void MainWidget::metalSelect(bool toggle)
{
    if(toggle)
        setDrawType(DrawType::Metal);
}

void MainWidget::siliconNSelect(bool toggle)
{
    if(toggle)
        setDrawType(DrawType::SiliconN);
}

void MainWidget::siliconPSelect(bool toggle)
{
    if(toggle)
        setDrawType(DrawType::SiliconP);
}

void MainWidget::deleteSiliconSelect(bool toggle)
{
    if(toggle)
        setDrawType(DrawType::DeleteSilicon);
}

void MainWidget::deleteMetalSelect(bool toggle)
{
    if(toggle)
        setDrawType(DrawType::DeleteMetal);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::setDrawType(MainWidget::DrawType drawType)
{
    if(drawType == _drawType)
        return;
    _drawType = drawType;
    emit drawTypeChanged(drawType);
    switch(drawType) {
    case DrawType::AddVia:
        drawTypeItem->setText(tr("AddVia"));
        break;
    case DrawType::DeleteMetal:
        drawTypeItem->setText(tr("DeleteMetal"));
        break;
    case DrawType::DeleteSilicon:
        drawTypeItem->setText(tr("DeleteSilicon"));
        break;
    case DrawType::Metal:
        drawTypeItem->setText(tr("Metal"));
        break;
    case DrawType::Select:
        drawTypeItem->setText(tr("Select"));
        break;
    case DrawType::SiliconN:
        drawTypeItem->setText(tr("SiliconN"));
        break;
    case DrawType::SiliconP:
        drawTypeItem->setText(tr("SiliconP"));
        break;
    default:
        drawTypeItem->setText(tr("Unknown draw type"));
    }
}
