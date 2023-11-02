all:
	gcc -Wall -Werror -Wextra -pedantic -Iinclude -Llib src/*.c -o maze.exe -lSDL2main -lSDL2 -lmingw32
	./maze.exe