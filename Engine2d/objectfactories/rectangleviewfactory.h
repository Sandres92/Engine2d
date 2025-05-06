#ifndef RECTANGLEVIEWFACTORY_H
#define RECTANGLEVIEWFACTORY_H

#include "objectviewfactory.h"

namespace Engine2d {
class RectangleViewFactory : public ObjectViewFactory {
public:
    ObjectView* createObjectView() override;
    ObjectView* createObjectView(QXmlStreamReader& xml) override;
    ObjectView* createObjectView(float posx, float posy) override;
};
}

#endif // RECTANGLEVIEWFACTORY_H
