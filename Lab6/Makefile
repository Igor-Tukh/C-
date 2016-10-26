main: ./bin/main.o ./bin/phonebook.o
	gcc ./bin/main.o ./bin/phonebook.o  -lexpat -o main

bin/main.o: ./src/main.c include/phonebook.h
	mkdir -p bin
	gcc -c ./src/main.c -o ./bin/main.o -I include 

bin/phonebook.o: ./src/phonebook.c include/names.h include/phonebook.h
	mkdir -p bin
	gcc -c ./src/phonebook.c -o ./bin/phonebook.o -I include

clean:
	rm -rf bin main
