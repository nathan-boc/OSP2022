output: main.o Task1Filter.o
	gcc -Wall -Werror -std=gnu99 -ggdb3 main.o Task1Filter.o -o Task1 -lm

main.o: main.c
	gcc -Wall -Werror -std=gnu99 -ggdb3 -c main.c

Task1Filter.o: Task1Filter.c
	gcc -Wall -Werror -std=gnu99 -ggdb3 -c Task1Filter.c

clean: 
	rm *.o Task1
