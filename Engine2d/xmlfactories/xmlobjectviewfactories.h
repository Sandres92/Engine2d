#ifndef XMLOBJECTVIEWFACTORIES_H
#define XMLOBJECTVIEWFACTORIES_H

#include "xmlobjectviewfactory.h"
#include <QMap>
#include <QString>

namespace Engine2d {
class XMLObjectViewFactories {
public:
    XMLObjectViewFactories();

    static XMLObjectViewFactories& instance()
    {
        static XMLObjectViewFactories instance;
        return instance;
    }

    bool isContainsFactory(const QString& className);
    void fillXMLAttributeForObjectView(const ObjectView& objectView, QXmlStreamWriter& xml);

private:
    QMap<QString, XMLObjectViewFactory*> factories;
};
}
#endif // XMLOBJECTVIEWFACTORIES_H
