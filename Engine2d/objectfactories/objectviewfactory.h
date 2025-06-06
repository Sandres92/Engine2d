#ifndef OBJECTVIEWFACTORY_H
#define OBJECTVIEWFACTORY_H

#include <QXmlStreamAttributes>
#include <QXmlStreamReader>

#include "objects/objectview.h"
#include "utility/convector.h"

namespace Engine2d {
class ObjectViewFactory {
public:
    explicit ObjectViewFactory() = default;
    virtual ~ObjectViewFactory() = default;

    virtual ObjectView* createObjectView() = 0;
    virtual ObjectView* createObjectView(QXmlStreamReader& xml) = 0;
    virtual ObjectView* createObjectView(float posx, float posy) = 0;

protected:
    template <typename T>
    T* createCommonObjectView(const QXmlStreamReader& xml)
    {
        static_assert(std::is_base_of<ObjectView, T>::value, "T must be a descendant of ObjectView");

        const QString name = xml.attributes().value("name").toString();
        const float posx = xml.attributes().value("posx").toFloat();
        const float posy = xml.attributes().value("posy").toFloat();

        const float width = xml.attributes().value("width").toFloat();
        const float height = xml.attributes().value("height").toFloat();

        const int angle = xml.attributes().value("angle").toInt();
        const bool lock = Convector::stringToBool(xml.attributes().value("lock").toString());

        const QColor lineColor = Convector::stringHexToColor(xml.attributes().value("color").toString());
        const int lineWidth = xml.attributes().value("linewidth").toInt();
        const bool fill = Convector::stringToBool(xml.attributes().value("fill").toString());

        const QColor fillColor = Convector::stringHexToColor(xml.attributes().value("fillcolor").toString());

        return new T(name, posx, posy, width, height, angle,
            lock, lineColor, lineWidth, fill, fillColor);
    }

    template <typename T>
    T* createCommonObjectView(const QString& name, float posx, float posy)
    {
        static_assert(std::is_base_of<ObjectView, T>::value, "T must be a descendant of ObjectView");

        return new T(name, posx, posy);
    }
};
}
#endif // OBJECTVIEWFACTORY_H
