OBJECTS = OList.o main.o node.o 
OBJECTS2 = tests tests.o
CXXFLAGS = -g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

OList.o: OList.cpp Node.h OList.h

main.o: main.cpp OList.h Node.h

node.o: node.cpp node.h

tests: tests.o
	g++ -o tests tests.o

tests.o: tests.cpp
	g++ -c tests.cpp

clean:
	rm -f main $(OBJECTS) $(OBJECTS2)