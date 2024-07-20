#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  snakeWidget = ui->Snake_Widget;
  snakeWidget->setField();
  gameTimer = new QTimer(this);
  snakeLevel = ui->snake_level;
  snakeScore = ui->snake_score;
  snakeMaxScore = ui->snake_max_score;
  tetrisLevel = ui->tetris_level;
  tetrisScore = ui->tetris_score;
  tetrisMaxScore = ui->tetris_max_score;

  connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateLabels);
  connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateField);
  connect(snakeWidget, &SnakeWidget::speedChanged, this,
          &MainWindow::handleSpeedChange);
  gameTimer->start(snakeWidget->getGameInfo()->speed);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateField() { snakeWidget->setField(); }

void MainWindow::updateLabels() {
  snakeLevel->setText(QString::number(snakeWidget->getGameInfo()->level));
  snakeScore->setText(QString::number(snakeWidget->getGameInfo()->score));
  snakeMaxScore->setText(
      QString::number(snakeWidget->getGameInfo()->high_score));
}

void MainWindow::handleSpeedChange(int newSpeed) { gameTimer->start(newSpeed); }
