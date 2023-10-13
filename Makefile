all: exec test

test: exec src/test.sh
	@./src/test.sh tests/*.test ./exec

exec: src/main.c
	@gcc -O2 src/main.c -o exec