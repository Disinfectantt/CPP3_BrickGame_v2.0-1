#include "s21_tetris_test.h"

START_TEST(test_info_init) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);

  ck_assert_int_eq(gameInfo.level, 1);
  ck_assert_int_eq(gameInfo.score, 0);
  ck_assert_int_eq(gameInfo.speed, 1);
  ck_assert_int_eq(gameInfo.pause, 1);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 20; j++) {
      ck_assert_int_eq(gameInfo.field[i][j], 0);
    }
  }

  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_tetramino_I) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, I, &current);

  ck_assert_int_eq(current.x1, 3);
  ck_assert_int_eq(current.y1, 0);
  ck_assert_int_eq(current.x2, 4);
  ck_assert_int_eq(current.y2, 0);
  ck_assert_int_eq(current.x3, 5);
  ck_assert_int_eq(current.y3, 0);
  ck_assert_int_eq(current.x4, 6);
  ck_assert_int_eq(current.y4, 0);
  ck_assert_int_eq(current.type, I);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_move_down) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current;
  tetramino_init_I(&current);

  int result = movedown(&current, &gameInfo);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(current.y1, 1);
  ck_assert_int_eq(current.y2, 1);
  ck_assert_int_eq(current.y3, 1);
  ck_assert_int_eq(current.y4, 1);

  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_check_full_line) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  for (int i = 0; i < 10; i++) {
    gameInfo.field[i][19] = 1;
  }
  int lines = check_full_line(&gameInfo);
  ck_assert_int_eq(lines, 1);
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(gameInfo.field[i][19], 0);
  }

  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_tetramino_init_J) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, J, &current);

  ck_assert_int_eq(current.x1, 4);
  ck_assert_int_eq(current.y1, 0);
  ck_assert_int_eq(current.x2, 4);
  ck_assert_int_eq(current.y2, 1);
  ck_assert_int_eq(current.x3, 5);
  ck_assert_int_eq(current.y3, 1);
  ck_assert_int_eq(current.x4, 6);
  ck_assert_int_eq(current.y4, 1);
  ck_assert_int_eq(current.type, J);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_tetramino_init_L) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, L, &current);

  ck_assert_int_eq(current.x1, 4);
  ck_assert_int_eq(current.y1, 1);
  ck_assert_int_eq(current.x2, 5);
  ck_assert_int_eq(current.y2, 1);
  ck_assert_int_eq(current.x3, 6);
  ck_assert_int_eq(current.y3, 1);
  ck_assert_int_eq(current.x4, 6);
  ck_assert_int_eq(current.y4, 0);
  ck_assert_int_eq(current.type, L);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_tetramino_init_O) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, O, &current);

  ck_assert_int_eq(current.x1, 4);
  ck_assert_int_eq(current.y1, 0);
  ck_assert_int_eq(current.x2, 5);
  ck_assert_int_eq(current.y2, 0);
  ck_assert_int_eq(current.x3, 4);
  ck_assert_int_eq(current.y3, 1);
  ck_assert_int_eq(current.x4, 5);
  ck_assert_int_eq(current.y4, 1);
  ck_assert_int_eq(current.type, O);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_tetramino_init_S) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, S, &current);

  ck_assert_int_eq(current.x1, 5);
  ck_assert_int_eq(current.y1, 0);
  ck_assert_int_eq(current.x2, 6);
  ck_assert_int_eq(current.y2, 0);
  ck_assert_int_eq(current.x3, 4);
  ck_assert_int_eq(current.y3, 1);
  ck_assert_int_eq(current.x4, 5);
  ck_assert_int_eq(current.y4, 1);
  ck_assert_int_eq(current.type, S);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_tetramino_init_T) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, T, &current);

  ck_assert_int_eq(current.x1, 5);
  ck_assert_int_eq(current.y1, 0);
  ck_assert_int_eq(current.x2, 4);
  ck_assert_int_eq(current.y2, 1);
  ck_assert_int_eq(current.x3, 5);
  ck_assert_int_eq(current.y3, 1);
  ck_assert_int_eq(current.x4, 6);
  ck_assert_int_eq(current.y4, 1);
  ck_assert_int_eq(current.type, T);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_tetramino_init_Z) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, Z, &current);

  ck_assert_int_eq(current.x1, 4);
  ck_assert_int_eq(current.y1, 0);
  ck_assert_int_eq(current.x2, 5);
  ck_assert_int_eq(current.y2, 0);
  ck_assert_int_eq(current.x3, 5);
  ck_assert_int_eq(current.y3, 1);
  ck_assert_int_eq(current.x4, 6);
  ck_assert_int_eq(current.y4, 1);
  ck_assert_int_eq(current.type, Z);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_next_init_I) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  next_update(&gameInfo, I);

  ck_assert_int_eq(gameInfo.next[1][0], 1);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 1);
  ck_assert_int_eq(gameInfo.next[2][0], 0);
  ck_assert_int_eq(gameInfo.next[2][1], 0);
  ck_assert_int_eq(gameInfo.next[2][2], 0);
  ck_assert_int_eq(gameInfo.next[2][3], 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_next_init_J) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  next_update(&gameInfo, J);
  ck_assert_int_eq(gameInfo.next[1][0], 1);
  ck_assert_int_eq(gameInfo.next[1][1], 0);
  ck_assert_int_eq(gameInfo.next[1][2], 0);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_next_init_L) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  next_update(&gameInfo, L);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 0);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_next_init_O) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  next_update(&gameInfo, O);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 0);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_next_init_S) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  next_update(&gameInfo, S);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 1);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 0);
  ck_assert_int_eq(gameInfo.next[2][3], 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_next_init_T) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  next_update(&gameInfo, T);
  ck_assert_int_eq(gameInfo.next[1][0], 0);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 0);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 1);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_next_init_Z) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  next_update(&gameInfo, Z);
  ck_assert_int_eq(gameInfo.next[1][0], 1);
  ck_assert_int_eq(gameInfo.next[1][1], 1);
  ck_assert_int_eq(gameInfo.next[1][2], 0);
  ck_assert_int_eq(gameInfo.next[1][3], 0);
  ck_assert_int_eq(gameInfo.next[2][0], 0);
  ck_assert_int_eq(gameInfo.next[2][1], 1);
  ck_assert_int_eq(gameInfo.next[2][2], 1);
  ck_assert_int_eq(gameInfo.next[2][3], 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_board_update) {
  Tetramino current;
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  spawn_block(&gameInfo, J, &current);
  gameInfo.field[current.x1][current.y1] = 1;
  gameInfo.field[current.x2][current.y2] = 1;
  gameInfo.field[current.x3][current.y3] = 1;
  gameInfo.field[current.x4][current.y4] = 1;
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_lines_to_score) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  gameInfo.score = 0;
  lines_to_score(&gameInfo, 1);
  ck_assert_int_eq(gameInfo.score, 100);
  ck_assert_int_eq(gameInfo.level, 1);
  gameInfo.score = 0;
  lines_to_score(&gameInfo, 2);
  ck_assert_int_eq(gameInfo.score, 300);
  ck_assert_int_eq(gameInfo.level, 1);
  gameInfo.score = 0;
  lines_to_score(&gameInfo, 3);
  ck_assert_int_eq(gameInfo.score, 700);
  ck_assert_int_eq(gameInfo.level, 2);
  gameInfo.score = 0;
  lines_to_score(&gameInfo, 4);
  ck_assert_int_eq(gameInfo.score, 1500);
  ck_assert_int_eq(gameInfo.level, 3);
  gameInfo.score = 5999;
  lines_to_score(&gameInfo, 1);
  ck_assert_int_eq(gameInfo.score, 6099);
  ck_assert_int_eq(gameInfo.level, 10);
  ck_assert_int_eq(gameInfo.speed, 10);
  gameInfo.high_score = 5000;
  gameInfo.score = 4999;
  lines_to_score(&gameInfo, 4);
  ck_assert_int_eq(gameInfo.score, 6499);
  ck_assert_int_eq(gameInfo.high_score, 6499);
  infoFree(&gameInfo);
}
END_TEST

Suite *suite_tetris_base(void) {
  Suite *s = suite_create("suite_tetris_base");
  TCase *tc = tcase_create("tetris_base_tc");

  tcase_add_test(tc, test_info_init);
  tcase_add_test(tc, test_tetramino_I);
  tcase_add_test(tc, test_move_down);
  tcase_add_test(tc, test_check_full_line);
  tcase_add_test(tc, test_tetramino_init_J);
  tcase_add_test(tc, test_tetramino_init_L);
  tcase_add_test(tc, test_tetramino_init_O);
  tcase_add_test(tc, test_tetramino_init_S);
  tcase_add_test(tc, test_tetramino_init_T);
  tcase_add_test(tc, test_tetramino_init_Z);
  tcase_add_test(tc, test_next_init_I);
  tcase_add_test(tc, test_next_init_J);
  tcase_add_test(tc, test_next_init_L);
  tcase_add_test(tc, test_next_init_O);
  tcase_add_test(tc, test_next_init_S);
  tcase_add_test(tc, test_next_init_T);
  tcase_add_test(tc, test_next_init_Z);
  tcase_add_test(tc, test_board_update);
  tcase_add_test(tc, test_lines_to_score);

  suite_add_tcase(s, tc);
  return s;
}
