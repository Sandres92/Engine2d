#ifndef XMLOBJECTVIEWFACTORY_H
#define XMLOBJECTVIEWFACTORY_H

#include "objects/objectview.h"
#include <QByteArray>
#include <QXmlStreamWriter>

namespace Engine2d {
class XMLObjectViewFactory {
public:
    XMLObjectViewFactory() = default;

    const QByteArray objectViewToXML(const ObjectView& objectView) const;
    void fillXMLAttributeForObjectView(const ObjectView& objectView, QXmlStreamWriter& xml);

private:
    virtual void addAdditionalXMLElements(const ObjectView& objectView, QXmlStreamWriter& xml) const;
};
}
#endif // XMLOBJECTVIEWFACTORY_H
