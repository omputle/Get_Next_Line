all: run

run: test
	./test

test: main.c
	gcc -o test main.c get_next_line.c libft/libft.a

fclean:
	rm -r test
