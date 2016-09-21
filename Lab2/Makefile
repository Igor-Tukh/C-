lab2: ./bin/test.o ./bin/test_str.o ./bin/str.o
	gcc ./bin/test.o ./bin/test_str.o ./bin/str.o -o lab2

bin/test.o: ./src/test.c include/test_str.h include/str.h
	mkdir -p bin
	gcc -c ./src/test.c -o ./bin/test.o -I include 
    
bin/test_str.o: ./src/test_str.c include/str.h
	mkdir -p bin
	gcc -c ./src/test_str.c -o ./bin/test_str.o -I include

bin/str.o: ./src/str.c
	mkdir -p bin
	gcc -c ./src/str.c -o ./bin/str.o -I include

clean:
	rm -rf bin lab2
	 