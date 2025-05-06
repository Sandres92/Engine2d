#ifndef ELLIPSEVIEWFACTORY_H
#define ELLIPSEVIEWFACTORY_H

#include "objectviewfactory.h"

namespace Engine2d {
class EllipseViewFactory : public ObjectViewFactory {
public:
    ObjectView* createObjectView() override;
    ObjectView* createObjectView(QXmlStreamReader& xml) override;
    ObjectView* createObjectView(float posx, float posy) override;
};
}
#endif // ELLIPSEVIEWFACTORY_H
