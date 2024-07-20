#ifndef TETRIS_H_
#define TETRIS_H_

#include "backend.h"
#include "fsm.h"

tetris_state game_loop(GameInfo_t *gameInfo, UserAction_t sig);
void handle_user_input(UserAction_t sig);

#endif  // TETRIS_H_
