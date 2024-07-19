#ifndef S21_SNAKE_H
#define S21_SNAKE_H

#include <iostream>
#include <random>

#include "snakeStruct.h"

namespace s21 {

class snake {
 private:
  GameInfo_t *gameInfo;
  int *snake_tail_x;
  int *snake_tail_y;
  int snake_head_x;
  int snake_head_y;
  int fruit_x;
  int fruit_y;
  int snake_size;
  UserAction_t current_direction;
  std::mt19937 engine;

 private:
  void startGame();
  void initStruct();
  void checkCollision();
  void randFruit();
  void updateSnakePos();
  void generateField();
  bool addSnakeToField(int i, int j);
  void switchPause();

 public:
  snake(GameInfo_t *GameInfo_t);
  ~snake();
  void userInput(UserAction_t action, bool hold);
  GameInfo_t updateCurrentState();
};

}  // namespace s21

#endif