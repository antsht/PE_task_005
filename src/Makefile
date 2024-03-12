BUILD_PATH=../bin/
CC=gcc
CFLAGS=-g -Wall -Wextra -Werror
EXTRAFLAGS=-fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector 

all: check rebuild

build: clean house travel morse

rebuild: clean_all house travel morse clean

house: clean house.c common/errors.c common/logger.c
	$(CC) $(CFLAGS) $(EXTRAFLAGS) house.c common/errors.c common/logger.c -o  $(BUILD_PATH)house 

travel: clean travel.c common/errors.c common/logger.c common/files.c
	$(CC) $(CFLAGS) $(EXTRAFLAGS) travel.c common/errors.c common/logger.c common/files.c -o  $(BUILD_PATH)travel -lm

morse: clean morse.c common/errors.c common/logger.c common/files.c
	$(CC) $(CFLAGS) $(EXTRAFLAGS) morse.c common/errors.c common/logger.c common/files.c -o  $(BUILD_PATH)morse


clean_all:
	rm -rf *.o *.a *.so $(BUILD_PATH)*
	
clean:
	rm -rf *.o *.a

check:
	clang-format -i *.c
	clang-format -i *.h
	clang-format -i */*.c
	clang-format -i */*.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h common/*.c common/*.h

test:
	cd ../	
	pytest --color=yes -v --tb=short  

test_config:
	python3 -m venv test-env  
	source test-env/bin/activate 
	pip install -r tests/requirements.txt



