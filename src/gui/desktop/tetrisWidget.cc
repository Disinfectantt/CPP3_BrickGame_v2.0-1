#include "tetrisWidget.h"

tetrisWidget::tetrisWidget(QWidget *parent) : QWidget(parent), m_cellSize(25) {
  setFocusPolicy(Qt::StrongFocus);
  m_timer = new QTimer(this);
  connect(m_timer, &QTimer::timeout, this, &tetrisWidget::onTimerTick);
  m_timer->start(100);
  infoInit(&m_gameInfo);
  action = (UserAction_t)-1;
  state = game_loop(nullptr, action);
}

tetrisWidget::~tetrisWidget() { infoFree(&m_gameInfo); }

void tetrisWidget::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  drawBoard(&painter);
  drawNextPiece(&painter);
  drawStats(&painter);
  if (m_gameInfo.pause == 1) {
    drawTextCenter(Qt::black, event, &painter, "PAUSE");
  }
  if (state == GAMEOVER) {
    drawTextCenter(Qt::red, event, &painter, "GAME OVER\nPRESS ENTER");
  }
}

void tetrisWidget::keyPressEvent(QKeyEvent *event) {
  action = (UserAction_t)-1;
  int key = event->key();
  if (key == Qt::Key_Up) {
    action = Up;
  }
  if (key == Qt::Key_Down) {
    action = Down;
  }
  if (key == Qt::Key_Left) {
    action = Left;
  }
  if (key == Qt::Key_Right) {
    action = Right;
  }
  if (key == Qt::Key_Escape) {
    action = Terminate;
    QCoreApplication::quit();
  }
  if (key == Qt::Key_Return || key == Qt::Key_Enter) {
    action = Action;
  }
  if (key == Qt::Key_Space) {
    action = Pause;
  }
  if (state == GAMEOVER && (key == Qt::Key_Return || key == Qt::Key_Enter)) {
    infoFree(&m_gameInfo);
    infoInit(&m_gameInfo);
    state = game_loop(nullptr, action);
  }
  handle_user_input(action);
  update();
}

void tetrisWidget::drawBoard(QPainter *painter) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 20; y++) {
      painter->setPen(QPen(Qt::darkGray, 1));
      QRect rect(x * m_cellSize, y * m_cellSize, m_cellSize, m_cellSize);
      if (m_gameInfo.field[x][y] == 1) {
        painter->fillRect(rect, Qt::gray);
      }
      painter->drawRect(rect);
    }
  }
}

void tetrisWidget::drawNextPiece(QPainter *painter) {
  int startX = 11 * m_cellSize;
  int startY = m_cellSize;
  painter->drawText(startX, startY - 5, "NEXT");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (m_gameInfo.next[j][i] == 1) {
        QRect rect(startX + i * m_cellSize, startY + j * m_cellSize, m_cellSize,
                   m_cellSize);
        painter->fillRect(rect, Qt::gray);
      }
    }
  }
}

void tetrisWidget::drawStats(QPainter *painter) {
  int startX = 11 * m_cellSize;
  int startY = 6 * m_cellSize;
  painter->drawText(startX, startY, QString("LEVEL: %1").arg(m_gameInfo.level));
  painter->drawText(startX, startY + m_cellSize,
                    QString("SPEED: %1").arg(m_gameInfo.speed));
  painter->drawText(startX, startY + 2 * m_cellSize,
                    QString("SCORE: %1").arg(m_gameInfo.score));
  painter->drawText(startX, startY + 3 * m_cellSize,
                    QString("HIGH SCORE: %1").arg(m_gameInfo.high_score));
}

void tetrisWidget::onTimerTick() {
  state = game_loop(&m_gameInfo, (UserAction_t)-1);
  update();
  int interval = 1000 - (m_gameInfo.speed * 50);
  m_timer->setInterval(qMax(100, interval));
}

void tetrisWidget::drawTextCenter(QColor color, QPaintEvent *event,
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
