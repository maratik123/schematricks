#ifndef SCHEMAITEMTYPEREGISTRY
#define SCHEMAITEMTYPEREGISTRY

#include <QGraphicsItem>

enum class SchemaItemType {
    Metal = QGraphicsItem::UserType + 1, SiliconN, SiliconP, Via, PNP, NPN
};

#endif // SCHEMAITEMTYPEREGISTRY

