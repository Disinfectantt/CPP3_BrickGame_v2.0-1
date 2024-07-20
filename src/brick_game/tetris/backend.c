#include "backend.h"

#include <stdio.h>

void infoInit(GameInfo_t *gameInfo) {
  gameInfo->level = 1;
  gameInfo->score = 0;
  gameInfo->speed = 1;
  gameInfo->high_score = 0;
  gameInfo->pause = 1;
  gameInfo->field = (int **)malloc(sizeof(int *) * 10);
  gameInfo->next = (int **)malloc(sizeof(int *) * 4);

  for (int i = 0; i < 10; i++) {
    gameInfo->field[i] = (int *)calloc(sizeof(int), 20);
  }
  for (int i = 0; i < 4; i++) {
    gameInfo->next[i] = (int *)calloc(sizeof(int), 4);
  }
  FILE *highScore;
  highScore = fopen("./highscore_tetris.txt", "r");
  if (highScore) {
    if (fscanf(highScore, "%d", &gameInfo->high_score) == 0) {
      gameInfo->high_score = 0;
    }
    fclose(highScore);
  }
}

void infoFree(GameInfo_t *gameInfo) {
  for (int i = 0; i < 10; i++) {
    free(gameInfo->field[i]);
  }
  for (int i = 0; i < 4; i++) {
    free(gameInfo->next[i]);
  }
  free(gameInfo->field);
  free(gameInfo->next);
}

void tetramino_init_I(Tetramino *current) {
  current->x1 = 3;
  current->y1 = 0;
  current->x2 = 4;
  current->y2 = 0;
  current->x3 = 5;
  current->y3 = 0;
  current->x4 = 6;
  current->y4 = 0;
  current->type = I;
}

void tetramino_init_J(Tetramino *current) {
  current->x1 = 4;
  current->y1 = 0;
  current->x2 = 4;
  current->y2 = 1;
  current->x3 = 5;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 1;
  current->type = J;
}
void tetramino_init_L(Tetramino *current) {
  current->x1 = 4;
  current->y1 = 1;
  current->x2 = 5;
  current->y2 = 1;
  current->x3 = 6;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 0;
  current->type = L;
}
void tetramino_init_O(Tetramino *current) {
  current->x1 = 4;
  current->y1 = 0;
  current->x2 = 5;
  current->y2 = 0;
  current->x3 = 4;
  current->y3 = 1;
  current->x4 = 5;
  current->y4 = 1;
  current->type = O;
}
void tetramino_init_S(Tetramino *current) {
  current->x1 = 5;
  current->y1 = 0;
  current->x2 = 6;
  current->y2 = 0;
  current->x3 = 4;
  current->y3 = 1;
  current->x4 = 5;
  current->y4 = 1;
  current->type = S;
}
void tetramino_init_T(Tetramino *current) {
  current->x1 = 5;
  current->y1 = 0;
  current->x2 = 4;
  current->y2 = 1;
  current->x3 = 5;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 1;
  current->type = T;
}
void tetramino_init_Z(Tetramino *current) {
  current->x1 = 4;
  current->y1 = 0;
  current->x2 = 5;
  current->y2 = 0;
  current->x3 = 5;
  current->y3 = 1;
  current->x4 = 6;
  current->y4 = 1;
  current->type = Z;
}

int board_update(GameInfo_t *board, Tetramino *current) {
  board->field[current->x1][current->y1] = 1;
  board->field[current->x2][current->y2] = 1;
  board->field[current->x3][current->y3] = 1;
  board->field[current->x4][current->y4] = 1;
  return 0;
}

void next_update(GameInfo_t *board, block nextBlock) {
  switch (nextBlock) {
    case I:
      next_init_I(board);
      break;
    case J:
      next_init_J(board);
      break;
    case L:
      next_init_L(board);
      break;
    case O:
      next_init_O(board);
      break;
    case S:
      next_init_S(board);
      break;
    case T:
      next_init_T(board);
      break;
    case Z:
      next_init_Z(board);
      break;
    default:
      break;
  }
}

