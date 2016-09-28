pose_db: ./bin/main.o ./bin/clist.o
	gcc ./bin/main.o ./bin/clist.o -o pose_db

bin/main.o: ./src/main.c include/clist.h
	mkdir -p bin
	gcc -c ./src/main.c -o ./bin/main.o -I include 
    
bin/clist.o: ./src/clist.c include/clist.h
	mkdir -p bin
	gcc -c ./src/clist.c -o ./bin/clist.o -I include

clean:
	rm -rf bin pose_db
