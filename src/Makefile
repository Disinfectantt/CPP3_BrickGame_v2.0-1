CC=g++
C_COMPILER=gcc
CC_FLAGS=-Wall -Werror -Wextra -std=c++17
C_CC_FLAGS=-Wall -Werror -Wextra -std=c11
TESTS_FOLDER=tests/
INSTALL_PATH=../artifact/
NCURSES_FLAGS := $(shell pkg-config --cflags --libs ncurses)
COVERAGE_FLAGS=-fprofile-arcs -ftest-coverage
LDFLAGS=$(shell pkg-config --libs gtest_main)
CHECK=$(shell pkg-config --libs check)

all: install cli gcov_report

install: cli
	cmake gui/desktop -B ../build
	make -C ../build/
	cp ../build/brickGame $(INSTALL_PATH)

uninstall:
	rm -f $(INSTALL_PATH)brickGame $(INSTALL_PATH)highscore_tetris.txt $(INSTALL_PATH)snake_max_score.txt $(INSTALL_PATH)cli

cli: snake.a tetris.a
	$(C_COMPILER) $(C_CC_FLAGS) -c gui/cli/*.c
	$(CC) $(CC_FLAGS) -o ../artifact/cli gui/cli/*.cc *.o snake.a tetris.a $(NCURSES_FLAGS)

tetris.a:
	$(C_COMPILER) $(C_CC_FALGS) -c brick_game/tetris/*.c
	ar rc tetris.a *.o
	ranlib tetris.a
	rm -f *.o

snake.a:
	$(CC) $(CC_FLAGS) -c brick_game/snake/*/*.cc
	ar rc snake.a *.o
	ranlib snake.a
	rm -f *.o

gcov_report: tests
	lcov -t "test" -o $(TESTS_FOLDER)test.info -c -d . --no-external --ignore-errors mismatch,mismatch
	genhtml -o report $(TESTS_FOLDER)test.info
	xdg-open report/index.html

tests: clean tetris_test snake_test

tetris_test:
	$(C_COMPILER) $(C_CC_FLAGS) $(COVERAGE_FLAGS) tests/tetris/*.c brick_game/tetris/*.c -o tetris_test $(CHECK)
	./tetris_test
	mv *.gcda *.gcno $(TESTS_FOLDER)

snake_test:
	$(CC) $(CC_FLAGS) $(CC_test) $(COVERAGE_FLAGS) tests/snake/*.cc brick_game/snake/*/*.cc -o snake_test $(LDFLAGS)
	./snake_test
	mv *.gcda *.gcno $(TESTS_FOLDER)

valgrind_tetris: tetris.a
	$(C_COMPILER) $(C_CC_FLAGS) $(COVERAGE_FLAGS) -g tests/tetris/*.c tetris.a -o tetris_test $(CHECK)
	valgrind --tool=memcheck --leak-check=yes ./tetris_test
	mv *.gcda *.gcno $(TESTS_FOLDER)

valgrind_snake: clean snake.a
	$(CC) $(CC_FLAGS) $(CC_test) $(COVERAGE_FLAGS) -g tests/snake/*.cc snake.a -o snake_test $(LDFLAGS)
	valgrind --tool=memcheck --leak-check=yes ./snake_test
	mv *.gcda *.gcno $(TESTS_FOLDER)

clean:
	rm -f snake.a tetris.a test *.o
	rm -f $(TESTS_FOLDER)*.gcda $(TESTS_FOLDER)*.gcno $(TESTS_FOLDER)test.info
	rm -rf report highscore_tetris.txt tetris_test snake_test snake_max_score.txt

clang:
	cp ../materials/linters/.clang-format .
	find . -type f -name "*.cc" -exec clang-format -i {} +
	find . -type f -name "*.h" -exec clang-format -i {} +
	find . -type f -name "*.c" -exec clang-format -i {} +
	rm -f .clang-format

dvi:
	xdg-open ../README.md

dist: $(shell find . -name '*.c') $(shell find . -name '*.cc') $(shell find . -name '*.h') ./Makefile
	tar -czf BrickGame_v2.0-1.tar.gz $^

.PHONY: tests gcov_report valgrind clean clang install uninstall cli tetris_test snake_test valgrind_snake valgrind_tetris dvi dist
