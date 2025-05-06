#ifndef RECTANGLEVIEW_H
#define RECTANGLEVIEW_H

#include <QPaintDevice>
#include <QString>
#include <QWidget>

#include "objectview.h"

namespace Engine2d {
class RectangleView : public ObjectView {
    Q_OBJECT

public:
    explicit RectangleView();
    explicit RectangleView(const QString& name, float posx, float posy);
    explicit RectangleView(const QString& name, float posx, float posy, float width, float height, int angle, bool lock,
        const QColor& lineColor, int lineWidth, bool fill, const QColor& fillColor);
    ~RectangleView() = default;
    virtual RectangleView* clone() override;

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEventHandler() override;
};
}
#endif // RECTANGLEVIEW_H
