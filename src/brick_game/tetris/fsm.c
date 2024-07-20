#include "fsm.h"

void clear_backpos(Tetramino *current, GameInfo_t *gameInfo) {
  gameInfo->field[current->x1][current->y1] = 0;
  gameInfo->field[current->x2][current->y2] = 0;
  gameInfo->field[current->x3][current->y3] = 0;
  gameInfo->field[current->x4][current->y4] = 0;
}

int movedown(Tetramino *current, GameInfo_t *gameInfo) {
  clear_backpos(current, gameInfo);
  if (current->y1 < 19 && current->y2 < 19 && current->y3 < 19 &&
      current->y4 < 19) {
    if (gameInfo->field[current->x1][current->y1 + 1] == 0 &&
        gameInfo->field[current->x2][current->y2 + 1] == 0 &&
        gameInfo->field[current->x3][current->y3 + 1] == 0 &&
        gameInfo->field[current->x4][current->y4 + 1] == 0) {
      current->y1 += 1;
      current->y2 += 1;
      current->y3 += 1;
      current->y4 += 1;
    } else {
      return 1;
    }
  } else {
    return 1;
  }
  return 0;
}

void moveright(Tetramino *current, GameInfo_t *gameInfo) {
  clear_backpos(current, gameInfo);
  if (current->x1 < 9 && current->x2 < 9 && current->x3 < 9 &&
      current->x4 < 9) {
    if (gameInfo->field[current->x1 + 1][current->y1] == 0 &&
        gameInfo->field[current->x2 + 1][current->y2] == 0 &&
        gameInfo->field[current->x3 + 1][current->y3] == 0 &&
        gameInfo->field[current->x4 + 1][current->y4] == 0) {
      current->x1 += 1;
      current->x2 += 1;
      current->x3 += 1;
      current->x4 += 1;
    }
  }
}

void moveleft(Tetramino *current, GameInfo_t *gameInfo) {
  clear_backpos(current, gameInfo);
  if (current->x1 > 0 && current->x2 > 0 && current->x3 > 0 &&
      current->x4 > 0) {
    if (gameInfo->field[current->x1 - 1][current->y1] == 0 &&
        gameInfo->field[current->x2 - 1][current->y2] == 0 &&
        gameInfo->field[current->x3 - 1][current->y3] == 0 &&
        gameInfo->field[current->x4 - 1][current->y4] == 0) {
      current->x1 -= 1;
      current->x2 -= 1;
      current->x3 -= 1;
      current->x4 -= 1;
    }
  }
}

void rotate_I(Tetramino *current, GameInfo_t *gameInfo) {
  clear_backpos(current, gameInfo);
  if (current->rotate_state == 0) {
    if (current->y1 > 1 && current->y2 > 1 && current->y3 > 1 &&
        current->y4 > 1 && current->y1 < 19 && current->y2 < 19 &&
        current->y3 < 19 && current->y4 < 19) {
      if (gameInfo->field[current->x1 + 2][current->y1 - 2] == 0 &&
          gameInfo->field[current->x2 + 1][current->y2 - 1] == 0 &&
          gameInfo->field[current->x3][current->y3] == 0 &&
          gameInfo->field[current->x4 - 1][current->y4 + 1] == 0) {
        current->x1 += 2;
        current->y1 -= 2;
        current->x2 += 1;
        current->y2 -= 1;
        current->x4 -= 1;
        current->y4 += 1;
        current->rotate_state = 1;
      }
    }
  } else {
    if (current->x1 > 1 && current->x2 > 1 && current->x3 > 1 &&
        current->x4 > 1 && current->x1 < 9 && current->x2 < 9 &&
        current->x3 < 9 && current->x4 < 9) {
      if (gameInfo->field[current->x1 - 2][current->y1 + 2] == 0 &&
          gameInfo->field[current->x2 - 1][current->y2 + 1] == 0 &&
          gameInfo->field[current->x3][current->y3] == 0 &&
          gameInfo->field[current->x4 + 1][current->y4 - 1] == 0) {
        current->x1 -= 2;
        current->y1 += 2;
        current->x2 -= 1;
        current->y2 += 1;
        current->x4 += 1;
        current->y4 -= 1;
        current->rotate_state = 0;
      }
    }
  }
}

