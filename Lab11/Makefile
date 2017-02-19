all: empl_db

bin:
	mkdir -p bin

empl_db: bin ./bin/main.o ./bin/employees.o
	g++ ./bin/main.o ./bin/employees.o  -lexpat -o empl_db

bin/main.o: ./src/main.cpp include/employees.h
	g++ -c ./src/main.cpp -o ./bin/main.o -I include 

bin/employees.o: ./src/employees.cpp include/employees.h
	g++ -c ./src/employees.cpp -o ./bin/employees.o -I include

clean:
	rm -rf bin empl_db
