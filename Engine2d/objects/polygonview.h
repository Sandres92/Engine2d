#ifndef POLYGONVIEW_H
#define POLYGONVIEW_H

#include <QPaintDevice>
#include <QPointF>
#include <QString>
#include <QVector>
#include <QWidget>

#include "objectview.h"
#include <QVariantList>

namespace Engine2d {
class PolygonView : public ObjectView {
    Q_OBJECT
    // Q_PROPERTY(QString coords READ getCoordsString)
    // Q_PROPERTY(QVector<QPointF> coords READ getCoords)
    Q_PROPERTY(QVariantList coords READ getCoordsAsVariantList WRITE setCoordsFromVariantList)

public:
    explicit PolygonView();
    explicit PolygonView(const QString& name, float posx, float posy);
    explicit PolygonView(const QString& name, float posx, float posy, float width, float height, int angle, bool lock,
        const QColor& lineColor, int lineWidth, bool fill, const QColor& fillColor);
    ~PolygonView() = default;

    void setCoords(const QVector<QPointF>& coords);
    void addCoord(const QPointF& coord);
    QVector<QPointF> getCoords() const;
    QString getCoordsString() const;
    QVariantList getCoordsAsVariantList() const;
    void setCoordsFromVariantList(const QVariantList& coordsVariantList);
    PolygonView* clone() override;

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEventHandler() override;

    void saveToStream(QDataStream& out) const override;
    void loadFromStream(QDataStream& in) override;

private:
    QVector<QPointF> coords;
};
}
#endif // POLYGONVIEW_H
