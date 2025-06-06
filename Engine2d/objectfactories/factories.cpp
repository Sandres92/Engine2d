#include "factories.h"

namespace Engine2d {
ObjectView* Factories::createObjectView(const QString& className, QXmlStreamReader& xml)
{
    return ObjectViewFactories::instance().createObjectView(className, xml);
}

Window* Factories::createWindow(const QXmlStreamReader& xml)
{
    return WindowFactory::instance().createWindow(xml);
}
}
