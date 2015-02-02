#ifndef ABSTRACTSCHEMAITEM_H
#define ABSTRACTSCHEMAITEM_H

#include <QGraphicsItem>

class AbstractSchemaItem : public QGraphicsItem
{
    Q_DISABLE_COPY(AbstractSchemaItem)
public:
    explicit AbstractSchemaItem(QGraphicsItem *parent = nullptr) : QGraphicsItem(parent) {}
};

#endif // ABSTRACTSCHEMAITEM_H
