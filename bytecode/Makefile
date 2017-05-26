main: main.o  bytecode.o
	gcc main.o bytecode.o -o main

main.o: bytecode.h main.c
	gcc -c main.c

bytecode.o: bytecode.h bytecode.c
	gcc -c bytecode.c

clean:
	@echo "clean project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean
