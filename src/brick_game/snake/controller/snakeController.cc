#include "snakeController.h"

namespace s21 {

snakeController::snakeController() : snakeClass(&gameInfo) {}

GameInfo_t snakeController::getAndUpdateGameInfo() {
  return snakeClass.updateCurrentState();
}

void snakeController::userInput(UserAction_t button, bool hold) {
  snakeClass.userInput(button, hold);
}

}  // namespace s21