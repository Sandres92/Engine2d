#ifndef XMLPOLYGONVIEWFACTORY_H
#define XMLPOLYGONVIEWFACTORY_H

#include "objects/objectview.h"
#include "xmlobjectviewfactory.h"
#include <QXmlStreamWriter>

namespace Engine2d {
class XMLPolygonViewFactory : public XMLObjectViewFactory {
public:
    XMLPolygonViewFactory();

protected:
    void addAdditionalXMLElements(const ObjectView& objectView, QXmlStreamWriter& xml) const override;
};
}
#endif // XMLPOLYGONVIEWFACTORY_H
