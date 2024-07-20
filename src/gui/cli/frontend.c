#include "frontend.h"

UserAction_t get_signal(int user_input) {
  UserAction_t rc = (UserAction_t)-1;

  if (user_input == KEY_UP) rc = Up;
  if (user_input == KEY_DOWN)
    rc = Down;
  else if (user_input == KEY_LEFT)
    rc = Left;
  else if (user_input == KEY_RIGHT)
    rc = Right;
  else if (user_input == ESCAPE)
    exit(0);
  else if (user_input == ENTER_KEY)
    rc = Action;
  else if (user_input == ' ')
    rc = Pause;

  return rc;
}

void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  for (int y = top_y; y < bottom_y + 1; y++) {
    mvprintw(y, left_x, "|");
    mvprintw(y, right_x, "|");
  }
  for (int y = top_y; y < bottom_y + 1; y++) {
    for (int x = left_x; x < right_x; x++) {
      if (x % 2 == 1) {
        mvaddch(y, x + 1, ' ');
      }
    }
  }
  for (int x = left_x; x < right_x + 1; x++) {
    mvaddch(bottom_y, x, '=');
  }
}

void print_stats(GameInfo_t *stats) {
  mvprintw(6, 29, "%d", stats->level);
  mvprintw(9, 29, "%d", stats->speed);
  mvprintw(12, 27, "%d", stats->score);
  mvprintw(15, 26, "%d", stats->high_score);
}

void print_board(GameInfo_t *board) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 20; y++) {
      if (board->field[x][y] == 1) {
        mvaddch(y + TOP_Y, x * 2 + (LEFT_X + 1), '0');
        mvaddch(y + TOP_Y, x * 2 + 1 + (LEFT_X + 1), '0');
      } else {
        mvaddch(y + TOP_Y, x * 2 + (LEFT_X + 1), ' ');
        mvaddch(y + TOP_Y, x * 2 + 1 + (LEFT_X + 1), ' ');
      }
    }
  }
}

void print_next_section(GameInfo_t *stats) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (stats->next[j][i] == 1) {
        mvprintw(NEXT_TOP_Y + j, NEXT_LEFT_X + 1 + i * 2, "00");
      } else {
        mvprintw(NEXT_TOP_Y + j, NEXT_LEFT_X + 1 + i * 2, " ");
      }
    }
  }
}

void print_text(char *text) { mvprintw(10, 4, text); }

GameInfo_t updateCurrentState() {
  GameInfo_t *gameInfo = change_GameInfo_t(NULL);
  if (gameInfo->pause == 1) {
    print_text(" GAME PAUSED ");
  } else {
    print_board(gameInfo);
    print_next_section(gameInfo);
    print_stats(gameInfo);
  }
  return *gameInfo;
}

GameInfo_t *change_GameInfo_t(GameInfo_t *gameInfo) {
  static GameInfo_t *Info;
  if (gameInfo == NULL) return Info;
  Info = gameInfo;
  return Info;
}

void print_overlay() {
  print_rectangle(TOP_Y, BOT_Y, LEFT_X, RIGHT_X);
  print_rectangle(NEXT_TOP_Y, NEXT_BOT_Y, NEXT_LEFT_X, NEXT_RIGHT_X);

  mvprintw(0, 27, "NEXT");
  mvprintw(5, 27, "LEVEL");
  mvprintw(8, 27, "SPEED");
  mvprintw(11, 27, "SCORE");
  mvprintw(14, 25, "HIGH SCORE");
}
