CC = gcc
I = shell.c
O = shell
FLAGS = -Wall -Wextra -g -std=c11

main: $(I)
	$(CC) $(I) $(FLAGS) -o $(O)
	./$(O)

clean:
	del -f $(O)
	cls