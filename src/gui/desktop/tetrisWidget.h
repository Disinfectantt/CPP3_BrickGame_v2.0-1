#ifndef TETRIS_WIDGET_H
#define TETRIS_WIDGET_H

#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>

#ifdef __cplusplus
extern "C" {
#endif

#include "../../brick_game/tetris/tetris.h"

#ifdef __cplusplus
}
#endif

class tetrisWidget : public QWidget {
  Q_OBJECT

 private:
  GameInfo_t m_gameInfo;
  int m_cellSize;
  QTimer *m_timer;
  int state;
  UserAction_t action;

 public:
  tetrisWidget(QWidget *parent = nullptr);
  ~tetrisWidget();

 protected:
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

 private:
  void drawBoard(QPainter *painter);
  void drawNextPiece(QPainter *painter);
  void drawStats(QPainter *painter);
  void drawTextCenter(QColor color, QPaintEvent *event, QPainter *painter,
                      const QString &text);

 private slots:
  void onTimerTick();
};

#endif