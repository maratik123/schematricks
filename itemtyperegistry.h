#ifndef ITEMTYPEREGISTRY
#define ITEMTYPEREGISTRY

#include <QGraphicsItem>

namespace SchemaItem {

enum class ItemType {
    Metal = QGraphicsItem::UserType + 1, SiliconN, SiliconP, Via, PNP, NPN
};

namespace ItemLevel {
    constexpr int Metal = 15;
    constexpr int Silicon = 5;
    constexpr int Via = 10;
}

}

#endif // ITEMTYPEREGISTRY
