//
// Created by HUANG WEN JUN on 2019/11/5.
//

#include "clock_circle.h"
#include <QSGFlatColorMaterial>
#include <cmath>
ClockCircle::ClockCircle(QQuickItem* parent)
    : QQuickItem(parent), _backgroundColor(Qt::white),
      _borderActiveColor(Qt::blue), _borderNonActiveColor(Qt::gray), _angle(0),
      _circleTime(QTime(0, 0, 0, 0)) {
    setFlag(QQuickItem::ItemHasContents);
    setAntialiasing(true);

    _internalTimer = new QTimer(this);
    connect(_internalTimer, &QTimer::timeout, [=]() {
        setAngle(angle() + 0.3);
        setCircleTime(circleTime().addMSecs(50));
        update();
    });
}
QSGNode* ClockCircle::updatePaintNode(
    QSGNode* oldNode, QQuickItem::UpdatePaintNodeData* updatePaintNodeData) {
    Q_UNUSED(updatePaintNodeData)

    if (!oldNode) {
        auto drawCircle = [this](double radius, QSGGeometry* geometry) {
            for (int i = 0; i < 360; ++i) {
                double rad = (i - 90) * Deg2Rad;
                geometry->vertexDataAsPoint2D()[i].set(std::cos(rad) * radius +
                                                       width() / 2)
            }
        };

        auto borderNonActiveGeometry =
            new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 360);
        borderNonActiveGeometry->setDrawingMode(GL_POLYGON);
        drawCircle(width() / 2, borderNonActiveGeometry);

        auto borderNonActiveMaterial = new QSGFlatColorMaterial();
        borderNonActiveMaterial->setColor(_borderNonActiveColor);

        auto borderNonActiveNode = new QSGGeometryNode();
        borderNonActiveNode->setGeometry(borderNonActiveGeometry);
        borderNonActiveNode->setMaterial(borderNonActiveMaterial);
        borderNonActiveNode->setFlags(QSGNode::OwnsGeometry |
                                      QSGNode::OwnsMaterial);
    }
    return QQuickItem::updatePaintNode(oldNode, updatePaintNodeData);
}
