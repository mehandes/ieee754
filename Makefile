src=src

all: exec

test: exec

exec: $(src)/main.c
	@gcc -O2 $(src)/main.c -o exec

