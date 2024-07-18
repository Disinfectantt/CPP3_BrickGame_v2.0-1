#include "../snake.h"

namespace s21 {

snake::snake(GameInfo_t *GameInfo_t) : gameInfo(GameInfo_t) {
  gameInfo->field = new int* [SNAKE_FIELD_HEIGHT];
  for(int i = 0; i < SNAKE_FIELD_HEIGHT; ++i){
    gameInfo->field[i] = new int[SNAKE_FIELD_WIDTH];
  }
  snake_tail_x = new int[SNAKE_FIELD_WIDTH];
  snake_tail_y = new int[SNAKE_FIELD_HEIGHT];
  gameInfo->high_score = 0;
  std::random_device rd;
  engine = std::mt19937(rd());
  startGame();
}

snake::~snake() {
  for(int i = 0; i < SNAKE_FIELD_HEIGHT; ++i){
    delete[] gameInfo->field[i];
  }
  delete[] gameInfo->field;
  delete[] snake_tail_x;
  delete[] snake_tail_y;
}

void snake::startGame(){
  initStruct();
  randFruit();
  std::uniform_int_distribution<> distr3(3, SNAKE_FIELD_HEIGHT - 3);
  snake_head_y = distr3(engine);
  std::uniform_int_distribution<> distr4(3, SNAKE_FIELD_WIDTH - 3);
  snake_head_x = distr4(engine);
}

void snake::initStruct(){
  snake_size = SNAKE_INIT_SIZE;
  gameInfo->pause = 1;
  gameInfo->level = 1;
  gameInfo->score = 0;
  gameInfo->speed = DEFAULT_SPEED;
  std::uniform_int_distribution<> distr(3, 7);
  current_direction = (UserAction_t)distr(engine);
}

GameInfo_t snake::updateCurrentState(){
  updateSnakePos();
  checkCollision();
  generateField();
  return *gameInfo;
}

void snake::checkCollision(){
  if(snake_head_x >= SNAKE_FIELD_WIDTH || snake_head_x < 0 || snake_head_y >= SNAKE_FIELD_HEIGHT || snake_head_y < 0)
    gameInfo->level = GAME_OVER;
  for(int i = 0; i < snake_size; ++i){
    if(snake_tail_x[i] == snake_head_x && snake_tail_y[i] == snake_head_y)
      gameInfo->level = GAME_OVER;
  }
  if(snake_head_x == fruit_x && snake_head_y == fruit_y){
    ++gameInfo->score;
    if(gameInfo->high_score < gameInfo->score)
      ++gameInfo->high_score;
    ++snake_size;
    randFruit();
  }
}

void snake::randFruit(){
  std::uniform_int_distribution<> distr1(0, SNAKE_FIELD_WIDTH);
  fruit_x = distr1(engine);
  std::uniform_int_distribution<> distr2(0, SNAKE_FIELD_HEIGHT);
  fruit_y = distr2(engine);
}

void snake::updateSnakePos(){
  int preX = snake_tail_x[0], preY = snake_tail_y[0];
  int preX2, preY2;
  snake_tail_x[0] = snake_head_x;
  snake_tail_y[0] = snake_head_y;
  for(int i = 1; i < snake_size; ++i){
    preX2 = snake_tail_x[i];
    preY2 = snake_tail_y[i];
    snake_tail_x[i] = preX;
    snake_tail_y[i] = preY;
    preX = preX2;
    preY = preY2;
  }
  if(current_direction == Left)
    --snake_head_x;
  else if(current_direction == Right)
    ++snake_head_x;
  else if(current_direction == Up)
    --snake_head_y;
  else if(current_direction == Down)
    ++snake_head_y;
}

void snake::generateField(){
  for(int i = 0; i < SNAKE_FIELD_HEIGHT; ++i){
    for(int j = 0; j < SNAKE_FIELD_WIDTH; ++j){
      if(i == fruit_y && j == fruit_x){
        gameInfo->field[i][j] = FOOD;
      }else if(snake_head_x == j && snake_head_y == i){
        gameInfo->field[i][j] = SNAKE;
      }else{
        if(!addSnakeToField(i, j))
          gameInfo->field[i][j] = 0;
      }
    }
  }
}

bool snake::addSnakeToField(int i, int j){
  bool ret = false;
  for(int k = 0; k < snake_size; ++k){
    if(snake_tail_x[k] == j && snake_tail_y[k] == i){
      gameInfo->field[i][j] = SNAKE;
      ret = true;
    }
  }
  return ret;
}

void snake::userInput(UserAction_t action, bool hold){
  if(action == Start){
    gameInfo->pause = 0;
    startGame();
  }else if(action == Pause){
    switchPause();
  }else if(action == Terminate){
    exit(0);
  }else if(action == Left){
    current_direction = Left;
  }else if(action == Right){
    current_direction = Right;
  }else if(action == Up){
    current_direction = Up;
  }else if(action == Down){
    current_direction = Down;
  }else if(action == Action && hold){
    // TODO gameInfo->speed +=
  }
}

void snake::switchPause(){
  if(gameInfo->level != START_SCREEN){
    if(gameInfo->pause == 1){
      gameInfo->pause == 0;
    }else{
      gameInfo->pause == 1;
    }
  }
}

}  // namespace s21
