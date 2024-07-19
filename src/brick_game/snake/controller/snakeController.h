#include "../snake.h"

namespace s21 {

class snakeController {
 private:
  snake snakeClass;
  GameInfo_t gameInfo;

 public:
  snakeController();
  GameInfo_t getAndUpdateGameInfo();
  void userInput(UserAction_t button, bool hold);
};

}  // namespace s21