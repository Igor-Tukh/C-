ms_cli: ./bin/ms_cli.o ./bin/mergesort.o
	gcc ./bin/ms_cli.o ./bin/mergesort.o -o ms_cli

bin/ms_cli.o: ./src/ms_cli.c include/mergesort.h
	mkdir -p bin
	gcc -c ./src/ms_cli.c -o ./bin/ms_cli.o -I include 
    
bin/mergesort.o: ./src/mergesort.c
	mkdir -p bin
	gcc -c ./src/mergesort.c -o ./bin/mergesort.o -I include

clean:
	rm -rf bin ms_cli
