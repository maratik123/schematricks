#ifndef SCHEMAITEMTYPEREGISTRY
#define SCHEMAITEMTYPEREGISTRY

#include <QGraphicsItem>

enum class SchemaItemType {
    Metal = QGraphicsItem::UserType + 1, SiliconN, SiliconP, Via, PNP, NPN
};

namespace SchemaItemLevel {
    const int Metal = 15;
    const int Silicon = 5;
    const int Via = 10;
};

#endif // SCHEMAITEMTYPEREGISTRY

