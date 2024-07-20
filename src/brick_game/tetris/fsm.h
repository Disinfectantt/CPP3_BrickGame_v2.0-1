#ifndef TETRIS_FSM_H_
#define TETRIS_FSM_H_

#include "backend.h"
#include "objects.h"

typedef enum {
  START = 0,
  SPAWN,
  MOVING,
  ROTATE,
  SHIFTING,
  COLLIDE,
  GAMEOVER,
  EXIT_STATE,
  PAUSE
} tetris_state;

typedef enum {
  MOVE_DOWN = 0,
  MOVE_RIGHT,
  MOVE_LEFT,
  ESCAPE_BTN,
  ENTER_BTN,
  NOSIG
} ssignals;

GameInfo_t *get_gameInfo(GameInfo_t *gameInfo);
UserAction_t *get_UserAction_t(UserAction_t *sig);
bool *get_fallTime(bool *fallTime);
tetris_state *get_state(tetris_state *state);
Tetramino *get_current(Tetramino *current);
block *get_nextBlock(block *nextBlock);
void userInput(UserAction_t action, bool hold);
void sigact(UserAction_t *sig, const bool *fallTime, tetris_state *state,
            GameInfo_t *gameInfo, Tetramino *current);

void spawn_state(GameInfo_t *gameInfo, Tetramino *current, block *nextBlock,
                 tetris_state *state);
void move_state(UserAction_t *sig, GameInfo_t *gameInfo, Tetramino *current,
                tetris_state *state);
void pause_state(UserAction_t *sig, GameInfo_t *gameInfo, tetris_state *state);
int movedown(Tetramino *current, GameInfo_t *gameInfo);
void moveright(Tetramino *current, GameInfo_t *gameInfo);
void moveleft(Tetramino *current, GameInfo_t *gameInfo);
void movedown_clock_check(GameInfo_t *gameInfo, Tetramino *current,
                          tetris_state *state);
int rotate(Tetramino *current, GameInfo_t *gameInfo);
void rotate_I(Tetramino *current, GameInfo_t *gameInfo);
int rotate_J_first(Tetramino *current, GameInfo_t *gameInfo);
void rotate_J_second(Tetramino *current, GameInfo_t *gameInfo);
void rotate_J(Tetramino *current, GameInfo_t *gameInfo);
int rotate_L_first(Tetramino *current, GameInfo_t *gameInfo);
void rotate_L_second(Tetramino *current, GameInfo_t *gameInfo);
void rotate_L(Tetramino *current, GameInfo_t *gameInfo);
void rotate_S(Tetramino *current, GameInfo_t *gameInfo);
int rotate_T_first(Tetramino *current, GameInfo_t *gameInfo);
void rotate_T_second(Tetramino *current, GameInfo_t *gameInfo);
void rotate_T(Tetramino *current, GameInfo_t *gameInfo);
void rotate_Z(Tetramino *current, GameInfo_t *gameInfo);
void clear_backpos(Tetramino *current, GameInfo_t *gameInfo);

#endif  // TETRIS_FSM_H_
