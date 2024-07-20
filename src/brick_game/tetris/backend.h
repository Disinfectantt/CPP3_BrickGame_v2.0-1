#ifndef TETRIS_BACKEND_H_
#define TETRIS_BACKEND_H_

#include "objects.h"

void infoInit(GameInfo_t *gameInfo);

void infoFree(GameInfo_t *gameInfo);

int spawn_block(GameInfo_t *gameInfo, block block_type, Tetramino *current);

int is_not_spawnable(GameInfo_t *gameInfo, Tetramino *current);

void tetramino_init_I(Tetramino *current);

void tetramino_init_J(Tetramino *current);

void tetramino_init_L(Tetramino *current);

void tetramino_init_O(Tetramino *current);

void tetramino_init_S(Tetramino *current);

void tetramino_init_T(Tetramino *current);

void tetramino_init_Z(Tetramino *current);

void next_init_I(GameInfo_t *board);

void next_init_J(GameInfo_t *board);
void next_init_L(GameInfo_t *board);

void next_init_O(GameInfo_t *board);

void next_init_S(GameInfo_t *board);

void next_init_T(GameInfo_t *board);

void next_init_Z(GameInfo_t *board);

int check_full_line(GameInfo_t *board);

void lines_to_score(GameInfo_t *gameInfo, int lines);

int board_update(GameInfo_t *board, Tetramino *current);

void next_update(GameInfo_t *board, block nextBlock);

#endif  // TETRIS_BACKEND_H_
