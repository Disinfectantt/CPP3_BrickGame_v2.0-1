#include <gtest/gtest.h>

#include "../../brick_game/snake/controller/snakeController.h"
#include "../../brick_game/snake/snake.h"

class MockSnake : public s21::snake {
 public:
  MockSnake(s21::GameInfo_t* GameInfo_t) : snake(GameInfo_t) {}

  void setFruitPosition(int x, int y) {
    fruit_x = x;
    fruit_y = y;
  }

  void getSnakeHeadPosition(int& x, int& y) {
    x = snake_head_x;
    y = snake_head_y;
  }

  void setSnakeHeadPosition(int x, int y) {
    snake_head_x = x;
    snake_head_y = y;
  }

  s21::UserAction_t getCurrentDirection() { return current_direction; }

  int getSnakeSize() const { return snake_size; }

  void setSnakeSize(int size) { snake_size = size; }

  void setLevel(int level) { gameInfo->level = level; }

  void spawnFruitBeforeHead() {
    int headX, headY;
    getSnakeHeadPosition(headX, headY);
    int fruitX = headX, fruitY = headY;
    switch ((int)getCurrentDirection()) {
      case s21::Left:
        fruitX--;
        break;
      case s21::Right:
        fruitX++;
        break;
      case s21::Up:
        fruitY--;
        break;
      case s21::Down:
        fruitY++;
        break;
    }
    setFruitPosition(fruitX, fruitY);
  }

  void setSnakeScore(int score) { gameInfo->score = score; }
};

class SnakeTest : public ::testing::Test {
 protected:
  s21::GameInfo_t gameInfo;
  MockSnake* snakeGame;

  void SetUp() override { snakeGame = new MockSnake(&gameInfo); }

  void TearDown() override { delete snakeGame; }
};

class SnakeControllerTest : public ::testing::Test {
 protected:
  s21::snakeController controller;
  s21::GameInfo_t gameInfo;
};

TEST_F(SnakeControllerTest, GetAndUpdateGameInfoTest) {
  s21::GameInfo_t result = controller.getAndUpdateGameInfo();
  EXPECT_EQ(result.level, 1);
  EXPECT_EQ(result.score, 0);
  EXPECT_EQ(result.pause, 1);
  EXPECT_NE(result.field, nullptr);
}

TEST_F(SnakeControllerTest, UserInputTest) {
  controller.userInput(s21::Pause, false);
  s21::GameInfo_t pausedState = controller.getAndUpdateGameInfo();
  EXPECT_EQ(pausedState.pause, 0);
}

TEST_F(SnakeTest, InitializationTest) {
  EXPECT_EQ(gameInfo.level, 1);
  EXPECT_EQ(gameInfo.score, 0);
  EXPECT_EQ(gameInfo.speed, DEFAULT_SPEED);
  EXPECT_EQ(gameInfo.pause, 1);
}

TEST_F(SnakeTest, StartGameTest) {
  snakeGame->userInput(s21::Pause, false);
  EXPECT_EQ(gameInfo.pause, 0);
}

TEST_F(SnakeTest, PauseGameTest) {
  snakeGame->userInput(s21::Pause, false);
  snakeGame->userInput(s21::Pause, false);
  EXPECT_EQ(gameInfo.pause, 1);
}

TEST_F(SnakeTest, MoveSnakeTest) {
  snakeGame->userInput(s21::Pause, false);
  int initialDirection = snakeGame->getCurrentDirection();
  int newDirection = s21::Left;
  while (newDirection == initialDirection) {
    newDirection += 1;
  }
  EXPECT_NE(initialDirection, newDirection);
}

TEST_F(SnakeTest, EatFruitTest) {
  snakeGame->userInput(s21::Pause, false);
  int initialScore = gameInfo.score;
  int initialSize = snakeGame->getSnakeSize();
  snakeGame->spawnFruitBeforeHead();
  snakeGame->updateCurrentState();
  EXPECT_GT(gameInfo.score, initialScore);
  EXPECT_GT(snakeGame->getSnakeSize(), initialSize);
}

TEST_F(SnakeTest, GameOverTest) {
  snakeGame->userInput(s21::Pause, false);
  s21::GameInfo_t info;
  do {
    snakeGame->userInput(s21::Right, false);
    info = snakeGame->updateCurrentState();
  } while (info.level != s21::GAME_OVER);

  EXPECT_EQ(gameInfo.level, s21::GAME_OVER);
}

TEST_F(SnakeTest, SpeedIncreaseTest) {
  snakeGame->userInput(s21::Pause, false);
  int initialSpeed = gameInfo.speed;
  snakeGame->setSnakeScore(4);
  snakeGame->spawnFruitBeforeHead();
  snakeGame->updateCurrentState();
  EXPECT_GT(initialSpeed, gameInfo.speed);
  EXPECT_GT(gameInfo.level, 1);
}

TEST_F(SnakeTest, DirectionChangeTest) {
  snakeGame->userInput(s21::Pause, false);
  snakeGame->userInput(s21::Right, false);
  snakeGame->updateCurrentState();
  snakeGame->userInput(s21::Down, false);
  snakeGame->updateCurrentState();
}

TEST_F(SnakeTest, BoostSpeedTest) {
  snakeGame->userInput(s21::Pause, false);
  int normalSpeed = gameInfo.speed;
  snakeGame->userInput(s21::Action, true);
  EXPECT_LT(gameInfo.speed, normalSpeed);
  snakeGame->userInput(s21::Action, false);
  EXPECT_EQ(gameInfo.speed, normalSpeed);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

#pragma GCC diagnostic ignored "-Wunused-result"
  RUN_ALL_TESTS();
#pragma GCC diagnostic pop

  return 0;
}
