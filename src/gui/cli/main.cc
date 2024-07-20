#ifdef __cplusplus
extern "C" {
#endif

#include "../../brick_game/tetris/tetris.h"
#include "frontend.h"

#ifdef __cplusplus
}
#endif

#include <chrono>
#include <iostream>
#include <thread>

#include "snakeFront.h"

void tetris_game();
int select_game();

int main() {
  int game = select_game();
  initscr();
  noecho();
  curs_set(0);
  curs_set(false);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  cbreak();
  timeout(40);
  srand((unsigned int)time(nullptr));
  if (game == 1) {
    print_overlay();
    tetris_game();
  }
  if (game == 2) {
    s21::snakeFront sf = s21::snakeFront();
    sf.snakeGame();
  }
  endwin();
  return 0;
}

void tetris_game() {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  change_GameInfo_t(&gameInfo);
  UserAction_t sig = (UserAction_t)-1;
  int state = game_loop(nullptr, sig);
  std::chrono::steady_clock::time_point lastUpdate;
  int interval = gameInfo.speed * 100;
  while (true) {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                           currentTime - lastUpdate)
                           .count();
    if (elapsedTime >= interval) {
      state = game_loop(&gameInfo, (UserAction_t)-1);
      updateCurrentState();
      lastUpdate = currentTime;
      interval = gameInfo.speed * 100;
    }
    sig = get_signal(getch());
    handle_user_input(sig);
    if (state == GAMEOVER) {
      if (sig == Action || sig == Pause) {
        infoFree(&gameInfo);
        infoInit(&gameInfo);
        state = game_loop(nullptr, (UserAction_t)-1);
      }
    }
  }
  infoFree(&gameInfo);
}

int select_game() {
  std::cout << "Select a game:\n1)Tetris\n2)Snake\n3)Any to exit\n";
  int x = -1;
  std::cin >> x;
  return x;
}
