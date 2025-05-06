#ifndef FACTORIES_H
#define FACTORIES_H

#include "objectviewfactory.h"
#include "windowfactory.h"
#include <QString>

namespace Engine2d {
class Factories {
public:
    Factories() = default;
    ~Factories() = default;

    Window* createWindow(const QXmlStreamReader& xml);
    ObjectView* createObjectView(const QString& className, QXmlStreamReader& xml);
};
}
#endif // FACTORIES_H
