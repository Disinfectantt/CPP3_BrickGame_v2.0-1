#ifndef S21_SNAKE_H
#define S21_SNAKE_H

#define SHAKE_FIELD_WIDTH 20
#define SNAKE_FILED_HEIGHT 10

#include <iostream>

namespace s21 {

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score = 0;
  int high_score = 0;
  int level = 0;
  int speed = 0;
  int pause = 0;
  int snake_size = 0;
} GameInfo_t;

class snake {
 private:
  UserAction_t userAction;
  GameInfo_t gameInfo;

 public:
  snake(GameInfo_t GameInfo_t);
  ~snake();
  void SnakeGameLoop();
  void userInput(UserAction_t action, bool hold);
  GameInfo_t updateCurrentState();
};

}  // namespace s21

#endif