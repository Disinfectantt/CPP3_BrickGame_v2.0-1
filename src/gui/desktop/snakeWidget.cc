#include "snakeWidget.h"

#include <QPainter>
#include <QTime>

SnakeWidget::SnakeWidget(QWidget *parent) : QWidget(parent) {
  setFocusPolicy(Qt::StrongFocus);
  oldSpeed = 0;
}

void SnakeWidget::setField() {
  GameInfo = controller.getAndUpdateGameInfo();
  if (GameInfo.speed != oldSpeed) {
    changeSpeed(GameInfo.speed);
    oldSpeed = GameInfo.speed;
  }
  update();
}

void SnakeWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  int cellWidth = width() / SNAKE_FIELD_WIDTH;
  int cellHeight = height() / SNAKE_FIELD_HEIGHT;
  for (int y = 0; y < SNAKE_FIELD_HEIGHT; ++y) {
    for (int x = 0; x < SNAKE_FIELD_WIDTH; ++x) {
      QRect cellRect(x * cellWidth, y * cellHeight, cellWidth, cellHeight);
      if (GameInfo.field[y][x] == s21::SNAKE) {
        painter.fillRect(cellRect, Qt::gray);
      } else if (GameInfo.field[y][x] == s21::FOOD) {
        painter.fillRect(cellRect, Qt::green);
      }
      painter.drawRect(cellRect);
    }
  }
  if (GameInfo.pause == 1 && GameInfo.level != s21::GAME_OVER) {
    drawTextCenter(Qt::black, event, &painter, "PAUSE\nPRESS ENTER");
  }
  if (GameInfo.level == s21::GAME_OVER) {
    drawTextCenter(Qt::red, event, &painter, "GAME OVER\nPRESS CTRL");
  }
  if (GameInfo.level == s21::VICTORY) {
    drawTextCenter(Qt::green, event, &painter, "YOU WON\nPRESS CTRL");
  }
}

void SnakeWidget::keyPressEvent(QKeyEvent *event) {
  int key = event->key();
  s21::UserAction_t action = s21::Action;
  bool hold = false;
  if (key == Qt::Key_Control) {
    action = s21::Start;
  }
  if (key == Qt::Key_Enter || key == Qt::Key_Return) {
    action = s21::Pause;
  }
  if (key == Qt::Key_Escape) {
    action = s21::Terminate;
  }
  if (key == Qt::Key_Left) {
    action = s21::Left;
  }
  if (key == Qt::Key_Right) {
    action = s21::Right;
  }
  if (key == Qt::Key_Up) {
    action = s21::Up;
  }
  if (key == Qt::Key_Down) {
    action = s21::Down;
  }
  if (key == Qt::Key_Space) {
    action = s21::Action;
    hold = true;
  }
  controller.userInput(action, hold);
}

void SnakeWidget::keyReleaseEvent(QKeyEvent *event) {
  int key = event->key();
  if (key == Qt::Key_Space) {
    controller.userInput(s21::Action, false);
  }
}

s21::GameInfo_t *SnakeWidget::getGameInfo() { return &GameInfo; }

void SnakeWidget::drawTextCenter(QColor color, QPaintEvent *event,
                                 QPainter *painter, const QString &text) {
  QFont font = painter->font();
  font.setPointSize(50);
  font.setBold(true);
  painter->setFont(font);
  QRect rect = event->rect();
  QRect textRect = rect;
  textRect.moveTop(textRect.top() - font.pointSize() / 2);
  painter->setPen(color);
  painter->setRenderHint(QPainter::TextAntialiasing);
  painter->drawText(textRect, Qt::AlignCenter, text);
}

void SnakeWidget::changeSpeed(int newSpeed) {
  GameInfo.speed = newSpeed;
  emit speedChanged(newSpeed);
}
