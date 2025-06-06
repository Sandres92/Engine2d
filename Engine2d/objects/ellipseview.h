#ifndef ELLIPSEVIEW_H
#define ELLIPSEVIEW_H

#include <QPaintDevice>
#include <QString>
#include <QWidget>

#include "objectview.h"

namespace Engine2d {
class EllipseView : public ObjectView {
    Q_OBJECT

public:
    explicit EllipseView();
    explicit EllipseView(const QString& name, float posx, float posy);
    explicit EllipseView(const QString& name, float posx, float posy, float width, float height, int angle, bool lock,
        const QColor& lineColor, int lineWidth, bool fill, const QColor& fillColor);

    ~EllipseView();
    EllipseView* clone() override;

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEventHandler() override;
};
}
#endif // ELLIPSEVIEW_H
