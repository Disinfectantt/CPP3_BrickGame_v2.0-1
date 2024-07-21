#include "s21_tetris_test.h"

START_TEST(tetris_base_test1) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Right);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test2) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Left);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test3) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test4) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test5) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(tetris_base_test6) {
  FILE *test_score = fopen("highscore_tetris.txt", "w");
  fclose(test_score);
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  game_loop(NULL, -1);

  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Down);
  game_loop(&gameInfo, Right);
  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Up);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);
  game_loop(&gameInfo, Action);

  game_loop(&gameInfo, Left);
  game_loop(&gameInfo, Right);
  gameInfo.field[0][18] = 1;
  gameInfo.field[1][18] = 1;
  gameInfo.field[2][18] = 1;
  gameInfo.field[3][18] = 1;
  gameInfo.field[4][18] = 1;

  gameInfo.field[5][18] = 1;
  gameInfo.field[6][18] = 1;
  gameInfo.field[7][18] = 1;
  gameInfo.field[8][18] = 1;
  gameInfo.field[9][18] = 1;
  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Down);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Action);
    game_loop(&gameInfo, Right);
  }

  for (size_t i = 0; i < 30000; i++) {
    game_loop(&gameInfo, Down);
    game_loop(&gameInfo, Down);
  }

  game_loop(&gameInfo, Pause);
  game_loop(&gameInfo, Terminate);

  infoFree(&gameInfo);
}
END_TEST

Suite *suite_tetris_base(void) {
  Suite *s = suite_create("suite_tetris_base");
  TCase *tc = tcase_create("tetris_base_tc");

  tcase_add_test(tc, tetris_base_test1);
  tcase_add_test(tc, tetris_base_test2);
  tcase_add_test(tc, tetris_base_test3);
  tcase_add_test(tc, tetris_base_test4);
  tcase_add_test(tc, tetris_base_test5);
  tcase_add_test(tc, tetris_base_test6);

  suite_add_tcase(s, tc);
  return s;
}
