#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QGraphicsScene;
class QGraphicsSimpleTextItem;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    Q_ENUMS(MainWidget::DrawType)
    Q_PROPERTY(MainWidget::DrawType drawType READ drawType WRITE setDrawType NOTIFY drawTypeChanged)
    Q_PROPERTY(bool showMetal READ isShowMetal WRITE setShowMetal NOTIFY showMetalChanged)

public:
    enum class DrawType { SiliconN, SiliconP, Metal, Select, DeleteSilicon, DeleteMetal, AddVia };

    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    MainWidget::DrawType drawType() const { return _drawType; }
    bool isShowMetal() const { return _isShowMetal; }

signals:
    void shiftPressed(bool);
    void drawTypeChanged(MainWidget::DrawType);
    void showMetalChanged(bool);

public slots:
    void setDrawType(MainWidget::DrawType drawType);
    void setShowMetal(bool showMetal);

private slots:
    void modifyControls(bool modify) { isControlModified = modify; }
    void selectSelect(bool toggle);
    void addViaSelect(bool toggle);
    void metalSelect(bool toggle);
    void siliconSelect(bool toggle);
    void deleteSelect(bool toggle);

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    bool keyEvent(bool type, QEvent *event);

    Ui::MainWidget *ui;
    DrawType _drawType;
    bool isControlModified;
    bool _isShowMetal;
    QGraphicsScene *scene;
    QGraphicsSimpleTextItem *drawTypeItem;
    QGraphicsSimpleTextItem *showMetalItem;
};

#endif // MAINWIDGET_H
