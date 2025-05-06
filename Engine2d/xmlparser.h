#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "objectfactories/factories.h"
#include "xmlfactories/xmlfactories.h"
#include <QMap>
#include <QString>

namespace Engine2d {
class XMLParser : public QObject {
    Q_OBJECT

public:
    XMLParser(QObject* parent = nullptr);
    ~XMLParser() = default;

    QList<Window*> load();
    void save(QList<Window*> windows);

signals:
    void xmlLoaded(QList<Window*> windows);

private:
    Factories factories;
    Engine2d::XMLFactories XMLFactories;
};
}
#endif // XMLPARSER_H
