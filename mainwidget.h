#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QAbstractButton>

class QButtonGroup;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    Q_ENUMS(DrawType)
    Q_PROPERTY(DrawType drawType READ drawType WRITE setDrawType NOTIFY drawTypeChanged)

public:
    enum class DrawType { SiliconN, SiliconP, Metal, Select, DeleteSilicon, DeleteMetal };

    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void modifyControls(bool modify);
    void showMetal(bool toggle);
    void selectSelect(bool toggle);
    void addViaSelect(bool toggle);
    void metalSelect(bool toggle);
    void siliconSelect(bool toggle);
    void deleteSelect(bool toggle);

protected:
    bool eventFilter(QObject *, QEvent *);

private:
    bool keyEvent(bool type, QEvent *event);
    Ui::MainWidget *ui;
    DrawType _drawType;
    bool isControlModified;
    bool isShowMetal;
    void setDrawType(DrawType drawType);
    DrawType drawType() const { return drawType; }

signals:
    void shiftPressed(bool modify);
    void drawTypeChanged(DrawType);
};

#endif // MAINWIDGET_H
