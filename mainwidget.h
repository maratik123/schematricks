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
    Q_ENUMS(DrawType)
    Q_PROPERTY(DrawType drawType READ drawType WRITE setDrawType NOTIFY drawTypeChanged)

public:
    enum class DrawType { SiliconN, SiliconP, Metal, Select, DeleteSilicon, DeleteMetal, AddVia };

    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    DrawType drawType() const { return _drawType; }
    bool isShowMetal() const { return _isShowMetal; }

signals:
    void shiftPressed(bool);
    void drawTypeChanged(DrawType);
    void showMetalChanged(bool);

public slots:
    void setDrawType(DrawType drawType);
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
