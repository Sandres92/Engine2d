#ifndef ENGINE_H
#define ENGINE_H

#include "xmlparser.h"
#include <QDebug>
#include <QShortcut>
#include <QWidget>

namespace Engine2d {
class Engine {
public:
    Engine();
    ~Engine();

    void init();

private slots:
    void slotShortcutCtrlS();

private:
    void loadXML();
    void saveXML();

    XMLParser xMLParser;
    QList<Window*> windows;

    QShortcut* keyCtrlS;
};
}

#endif // ENGINE_H
