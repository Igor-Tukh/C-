lab1: ./bin/util.o ./bin/algorithm.o ./bin/io.o ./bin/main.o
	gcc ./bin/util.o ./bin/algorithm.o ./bin/io.o ./bin/main.o -o lab1

bin/main.o: ./src/main.c include/algorithm.h include/util.h include/io.h
	mkdir -p bin
	gcc -c ./src/main.c -o ./bin/main.o -I /include

bin/algorithm.o: ./src/algorithm.c include/io.h include/util.h
	mkdir -p bin
	gcc -c ./src/algorithm.c -o ./bin/algorithm.o -I /include

bin/io.o: ./src/io.c include/io.h
	mkdir -p bin
	gcc -c ./src/io.c -o ./bin/io.o -I /include

bin/util.o: ./src/util.c include/io.h
	mkdir -p bin
	gcc -c ./src/util.c -o ./bin/util.o -I /include

clean:
	rm -rf bin lab1
	 