#include "ellipseviewfactory.h"

#include "objects/ellipseview.h"

namespace Engine2d {
ObjectView* EllipseViewFactory::createObjectView()
{
    EllipseView* ellipseView = new EllipseView();
    return ellipseView;
}

ObjectView* EllipseViewFactory::createObjectView(QXmlStreamReader& xml)
{
    EllipseView* ellipseView = createCommonObjectView<EllipseView>(xml);
    return ellipseView;
}

ObjectView* EllipseViewFactory::createObjectView(float posx, float posy)
{
    EllipseView* ellipseView = createCommonObjectView<EllipseView>("Эллипс", posx, posy);
    return ellipseView;
}
}
