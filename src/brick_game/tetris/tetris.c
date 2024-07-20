#include "tetris.h"

void handle_user_input(UserAction_t sig) {
  static GameInfo_t *gameInfo = NULL;
  static tetris_state *state = NULL;
  static Tetramino *current = NULL;
  static bool *fallTime = NULL;

  if (gameInfo == NULL) {
    gameInfo = get_gameInfo(NULL);
    state = get_state(NULL);
    current = get_current(NULL);
    fallTime = get_fallTime(NULL);
  }
  sigact(&sig, fallTime, state, gameInfo, current);
}

tetris_state game_loop(GameInfo_t *gameInfo, UserAction_t sig) {
  static tetris_state state;
  static Tetramino current;
  static block nextBlock;
  static bool fallTime;
  static clock_t clock1;

  if (gameInfo == NULL) {
    fallTime = 0;
    clock1 = clock();
    nextBlock = rand() % 7;
    state = SPAWN;
    current.rotate_state = 0;
    current.type = 0;
    current.x1 = current.x2 = current.x3 = current.x4 = 0;
    current.y1 = current.y2 = current.y3 = current.y4 = 0;

    get_state(&state);
    get_current(&current);
    get_nextBlock(&nextBlock);
    get_fallTime(&fallTime);
  } else {
    get_gameInfo(gameInfo);
    clock_t clock2 = clock();
    if (clock2 - clock1 >= 12000 - ((clock_t)gameInfo->speed * 150 + 10000)) {
      clock1 = clock2;
      fallTime = 1;
      get_fallTime(&fallTime);
    }
    if (state == SPAWN) {
      if (spawn_block(gameInfo, nextBlock, &current)) {
        state = GAMEOVER;
      } else {
        nextBlock = rand() % 7;
        next_update(gameInfo, nextBlock);
        board_update(gameInfo, &current);
        state = MOVING;
        if (gameInfo->pause == 1) {
          state = PAUSE;
        }
      }
    }
    sigact(&sig, &fallTime, &state, gameInfo, &current);
    fallTime = 0;
  }

  return state;
}
