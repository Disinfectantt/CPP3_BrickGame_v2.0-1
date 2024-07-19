#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  snakeWidget = ui->Snake_Widget;
  snakeWidget->setField();
  gameTimer = new QTimer(this);
  connect(gameTimer, &QTimer::timeout, this, &MainWindow::updateField);
  gameTimer->start(snakeWidget->getGameInfo()->speed);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::updateField() { snakeWidget->setField(); }
