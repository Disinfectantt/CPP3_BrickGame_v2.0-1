#ifndef SNAKE_STRUCT_H
#define SNAKE_STRICT_H

#define SNAKE_FIELD_WIDTH 20
#define SNAKE_FIELD_HEIGHT 10
#define SNAKE_INIT_SIZE 4
#define DEFAULT_SPEED 100

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

typedef enum {
  SNAKE,
  FOOD
} field_points;

typedef enum {
  GAME_OVER = -1,
  START_SCREEN = -2
} gameStatus;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

#endif