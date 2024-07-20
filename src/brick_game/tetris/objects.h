#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ESCAPE 27
#define ENTER_KEY 10

#define LEFT_X 0
#define RIGHT_X 21
#define TOP_Y 0
#define BOT_Y 20

#define NEXT_LEFT_X 24
#define NEXT_RIGHT_X 33
#define NEXT_TOP_Y 1
#define NEXT_BOT_Y 5

typedef enum { I = 0, J, L, O, S, T, Z } block;

typedef struct {
  int x1;
  int y1;

  int x2;
  int y2;

  int x3;
  int y3;

  int x4;
  int y4;

  block type;
  int rotate_state;
} Tetramino;

typedef enum { first = 0, second, third, fourth } rotateState;

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
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

#endif
