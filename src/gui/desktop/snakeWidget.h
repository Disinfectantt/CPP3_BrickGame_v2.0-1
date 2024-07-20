#ifndef SNAKEWIDGET_H
#define SNAKEWIDGET_H

#include <QKeyEvent>
#include <QWidget>

#include "../../brick_game/snake/controller/snakeController.h"
#include "../../brick_game/snake/snakeStruct.h"

class SnakeWidget : public QWidget {
  Q_OBJECT
 private:
  s21::GameInfo_t GameInfo;
  s21::snakeController controller;
  int oldSpeed;

 private:
  void drawTextCenter(QColor color, QPaintEvent *event, QPainter *painter,
                      const QString &text);

 public:
  SnakeWidget(QWidget *parent = nullptr);
  void setField();
  s21::GameInfo_t *getGameInfo();
  void changeSpeed(int newSpeed);

 protected:
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;
  void keyReleaseEvent(QKeyEvent *event) override;

 signals:
  void speedChanged(int newSpeed);
};
#endif
