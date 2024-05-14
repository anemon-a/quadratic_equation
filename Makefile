CC=gcc
CFLAGS= -Wall -Werror -Wextra
PLATFORM := $(shell uname)
NAME_PROJECT=quadratic_equation

all: test

ifeq ($(PLATFORM), Darwin)
test: $(NAME_PROJECT).a
	$(CC) $(CFLAGS) --coverage $(NAME_PROJECT)_test.c $(NAME_PROJECT).c -o test $(NAME_PROJECT).a -lcheck
	./test
else
test: $(NAME_PROJECT).a
	$(CC) --coverage $(NAME_PROJECT)_test.c $(NAME_PROJECT).c -o test $(NAME_PROJECT).a -lcheck_pic -lpthread -lrt -lm -lsubunit
	./test
endif

$(NAME_PROJECT).a: $(NAME_PROJECT).o
	ar rc $(NAME_PROJECT).a $(NAME_PROJECT).o
	ranlib $(NAME_PROJECT).a

$(NAME_PROJECT).o:
	$(CC) $(CFLAGS) -c $(NAME_PROJECT).c

clang-format:
	clang-format -n *.c *.h

clean:
	rm -rf ./*.o ./*.gcda ./*.gcno ./*.info ./*.a ./*txt test

rebuild: clean all