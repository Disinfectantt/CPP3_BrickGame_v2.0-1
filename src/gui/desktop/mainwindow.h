#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QTimer>

#include "snakeWidget.h"
#include "tetrisWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  SnakeWidget *snakeWidget;
  QTimer *gameTimer;
  QLabel *snakeScore;
  QLabel *snakeMaxScore;
  QLabel *snakeLevel;

 private:
  void updateField();
  void updateLabels();
  void handleSpeedChange(int newSpeed);
};
#endif  // MAINWINDOW_H
