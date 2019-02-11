OBJECT_FLAGS = -g -c 
EXECUTABLE_FLAGS = -g 

all: prog1generator.o prog1sorter.o
	gcc $(EXECUTABLE_FLAGS) interface.o prog1generator.o -o prog1generator
	gcc $(EXECUTABLE_FLAGS) interface.o prog1sorter.o -o prog1sorter

prog1generator.o: interface.o prog1generator.c
	gcc $(OBJECT_FLAGS) prog1generator.c

prog1sorter.o: interface.o prog1sorter.c
	gcc $(OBJECT_FLAGS) prog1sorter.c

interface.o: interface.h interface.c
	gcc $(OBJECT_FLAGS) interface.c

clean:
	rm -rf *~ *.o prog1generator prog1sorter