int rotate_J_first(Tetramino *current, GameInfo_t *gameInfo) {
  int is_changed = 0;
  clear_backpos(current, gameInfo);
  if (current->rotate_state == 0) {
    if (current->y2 < 19) {
      if (gameInfo->field[current->x1 + 2][current->y1] == 0 &&
          gameInfo->field[current->x2 + 1][current->y2 - 1] == 0 &&
          gameInfo->field[current->x4 - 1][current->y4 + 1] == 0) {
        current->x1 += 2;
        current->x2 += 1;
        current->y2 -= 1;
        current->x4 -= 1;
        current->y4 += 1;
        current->rotate_state = 1;
      }
    }
  } else if (current->rotate_state == 1) {
    if (current->x2 > 0) {
      if (gameInfo->field[current->x1][current->y1 + 2] == 0 &&
          gameInfo->field[current->x2 + 1][current->y2 + 1] == 0 &&
          gameInfo->field[current->x4 - 1][current->y4 - 1] == 0) {
        current->y1 += 2;
        current->x2 += 1;
        current->y2 += 1;
        current->x4 -= 1;
        current->y4 -= 1;
        current->rotate_state = 2;
        is_changed = 1;
      }
    }
  }
  return is_changed;
}
void rotate_J_second(Tetramino *current, GameInfo_t *gameInfo) {
  if (current->rotate_state == 2) {
    if (current->y2 > 0) {
      if (gameInfo->field[current->x1 - 2][current->y1] == 0 &&
          gameInfo->field[current->x2 - 1][current->y2 + 1] == 0 &&
          gameInfo->field[current->x4 + 1][current->y4 - 1] == 0) {
        current->x1 -= 2;
        current->x2 -= 1;
        current->y2 += 1;
        current->x4 += 1;
        current->y4 -= 1;
        current->rotate_state = 3;
      }
    }
  } else if (current->rotate_state == 3) {
    if (current->x2 < 9) {
      if (gameInfo->field[current->x1][current->y1 - 2] == 0 &&
          gameInfo->field[current->x2 - 1][current->y2 - 1] == 0 &&
          gameInfo->field[current->x4 + 1][current->y4 + 1] == 0) {
        current->y1 -= 2;
        current->x2 -= 1;
        current->y2 -= 1;
        current->x4 += 1;
        current->y4 += 1;
        current->rotate_state = 0;
      }
    }
  }
}

void rotate_J(Tetramino *current, GameInfo_t *gameInfo) {
  if (!rotate_J_first(current, gameInfo)) {
    rotate_J_second(current, gameInfo);
  }
}

int rotate_L_first(Tetramino *current, GameInfo_t *gameInfo) {
  int is_changed = 0;
  clear_backpos(current, gameInfo);
  if (current->rotate_state == 0) {
    if (current->y2 < 19) {
      if (gameInfo->field[current->x1 + 1][current->y1 - 1] == 0 &&
          gameInfo->field[current->x3 - 1][current->y3 + 1] == 0 &&
          gameInfo->field[current->x4][current->y4 + 2] == 0) {
        current->x1 += 1;
        current->y1 -= 1;
        current->x3 -= 1;
        current->y3 += 1;
        current->y4 += 2;
        current->rotate_state = 1;
      }
    }
  } else if (current->rotate_state == 1) {
    if (current->x2 > 0) {
      if (gameInfo->field[current->x1 + 1][current->y1 + 1] == 0 &&
          gameInfo->field[current->x3 - 1][current->y3 - 1] == 0 &&
          gameInfo->field[current->x4 - 2][current->y4] == 0) {
        current->x1 += 1;
        current->y1 += 1;
        current->x3 -= 1;
        current->y3 -= 1;
        current->x4 -= 2;
        current->rotate_state = 2;
        is_changed = 1;
      }
    }
  }
  return is_changed;
}
void rotate_L_second(Tetramino *current, GameInfo_t *gameInfo) {
  if (current->rotate_state == 2) {
    if (current->y2 > 0) {
      if (gameInfo->field[current->x1 - 1][current->y1 + 1] == 0 &&
          gameInfo->field[current->x3 + 1][current->y3 - 1] == 0 &&
          gameInfo->field[current->x4][current->y4 - 2] == 0) {
        current->x1 -= 1;
        current->y2 += 1;
        current->x3 += 1;
        current->y3 -= 1;
        current->y4 -= 2;
        current->rotate_state = 3;
      }
    }
  } else if (current->rotate_state == 3) {
    if (current->x2 < 9) {
      if (gameInfo->field[current->x1 - 1][current->y1 - 1] == 0 &&
          gameInfo->field[current->x3 + 1][current->y3 + 1] == 0 &&
          gameInfo->field[current->x4 + 2][current->y4] == 0) {
        current->x1 -= 1;
        current->y2 -= 1;
        current->x3 += 1;
        current->y3 += 1;
        current->x4 += 2;
        current->rotate_state = 0;
      }
    }
  }
}

void rotate_L(Tetramino *current, GameInfo_t *gameInfo) {
  if (!rotate_L_first(current, gameInfo)) {
    rotate_L_second(current, gameInfo);
  }
}
void rotate_S(Tetramino *current, GameInfo_t *gameInfo) {
  clear_backpos(current, gameInfo);
  if (current->rotate_state == 0) {
    if (current->y1 > 0) {
      if (gameInfo->field[current->x1 + 1][current->y1] == 0 &&
          gameInfo->field[current->x2][current->y2 + 1] == 0 &&
          gameInfo->field[current->x3 + 1][current->y3 - 2] == 0 &&
          gameInfo->field[current->x4][current->y4 - 1] == 0) {
        current->x1 += 1;
        current->y2 += 1;
        current->x3 += 1;
        current->y3 -= 2;
        current->y4 -= 1;
        current->rotate_state = 1;
      }
    }
  } else if (current->rotate_state == 1) {
    if (current->x3 > 0) {
      if (gameInfo->field[current->x1 - 1][current->y1] == 0 &&
          gameInfo->field[current->x2][current->y2 - 1] == 0 &&
          gameInfo->field[current->x3 - 1][current->y3 + 2] == 0 &&
          gameInfo->field[current->x4][current->y4 + 1] == 0) {
        current->x1 -= 1;
        current->y2 -= 1;
        current->x3 -= 1;
        current->y3 += 2;
        current->y4 += 1;
        current->rotate_state = 0;
      }
    }
  }
}

int rotate_T_first(Tetramino *current, GameInfo_t *gameInfo) {
  int is_changed = 0;
  clear_backpos(current, gameInfo);
  if (current->rotate_state == 0) {
    if (current->y2 < 19) {
      if (gameInfo->field[current->x1 + 1][current->y1 + 1] == 0 &&
          gameInfo->field[current->x2 + 1][current->y2 - 1] == 0 &&
          gameInfo->field[current->x4 - 1][current->y4 + 1] == 0) {
        current->x1 += 1;
        current->y1 += 1;
        current->x2 += 1;
        current->y2 -= 1;
        current->x4 -= 1;
        current->y4 += 1;
        current->rotate_state = 1;
      }
    }
  } else if (current->rotate_state == 1) {
    if (current->x2 > 0) {
      if (gameInfo->field[current->x1 - 1][current->y1 + 1] == 0 &&
          gameInfo->field[current->x2 + 1][current->y2 + 1] == 0 &&
          gameInfo->field[current->x4 - 1][current->y4 - 1] == 0) {
        current->x1 -= 1;
        current->y1 += 1;
        current->x2 += 1;
        current->y2 += 1;
        current->x4 -= 1;
        current->y4 -= 1;
        current->rotate_state = 2;
        is_changed = 1;
      }
    }
  }
  return is_changed;
}

