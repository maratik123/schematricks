#include "mainwidget.h"
#include "utils.h"
#include "ui_mainwidget.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    _drawType(DrawType::Nothing),
    _isShowMetal(false),
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

QDebug operator<<(QDebug debug, MainWidget::DrawType drawType) {
    const char* strDrawType;
    switch(drawType) {
    case MainWidget::DrawType::AddVia:
        strDrawType = "AddVia";
        break;
    case MainWidget::DrawType::DeleteMetal:
        strDrawType = "DeleteMetal";
        break;
    case MainWidget::DrawType::DeleteSilicon:
        strDrawType = "DeleteSilicon";
        break;
    case MainWidget::DrawType::Metal:
        strDrawType = "Metal";
        break;
    case MainWidget::DrawType::Select:
        strDrawType = "Select";
        break;
    case MainWidget::DrawType::SiliconN:
        strDrawType = "SiliconN";
        break;
    case MainWidget::DrawType::SiliconP:
        strDrawType = "SiliconP";
        break;
    default:
        strDrawType = "Unknown draw type";
        break;
    }
    return debug << QLatin1String(strDrawType);
}

void MainWidget::setDrawType(MainWidget::DrawType drawType)
{
    if(drawType == _drawType)
        return;
    _drawType = drawType;
    emit drawTypeChanged(drawType);
    QString drawTypeStr;
    {
        QDebug(&drawTypeStr) << drawType;
    }
    drawTypeItem->setText(drawTypeStr);
}
