#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void modifyControls(bool modify);

protected:
    bool eventFilter(QObject *, QEvent *);

private:
    bool keyEvent(bool type, QEvent *event);
    Ui::MainWidget *ui;

signals:
    void shiftPressed(bool modify);
};

#endif // MAINWIDGET_H
