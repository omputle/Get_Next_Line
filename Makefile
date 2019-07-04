all: run

run: test
	./test

test: main.c
	gcc -o test main.c krillin.c libft/libft.a

fclean:
	rm -r test
