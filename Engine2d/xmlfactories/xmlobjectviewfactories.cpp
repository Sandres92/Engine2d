#include "xmlobjectviewfactories.h"

#include "xmlellipseviewfactory.h"
#include "xmlpolygonviewfactory.h"
#include "xmlrectangleviewfactory.h"

#include "utility/convector.h"

namespace Engine2d {
XMLObjectViewFactories::XMLObjectViewFactories()
{
    factories["EllipseView"] = new XMLEllipseViewFactory();
    factories["RectangleView"] = new XMLRectangleViewFactory();
    factories["PolygonView"] = new XMLPolygonViewFactory();
}

bool XMLObjectViewFactories::isContainsFactory(const QString& className)
{
    return factories.contains(className);
}

void XMLObjectViewFactories::fillXMLAttributeForObjectView(const ObjectView& objectView, QXmlStreamWriter& xml)
{
    QString className = Convector::fullCalssNameToShort(objectView.metaObject()->className());

    if (factories.contains(className)) {
        factories[className]->fillXMLAttributeForObjectView(objectView, xml);
    }
}
}