void rotate_T_second(Tetramino *current, GameInfo_t *gameInfo) {
  if (current->rotate_state == 2) {
    if (current->y2 > 0) {
      if (gameInfo->field[current->x1 - 1][current->y1 - 1] == 0 &&
          gameInfo->field[current->x2 - 1][current->y2 + 1] == 0 &&
          gameInfo->field[current->x4 + 1][current->y4 - 1] == 0) {
        current->x1 -= 1;
        current->y1 -= 1;
        current->x2 -= 1;
        current->y2 += 1;
        current->x4 += 1;
        current->y4 -= 1;
        current->rotate_state = 3;
      }
    }
  } else if (current->rotate_state == 3) {
    if (current->x2 < 9) {
      if (gameInfo->field[current->x1 + 1][current->y1 - 1] == 0 &&
          gameInfo->field[current->x2 - 1][current->y2 - 1] == 0 &&
          gameInfo->field[current->x4 + 1][current->y4 + 1] == 0) {
        current->x1 += 1;
        current->y1 -= 1;
        current->x2 -= 1;
        current->y2 -= 1;
        current->x4 += 1;
        current->y4 += 1;
        current->rotate_state = 0;
      }
    }
  }
}

void rotate_T(Tetramino *current, GameInfo_t *gameInfo) {
  if (!rotate_T_first(current, gameInfo)) {
    rotate_T_second(current, gameInfo);
  }
}
void rotate_Z(Tetramino *current, GameInfo_t *gameInfo) {
  clear_backpos(current, gameInfo);
  if (current->rotate_state == 0) {
    if (current->y1 > 0) {
      if (gameInfo->field[current->x1 + 2][current->y1 - 1] == 0 &&
          gameInfo->field[current->x2 + 1][current->y2] == 0 &&
          gameInfo->field[current->x3][current->y3 - 1] == 0 &&
          gameInfo->field[current->x4 - 1][current->y4] == 0) {
        current->x1 += 2;
        current->y1 -= 1;
        current->x2 += 1;
        current->y3 -= 1;
        current->x4 -= 1;
        current->rotate_state = 1;
      }
    }
  } else if (current->rotate_state == 1) {
    if (current->x3 > 0) {
      if (gameInfo->field[current->x1 - 2][current->y1 + 1] == 0 &&
          gameInfo->field[current->x2 - 1][current->y2] == 0 &&
          gameInfo->field[current->x3][current->y3 + 1] == 0 &&
          gameInfo->field[current->x4 + 1][current->y4] == 0) {
        current->x1 -= 2;
        current->y1 += 1;
        current->x2 -= 1;
        current->y3 += 1;
        current->x4 += 1;
        current->rotate_state = 0;
      }
    }
  }
}

int rotate(Tetramino *current, GameInfo_t *gameInfo) {
  if (current->type == I) {
    rotate_I(current, gameInfo);
  } else if (current->type == J) {
    rotate_J(current, gameInfo);
  } else if (current->type == L) {
    rotate_L(current, gameInfo);
  } else if (current->type == S) {
    rotate_S(current, gameInfo);
  } else if (current->type == T) {
    rotate_T(current, gameInfo);
  } else if (current->type == Z) {
    rotate_Z(current, gameInfo);
  }
  return 0;
}

void movedown_clock_check(GameInfo_t *gameInfo, Tetramino *current,
                          tetris_state *state) {
  if (movedown(current, gameInfo)) {
    *state = SPAWN;
    board_update(gameInfo, current);
    int lines = check_full_line(gameInfo);
    lines_to_score(gameInfo, lines);
  } else
    board_update(gameInfo, current);
}

