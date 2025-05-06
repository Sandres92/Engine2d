#ifndef OBJECTVIEWFACTORIES_H
#define OBJECTVIEWFACTORIES_H

#include "objectviewfactory.h"
#include <QMap>

namespace Engine2d {
class ObjectViewFactories {
public:
    ObjectViewFactories();
    ~ObjectViewFactories();

    ObjectViewFactories(const ObjectViewFactories&) = delete;
    ObjectViewFactories& operator=(const ObjectViewFactories&) = delete;

    static ObjectViewFactories& instance()
    {
        static ObjectViewFactories instance;
        return instance;
    }

    bool isContainsFactory(const QString& className);
    ObjectView* createObjectView(const QString& className);
    ObjectView* createObjectView(const QString& className, QXmlStreamReader& xml);
    ObjectView* createObjectView(const QString& className, float posx, float posy);

private:
    QMap<QString, ObjectViewFactory*> factories;
};
}
#endif // OBJECTVIEWFACTORIES_H
