#include "ellipseview.h"

#include <QDebug>
#include <QPainter>

namespace Engine2d {
EllipseView::EllipseView()
    : ObjectView("Эллипс")
{
}

EllipseView::EllipseView(const QString& name, float posx, float posy)
    : ObjectView(name, posx, posy, 75.f, 75.f, 0, false,
          QColor(0, 0, 0, 255), 2, true, QColor(204, 51, 51, 255))
{
}

EllipseView::EllipseView(const QString& name, float posx, float posy, float width, float height, int angle, bool lock,
    const QColor& lineColor, int linewidth, bool fill, const QColor& fillColor)
    : ObjectView(name, posx, posy, width, height, angle, lock, lineColor, linewidth, fill, fillColor)
{
}

EllipseView::~EllipseView()
{
}

void EllipseView::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    if (fill) {
        painter.setBrush(fillColor);
    }

    painter.setPen(QPen(lineColor, lineWidth));

    painter.setRenderHint(QPainter::Antialiasing);

    QRect ellipse(lineWidth / 2.f, lineWidth / 2.f, width - lineWidth / 2.f, height - lineWidth / 2.f);
    painter.drawEllipse(ellipse);
}

void EllipseView::mousePressEventHandler()
{
}

EllipseView* EllipseView::clone()
{
    EllipseView* newObjectView = new EllipseView(this->name, this->posx, this->posy, this->width,
        this->height, this->angle, this->lock, this->lineColor,
        this->lineWidth, this->fill, this->fillColor);
    // newObjectView->setParent(this->parentWidget());
    return newObjectView;
}
}
