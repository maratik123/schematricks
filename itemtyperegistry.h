#ifndef ITEMTYPEREGISTRY
#define ITEMTYPEREGISTRY

#include <QGraphicsItem>

namespace SchemaItem {

enum class ItemType {
    Metal = QGraphicsItem::UserType + 1, SiliconN, SiliconP, Via, PNP, NPN
};

namespace ItemLevel {
    const int Metal = 15;
    const int Silicon = 5;
    const int Via = 10;
}

}

#endif // ITEMTYPEREGISTRY
