#ifndef ABSTRACTSCHEMAITEM_H
#define ABSTRACTSCHEMAITEM_H

#include <QGraphicsItem>

enum class SchemaItemType;

class AbstractSchemaItem : public QGraphicsItem
{
    Q_DISABLE_COPY(AbstractSchemaItem)

public:
    explicit AbstractSchemaItem(int i, int j, qreal cellSize, QGraphicsItem *parent = nullptr);
    qreal gridSize() const { return _cellSize; }

    int type() const { return static_cast<int>(schemaItemType()); }
    int i() const { return _i; }
    int j() const { return _j; }
    void setI(int i) { _i = i; setX(i * _cellSize); }
    void setJ(int j) { _j = j; setY(j * _cellSize); }
    virtual SchemaItemType schemaItemType() const = 0;

private:
    const qreal _cellSize;
    int _i;
    int _j;
};

#endif // ABSTRACTSCHEMAITEM_H
