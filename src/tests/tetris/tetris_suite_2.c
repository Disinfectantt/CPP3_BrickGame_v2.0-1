#include "s21_tetris_test.h"

START_TEST(test_movedown) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current = {.x1 = 5,
                       .y1 = 10,
                       .x2 = 5,
                       .y2 = 11,
                       .x3 = 5,
                       .y3 = 12,
                       .x4 = 5,
                       .y4 = 13};

  int result = movedown(&current, &gameInfo);
  ck_assert_int_eq(result, 0);
  ck_assert_int_eq(current.y1, 11);
  ck_assert_int_eq(current.y2, 12);
  ck_assert_int_eq(current.y3, 13);
  ck_assert_int_eq(current.y4, 14);

  current.y1 = 18;
  current.y2 = 19;
  current.y3 = 19;
  current.y4 = 19;
  result = movedown(&current, &gameInfo);
  ck_assert_int_eq(result, 1);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_lines_to_score) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);

  lines_to_score(&gameInfo, 1);
  ck_assert_int_eq(gameInfo.score, 100);
  ck_assert_int_eq(gameInfo.level, 1);

  gameInfo.score = 0;
  lines_to_score(&gameInfo, 2);
  ck_assert_int_eq(gameInfo.score, 300);
  ck_assert_int_eq(gameInfo.level, 1);

  gameInfo.score = 0;
  lines_to_score(&gameInfo, 4);
  ck_assert_int_eq(gameInfo.score, 1500);
  ck_assert_int_eq(gameInfo.level, 3);

  gameInfo.score = 5999;
  lines_to_score(&gameInfo, 1);
  ck_assert_int_eq(gameInfo.score, 6099);
  ck_assert_int_eq(gameInfo.level, 10);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_mainGameLogic) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);

  tetris_state state = mainGameLogic(NULL, -1);
  ck_assert_int_eq(state, SPAWN);

  state = mainGameLogic(&gameInfo, -1);
  ck_assert_int_eq(state, PAUSE);
  ck_assert_int_eq(gameInfo.pause, 1);
  handle_user_input(Pause);
  ck_assert_int_eq(gameInfo.pause, 0);

  state = mainGameLogic(&gameInfo, Left);
  ck_assert_int_eq(state, SHIFTING);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_rotate_I) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current;
  current.rotate_state = 0;
  tetramino_init_I(&current);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 0);
  movedown(&current, &gameInfo);
  movedown(&current, &gameInfo);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 1);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_rotate_J) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current;
  current.rotate_state = 0;
  tetramino_init_J(&current);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 1);
  moveright(&current, &gameInfo);
  moveright(&current, &gameInfo);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 2);
  movedown(&current, &gameInfo);
  movedown(&current, &gameInfo);
  movedown(&current, &gameInfo);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 3);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_rotate_L) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current;
  current.rotate_state = 0;
  tetramino_init_L(&current);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 1);
  moveleft(&current, &gameInfo);
  moveleft(&current, &gameInfo);
  moveleft(&current, &gameInfo);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 2);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 3);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_rotate_S) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current;
  current.rotate_state = 0;
  tetramino_init_S(&current);
  moveleft(&current, &gameInfo);
  moveleft(&current, &gameInfo);
  moveleft(&current, &gameInfo);
  movedown(&current, &gameInfo);
  movedown(&current, &gameInfo);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 1);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_rotate_T) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current;
  current.rotate_state = 0;
  tetramino_init_T(&current);
  moveright(&current, &gameInfo);
  moveright(&current, &gameInfo);
  moveright(&current, &gameInfo);
  movedown(&current, &gameInfo);
  movedown(&current, &gameInfo);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 1);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 2);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 3);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_rotate_Z) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  Tetramino current;
  current.rotate_state = 0;
  tetramino_init_Z(&current);
  moveleft(&current, &gameInfo);
  moveleft(&current, &gameInfo);
  moveleft(&current, &gameInfo);
  movedown(&current, &gameInfo);
  movedown(&current, &gameInfo);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 1);
  rotate(&current, &gameInfo);
  ck_assert_int_eq(current.rotate_state, 0);
  infoFree(&gameInfo);
}
END_TEST

START_TEST(test_game_loop) {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  ck_assert_int_eq((int)game_loop(NULL, -1), (int)Pause);
  infoFree(&gameInfo);
}
END_TEST

Suite *tetris_2(void) {
  Suite *s = suite_create("suite_tetris_2");
  TCase *tc = tcase_create("tetris2_tc");
  tcase_add_test(tc, test_movedown);
  tcase_add_test(tc, test_rotate_I);
  tcase_add_test(tc, test_lines_to_score);
  tcase_add_test(tc, test_mainGameLogic);
  tcase_add_test(tc, test_rotate_I);
  tcase_add_test(tc, test_rotate_J);
  tcase_add_test(tc, test_rotate_L);
  tcase_add_test(tc, test_rotate_S);
  tcase_add_test(tc, test_rotate_T);
  tcase_add_test(tc, test_rotate_Z);
  tcase_add_test(tc, test_game_loop);
  suite_add_tcase(s, tc);
  return s;
}
