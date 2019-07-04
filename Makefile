all: run

run: test
	clear
	./test

test: get_next_line.c check.txt
	gcc -o test main.c get_next_line.c libft/libft.a

clean:
	rm -r test