void next_init_I(GameInfo_t *board) {
  board->next[1][0] = 1;
  board->next[1][1] = 1;
  board->next[1][2] = 1;
  board->next[1][3] = 1;

  board->next[2][0] = 0;
  board->next[2][1] = 0;
  board->next[2][2] = 0;
  board->next[2][3] = 0;
}
void next_init_J(GameInfo_t *board) {
  board->next[1][0] = 1;
  board->next[1][1] = 0;
  board->next[1][2] = 0;
  board->next[1][3] = 0;

  board->next[2][0] = 1;
  board->next[2][1] = 1;
  board->next[2][2] = 1;
  board->next[2][3] = 0;
}
void next_init_L(GameInfo_t *board) {
  board->next[1][0] = 0;
  board->next[1][1] = 0;
  board->next[1][2] = 1;
  board->next[1][3] = 0;

  board->next[2][0] = 1;
  board->next[2][1] = 1;
  board->next[2][2] = 1;
  board->next[2][3] = 0;
}
void next_init_O(GameInfo_t *board) {
  board->next[1][0] = 0;
  board->next[1][1] = 1;
  board->next[1][2] = 1;
  board->next[1][3] = 0;

  board->next[2][0] = 0;
  board->next[2][1] = 1;
  board->next[2][2] = 1;
  board->next[2][3] = 0;
}
void next_init_S(GameInfo_t *board) {
  board->next[1][0] = 0;
  board->next[1][1] = 1;
  board->next[1][2] = 1;
  board->next[1][3] = 0;

  board->next[2][0] = 1;
  board->next[2][1] = 1;
  board->next[2][2] = 0;
  board->next[2][3] = 0;
}
void next_init_T(GameInfo_t *board) {
  board->next[1][0] = 0;
  board->next[1][1] = 1;
  board->next[1][2] = 0;
  board->next[1][3] = 0;

  board->next[2][0] = 1;
  board->next[2][1] = 1;
  board->next[2][2] = 1;
  board->next[2][3] = 0;
}
void next_init_Z(GameInfo_t *board) {
  board->next[1][0] = 1;
  board->next[1][1] = 1;
  board->next[1][2] = 0;
  board->next[1][3] = 0;

  board->next[2][0] = 0;
  board->next[2][1] = 1;
  board->next[2][2] = 1;
  board->next[2][3] = 0;
}

int spawn_block(GameInfo_t *gameInfo, block block_type, Tetramino *current) {
  int error = 0;
  switch (block_type) {
    case I:
      tetramino_init_I(current);
      break;
    case J:
      tetramino_init_J(current);
      break;
    case L:
      tetramino_init_L(current);
      break;
    case O:
      tetramino_init_O(current);
      break;
    case S:
      tetramino_init_S(current);
      break;
    case T:
      tetramino_init_T(current);
      break;
    case Z:
      tetramino_init_Z(current);
      break;
    default:
      break;
  }
  current->rotate_state = 0;
  error = is_not_spawnable(gameInfo, current);
  return error;
}

int is_not_spawnable(GameInfo_t *gameInfo, Tetramino *current) {
  if (gameInfo->field[current->x1][current->y1] == 0 &&
      gameInfo->field[current->x2][current->y2] == 0 &&
      gameInfo->field[current->x3][current->y3] == 0 &&
      gameInfo->field[current->x4][current->y4] == 0) {
    return 0;
  }
  return 1;
}

void lines_to_score(GameInfo_t *gameInfo, int lines) {
  if (lines == 1) {
    gameInfo->score += 100;
  }
  if (lines == 2) {
    gameInfo->score += 300;
  }
  if (lines == 3) {
    gameInfo->score += 700;
  }
  if (lines >= 4) {
    gameInfo->score += 1500;
  }
  if (gameInfo->score > gameInfo->high_score) {
    gameInfo->high_score = gameInfo->score;
    FILE *highScore;
    highScore = fopen("./highscore_tetris.txt", "w");
    if (highScore) {
      fprintf(highScore, "%d", gameInfo->high_score);
      fclose(highScore);
    }
  }
  if (gameInfo->score / 600 > 9) {
    gameInfo->level = 10;
  } else {
    gameInfo->level = gameInfo->score / 600 + 1;
  }
  gameInfo->speed = gameInfo->level;
}

int check_full_line(GameInfo_t *board) {
  int lines = 0;
  for (int y = 0; y < 20; y++) {
    int isFull = 1;
    for (int x = 0; x < 10; x++) {
      if (board->field[x][y] == 0) {
        isFull = 0;
      }
    }
    if (isFull) {
      lines++;
      for (int y1 = y; y1 > 0; y1--) {
        for (int x1 = 0; x1 < 10; x1++) {
          board->field[x1][y1] = board->field[x1][y1 - 1];
        }
      }
      for (int x1 = 0; x1 < 10; x1++) {
        board->field[x1][0] = 0;
      }
    }
  }
  return lines;
}
