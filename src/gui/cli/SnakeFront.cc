#include "snakeFront.h"

namespace s21 {

snakeFront::snakeFront() { oldSpeed = 0; }

void snakeFront::snakeGame() {
  std::chrono::steady_clock::time_point lastUpdate;
  int interval = GameInfo.speed;
  while (true) {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                           currentTime - lastUpdate)
                           .count();
    if (elapsedTime >= interval) {
      drawField();
      lastUpdate = currentTime;
      interval = GameInfo.speed;
    }
    int ch = getch();
    isSpacePressed(ch);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}

void snakeFront::isSpacePressed(int ch) {
  static bool spacePressed = false;
  if (ch != ERR) {
    if (ch == ' ') {
      if (!spacePressed) {
        spacePressed = true;
        controller.userInput(Action, true);
      }
    } else {
      controller.userInput(btnHandling(ch), false);
    }
  } else {
    if (spacePressed) {
      spacePressed = false;
      controller.userInput(Action, false);
    }
  }
}

UserAction_t snakeFront::btnHandling(int ch) {
  UserAction_t action = Action;
  if (ch == KEY_UP) action = Up;
  if (ch == KEY_DOWN)
    action = Down;
  else if (ch == KEY_LEFT)
    action = Left;
  else if (ch == KEY_RIGHT)
    action = Right;
  else if (ch == 27)
    action = Terminate;
  else if (ch == ' ')
    action = Action;
  else if (ch == KEY_ENTER || ch == 10 || ch == 13)
    action = Pause;
  else if (ch == KEY_BACKSPACE)
    action = Start;
  return action;
}

void snakeFront::drawField() {
  GameInfo = controller.getAndUpdateGameInfo();
  clear();
  drawBorder();
  for (int y = 0; y < SNAKE_FIELD_HEIGHT; ++y) {
    for (int x = 0; x < SNAKE_FIELD_WIDTH; ++x) {
      move(y + 1, x + 1);
      if (GameInfo.field[y][x] == s21::SNAKE) {
        printw(CLI_SNAKE);
      } else if (GameInfo.field[y][x] == s21::FOOD) {
        printw(CLI_SNAKE_FOOD);
      }
    }
  }
  if (GameInfo.pause == 1 && GameInfo.level != s21::GAME_OVER) {
    print_text("PAUSE PRESS ENTER");
  }
  if (GameInfo.level == s21::GAME_OVER) {
    print_text("GAME OVER PRESS BACKSPACE");
  }
  if (GameInfo.level == s21::VICTORY) {
    print_text("YOU WON PRESS BACKSPACE");
  }
  drawStats();
  refresh();
}

void snakeFront::print_text(std::string text) {
  int y = SNAKE_FIELD_HEIGHT + 2;
  int x = 1;
  mvprintw(y, x, "%s", text.c_str());
}

void snakeFront::drawStats() {
  mvprintw(2, SNAKE_FIELD_WIDTH + 5, "Score: %d", GameInfo.score);
  mvprintw(4, SNAKE_FIELD_WIDTH + 5, "High score: %d", GameInfo.high_score);
  mvprintw(6, SNAKE_FIELD_WIDTH + 5, "Level: %d", GameInfo.level);
}

void snakeFront::drawBorder() {
  for (int y = 0; y < SNAKE_FIELD_HEIGHT + 2; ++y) {
    for (int x = 0; x < SNAKE_FIELD_WIDTH + 2; ++x) {
      move(y, x);
      if (y == 0 || y == SNAKE_FIELD_HEIGHT + 1) {
        printw("-");
      } else if (x == 0 || x == SNAKE_FIELD_WIDTH + 1) {
        printw("|");
      }
    }
  }
}
}  // namespace s21
