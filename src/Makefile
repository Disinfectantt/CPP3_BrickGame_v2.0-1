CC=g++
C_COMPILER=gcc
CC_FLAGS=-Wall -Werror -Wextra -std=c++17
C_CC_FLAGS=-Wall -Werror -Wextra -std=c11
TESTS_FOLDER=tests/
INSTALL_PATH=../artifact/
NCURSES_FLAGS := $(shell pkg-config --cflags --libs ncurses)

.PHONY: tests gcov_report valgrind clean clang install uninstall cli

all: install gcov_report

install:
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

gcov_report: test
	lcov -t "test" -o $(TESTS_FOLDER)test.info -c -d . --no-external
	genhtml -o report $(TESTS_FOLDER)test.info
	open report/index.html

tests: clean
	$(CC) $(CC_FLAGS) $(CC_test) $(TESTS_FOLDER)*.cc *.cc -o test -lm $(LDFLAGS)
	./test
	mv *.gcda *.gcno $(TESTS_FOLDER)

valgrind: clean
	$(CC) -g $(CC_FLAGS) $(CC_test) $(TESTS_FOLDER)*.cc *.cc -o test -lm $(LDFLAGS)
	valgrind --tool=memcheck --leak-check=yes ./test
	mv *.gcda *.gcno $(TESTS_FOLDER)

clean:
	rm -f snake.a tetris.a test *.o
	rm -f $(TESTS_FOLDER)*.gcda $(TESTS_FOLDER)*.gcno $(TESTS_FOLDER)test.info
	rm -rf report

clang:
	cp ../materials/linters/.clang-format .
	find . -type f -name "*.cc" -exec clang-format -i {} +
	find . -type f -name "*.h" -exec clang-format -i {} +
	find . -type f -name "*.c" -exec clang-format -i {} +
	rm -f .clang-format
