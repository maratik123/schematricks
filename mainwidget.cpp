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
    isControlModified(false),
    _isShowMetal(true),
    scene(new QGraphicsScene(this)),
    drawTypeItem(new QGraphicsSimpleTextItem()),
    showMetalItem(new QGraphicsSimpleTextItem())
{
    ui->setupUi(this);

    connect(this, SIGNAL(shiftPressed(bool)), SLOT(modifyControls(bool)));
    
    for(QObject *child : children()) {
        child->installEventFilter(this);
    }

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

void MainWidget::siliconSelect(bool toggle)
{
    if(toggle)
        setDrawType(isControlModified ? DrawType::SiliconP : DrawType::SiliconN);
}

void MainWidget::deleteSelect(bool toggle)
{
    if(toggle)
        setDrawType(isControlModified ? DrawType::DeleteMetal : DrawType::DeleteSilicon);
}

bool MainWidget::keyEvent(bool type, QEvent *event) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if(keyEvent->key() == Qt::Key_Shift) {
        emit shiftPressed(type);
        return true;
    }
    return false;
}

bool MainWidget::eventFilter(QObject *object, QEvent *event) {
    switch(event->type()) {
    case QEvent::KeyPress:
        if(keyEvent(true, event))
            return true;
        break;
    case QEvent::KeyRelease:
        if(keyEvent(false, event))
            return true;
        break;
    default:
        break;
    }
    return QWidget::eventFilter(object, event);
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
        drawTypeItem->setText(tr("Unkbown draw type"));
    }


}
