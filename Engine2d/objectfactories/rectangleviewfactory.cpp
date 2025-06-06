#include "rectangleviewfactory.h"

#include "objects/rectangleview.h"

namespace Engine2d {
ObjectView* RectangleViewFactory::createObjectView()
{
    RectangleView* rectangleView = new RectangleView();
    return rectangleView;
}

ObjectView* RectangleViewFactory::createObjectView(QXmlStreamReader& xml)
{
    return createCommonObjectView<RectangleView>(xml);
}

ObjectView* RectangleViewFactory::createObjectView(float posx, float posy)
{
    RectangleView* ellipseView = createCommonObjectView<RectangleView>("Прямоугольник", posx, posy);
    return ellipseView;
}
}
