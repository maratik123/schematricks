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
    void drawTypeChanged(MainWidget::DrawType);
    void showMetalChanged(bool);

public slots:
    void setDrawType(MainWidget::DrawType drawType);
    void setShowMetal(bool showMetal);

private slots:
    void selectSelect(bool toggle);
    void addViaSelect(bool toggle);
    void metalSelect(bool toggle);
    void siliconNSelect(bool toggle);
    void siliconPSelect(bool toggle);
    void deleteSiliconSelect(bool toggle);
    void deleteMetalSelect(bool toggle);

private:
    bool keyEvent(bool type, QEvent *event);

    Ui::MainWidget *ui;
    DrawType _drawType;
    bool _isShowMetal;
    QGraphicsScene *scene;
    QGraphicsSimpleTextItem *drawTypeItem;
    QGraphicsSimpleTextItem *showMetalItem;
};

#endif // MAINWIDGET_H
