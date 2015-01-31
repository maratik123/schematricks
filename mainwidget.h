#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class QGraphicsScene;
class QGraphicsSimpleTextItem;
class QDebug;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWidget)
    Q_ENUMS(MainWidget::DrawType)
    Q_PROPERTY(MainWidget::DrawType drawType READ drawType WRITE setDrawType NOTIFY drawTypeChanged)
    Q_PROPERTY(bool showMetal READ isShowMetal WRITE setShowMetal NOTIFY showMetalChanged)

public:
    enum class DrawType { Nothing, SiliconN, SiliconP, Metal, Select, DeleteSilicon, DeleteMetal, AddVia };

    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    DrawType drawType() const { return _drawType; }
    bool isShowMetal() const { return _isShowMetal; }

signals:
    void drawTypeChanged(MainWidget::DrawType);
    void showMetalChanged(bool);

public slots:
    void setDrawType(MainWidget::DrawType drawType);
    void setShowMetal(bool showMetal);
    void selectSelect(bool toggle) { if(toggle) setDrawType(DrawType::Select); }
    void addViaSelect(bool toggle) { if(toggle) setDrawType(DrawType::AddVia); }
    void metalSelect(bool toggle) { if(toggle) setDrawType(DrawType::Metal); }
    void siliconNSelect(bool toggle) { if(toggle) setDrawType(DrawType::SiliconN); }
    void siliconPSelect(bool toggle) { if(toggle) setDrawType(DrawType::SiliconP); }
    void deleteSiliconSelect(bool toggle) { if(toggle) setDrawType(DrawType::DeleteSilicon); }
    void deleteMetalSelect(bool toggle) { if(toggle) setDrawType(DrawType::DeleteMetal); }

private:
    bool keyEvent(bool type, QEvent *event);

    Ui::MainWidget *ui;
    DrawType _drawType;
    bool _isShowMetal;
    QGraphicsScene *scene;
    QGraphicsSimpleTextItem *drawTypeItem;
    QGraphicsSimpleTextItem *showMetalItem;
};

QDebug operator<<(QDebug debug, MainWidget::DrawType drawType);

#endif // MAINWIDGET_H
