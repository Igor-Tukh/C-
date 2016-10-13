main: ./bin/main.o ./bin/position.o ./bin/clist.o
	gcc ./bin/main.o ./bin/position.o ./bin/clist.o -o main

bin/main.o: ./src/main.c include/position.h
	mkdir -p bin
	gcc -c ./src/main.c -o ./bin/main.o -I include 

bin/position.o: ./src/position.c include/clist.h
	mkdir -p bin
	gcc -c ./src/position.c -o ./bin/position.o -I include 
    
bin/clist.o: ./src/clist.c include/clist.h
	mkdir -p bin
	gcc -c ./src/clist.c -o ./bin/clist.o -I include

clean:
	rm -rf bin main
