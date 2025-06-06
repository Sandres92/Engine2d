#include "xmlparser.h"

#include <QXmlStreamEntityDeclaration>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include <QDebug>
#include <QFile>

namespace Engine2d {
XMLParser::XMLParser(QObject* parent)
    : QObject(parent)
{
}

QList<Window*> XMLParser::load()
{
    // QString filePath = QDir::currentPath() + "/window_description.xml";
    QString filePath = QCoreApplication::applicationDirPath() + "/window_description.xml";
    qDebug() << "Load file " << filePath;

    QFile file(filePath);
    QList<Window*> windows;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error open file to read! Error = " << file.errorString();
        return windows;
    }

    QXmlStreamReader xml(&file);
    Window* window = nullptr;

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (token == QXmlStreamReader::StartDocument) {
            continue;
        }

        if (token == QXmlStreamReader::StartElement) {
            if (xml.name() == "window") {
                window = factories.createWindow(xml);
                windows.append(window);

                continue;
            }

            if (xml.name() == "objectView") {
                QString className = xml.attributes().value("class").toString();
                ObjectView* objectView = factories.createObjectView(className, xml);

                if (objectView != nullptr) {
                    window->addObjectView(objectView);
                }

                // if (className == "EllipseView") {
                //     EllipseView *ellipseView = ellipseViewFactory.createObjectView(xml);
                //     ellipseView->setParent(window);
                // }
                // else if (className == "RectangleView") {
                //     RectangleView *rectangleView = rectangleViewFactory.createObjectView(xml);
                //     rectangleView->setParent(window);
                // }
                // else if (className == "PolygonView") {
                //     PolygonView *polygonView = polygonViewFactory.createObjectView(xml);
                //     polygonView->setParent(window);
                // }
            }
        }
    }

    for (int i = 0; i < windows.size(); i++) {
        windows[i]->show();
    }

    file.close();

    emit xmlLoaded(windows);
    return windows;
}

void XMLParser::save(QList<Window*> windows)
{
    QString filePath = QCoreApplication::applicationDirPath() + "/window_description.xml";
    qDebug() << "Save file " << filePath;

    QFileInfo fileInfo(filePath);
    QFile file(filePath);

    if (!fileInfo.exists()) {
        qDebug() << "File for write not exist";
        // TODO: create file
    }

    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Error open file to write! Error = " << file.errorString();
        return;
    }

    QXmlStreamWriter xml(&file);
    xml.setAutoFormatting(true);
    // xml.writeStartDocument();

    qDebug() << "windows.size()  " << windows.size();

    for (int i = 0; i < windows.size(); i++) {
        xml.writeStartElement("window");
        XMLFactories.fillXMLAttributeForWindow(*windows[i], xml);

        QList<ObjectView*> objectViews = windows[i]->getObjectViews();

        for (int j = 0; j < objectViews.size(); j++) {
            xml.writeStartElement("objectView");
            XMLFactories.fillXMLAttributeForObjectView(*objectViews[j], xml);
            xml.writeEndElement();
        }

        // QByteArray partXml = factories.windowToXML(*windows[i]);
        // file.write(partXml);

        xml.writeEndElement();
    }

    // xml.writeEndDocument();
    qDebug() << "File was saved " << filePath;

    file.close();
}
}
