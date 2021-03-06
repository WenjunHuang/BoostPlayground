#pragma once


#include <QGraphicsObject>

class RobotPart: public QGraphicsObject {
public:
  RobotPart(QGraphicsItem *parent = nullptr);

protected:
  void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
  void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
  void dropEvent(QGraphicsSceneDragDropEvent *event) override;

  QColor color;
  bool dragOver;
};

class RobotHead: public RobotPart {
public:
  RobotHead(QGraphicsItem *parent = nullptr);

  QRectF boundingRect() const override;
  void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget = nullptr) override;

protected:
  void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;
  void dropEvent(QGraphicsSceneDragDropEvent *event) override;

private:
  QPixmap pixmap;
};

class RobotTorso: public RobotPart {
public:
  RobotTorso(QGraphicsItem *parent = nullptr);

  QRectF boundingRect() const override;
  void paint(QPainter* painter,const QStyleOptionGraphicsItem* option,QWidget *widget = nullptr) override;
};

class RobotLimb: public RobotPart {
public:
  RobotLimb(QGraphicsItem* parent = nullptr);

  QRectF boundingRect() const override;
  void paint(QPainter *painter,const QStyleOptionGraphicsItem* option,QWidget *widget = nullptr) override;
};

class Robot: public RobotPart {
public:
  Robot(QGraphicsItem *parent = nullptr);

  QRectF boundingRect() const override;
  void paint(QPainter *painter,const QStyleOptionGraphicsItem* option,QWidget *widget = nullptr) override;
};


