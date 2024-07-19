CC=g++
CC_FLAGS=-Wall -Werror -Wextra -std=c++17
TESTS_FOLDER=tests/

.PHONY: tests gcov_report valgrind clean clang

all: install gcov_report

install:
	cmake gui/desktop -B ../build
	make -C ../build/
	cp ../build/brickGame ../artifact/

uninstall:
	rm -f ../artifact/brickGame

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
	rm -f snake.a test *.o
	rm -f $(TESTS_FOLDER)*.gcda $(TESTS_FOLDER)*.gcno $(TESTS_FOLDER)test.info
	rm -rf report

clang:
	cp ../materials/linters/.clang-format .
	find . -type f -name "*.cc" -exec clang-format -i {} +
	find . -type f -name "*.h" -exec clang-format -i {} +
	rm -f .clang-format
