#ifndef SNAKE_FRONT_H
#define SNAKE_FRONT_H

#define CLI_SNAKE_FOOD "*"
#define CLI_SNAKE "O"

#include <ncurses.h>

#include <chrono>
#include <iostream>
#include <thread>

#include "../../brick_game/snake/controller/snakeController.h"
#include "../../brick_game/snake/snakeStruct.h"

namespace s21 {

class snakeFront {
 private:
  s21::GameInfo_t GameInfo;
  s21::snakeController controller;
  int oldSpeed;

 private:
  void print_text(std::string text);
  void drawBorder();
  void drawField();
  void drawStats();
  UserAction_t btnHandling(int ch);
  void isSpacePressed(int ch);

 public:
  snakeFront();
  void snakeGame();
};

}  // namespace s21

#endif