void spawn_state(GameInfo_t *gameInfo, Tetramino *current, block *nextBlock,
                 tetris_state *state) {
  if (spawn_block(gameInfo, *nextBlock, current)) {
    *state = GAMEOVER;
  } else {
    *nextBlock = rand() % 7;
    next_update(gameInfo, *nextBlock);
    board_update(gameInfo, current);
    *state = MOVING;
  }
}

void move_state(UserAction_t *sig, GameInfo_t *gameInfo, Tetramino *current,
                tetris_state *state) {
  switch (*sig) {
    case Down:
      movedown(current, gameInfo);
      board_update(gameInfo, current);
      break;
    case Right:
      moveright(current, gameInfo);
      board_update(gameInfo, current);
      break;
    case Left:
      moveleft(current, gameInfo);
      board_update(gameInfo, current);
      break;
    case Action:
      rotate(current, gameInfo);
      board_update(gameInfo, current);
      break;
    case Terminate:
      *state = EXIT_STATE;
      break;
    case Pause:
      gameInfo->pause = 1;
      *state = PAUSE;
    default:
      break;
  }
  if (*state != EXIT_STATE && *state != PAUSE) {
    *state = SHIFTING;
  }
}

void pause_state(UserAction_t *sig, GameInfo_t *gameInfo, tetris_state *state) {
  switch (*sig) {
    case Pause:
      gameInfo->pause = 0;
      *state = MOVING;
      break;
    case Terminate:
      *state = EXIT_STATE;
      break;
    default:
      break;
  }
}

GameInfo_t *get_gameInfo(GameInfo_t *gameInfo) {
  static GameInfo_t *Info;
  if (gameInfo == NULL) return Info;
  Info = gameInfo;
  return Info;
}
tetris_state *get_state(tetris_state *state) {
  static tetris_state *State;
  if (state == NULL) return State;
  State = state;
  return State;
}
Tetramino *get_current(Tetramino *current) {
  static Tetramino *Current;
  if (current == NULL) return Current;
  Current = current;
  return Current;
}
block *get_nextBlock(block *nextBlock) {
  static block *NextBlock;
  if (nextBlock == NULL) return NextBlock;
  NextBlock = nextBlock;
  return NextBlock;
}
bool *get_fallTime(bool *fallTime) {
  static bool *FallTime;
  if (fallTime == NULL) return FallTime;
  FallTime = fallTime;
  return FallTime;
}

void userInput(UserAction_t action, bool hold) {
  GameInfo_t *gameInfo = get_gameInfo(NULL);
  tetris_state *state = get_state(NULL);
  Tetramino *current = get_current(NULL);
  block *nextBlock = get_nextBlock(NULL);
  bool *fallTime = get_fallTime(NULL);
  if (hold) {
    // sigact(&action, fallTime, state, gameInfo, current, nextBlock);
  }

  get_gameInfo(gameInfo);
  get_state(state);
  get_current(current);
  get_nextBlock(nextBlock);
}

void sigact(UserAction_t *sig, const bool *fallTime, tetris_state *state,
            GameInfo_t *gameInfo, Tetramino *current) {
  if (*fallTime && *state != START && *state != GAMEOVER && *state != SPAWN &&
      *state != PAUSE) {
    movedown_clock_check(gameInfo, current, state);
  }
  switch (*state) {
    case START:
      switch (*sig) {
        case Action:
          *state = SPAWN;
          break;
        case Terminate:
          exit(0);
        default:
          break;
      }
      break;
    case MOVING:
      move_state(sig, gameInfo, current, state);
      break;
    case SHIFTING:
      if (*state != SPAWN) {
        *state = MOVING;
      }
      break;
    case PAUSE:
      pause_state(sig, gameInfo, state);
      break;
    case GAMEOVER:
      switch (*sig) {
        case Action:
          *state = SPAWN;
          break;
        default:
          break;
      }
    default:
      break;
  }
}
