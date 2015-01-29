#include "mainwidget.h"

#include "utils.h"

#include "ui_mainwidget.h"

#include <QKeyEvent>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    for(QObject *child : children()) {
        child->installEventFilter(this);
    }

    connect(this, SIGNAL(shiftPressed(bool)), SLOT(modifyControls(bool)));
}

void MainWidget::modifyControls(bool modify) {
    ui->showMetalCheckBox->setChecked(modify);
}

bool MainWidget::keyEvent(bool type, QEvent *event) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if(keyEvent->key() == Qt::Key_Shift) {
        emit shiftPressed(type);
        return true;
    }
    return false;
}

bool MainWidget::eventFilter(QObject *, QEvent *event) {
    switch(event->type()) {
    case QEvent::KeyPress:
        return keyEvent(true, event);
    case QEvent::KeyRelease:
        return keyEvent(false, event);
    default:
        return false;
    }
}

MainWidget::~MainWidget()
{
    delete ui;
}
