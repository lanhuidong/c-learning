main: main.o  bytecode.o
	gcc --std=c99 main.o bytecode.o -o main

main.o: bytecode.h main.c
	gcc --std=c99 -c main.c

bytecode.o: bytecode.h bytecode.c
	gcc --std=c99 -c bytecode.c

clean:
	@echo "clean project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean
