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
  return mainGameLogic(gameInfo, sig);
}
