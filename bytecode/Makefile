main: main.o  bytecode.o constant_pool_out.o
	gcc --std=c99 -lm main.o bytecode.o constant_pool_out.o -o main

main.o: bytecode.h constant_pool_out.h main.c
	gcc --std=c99 -c main.c

bytecode.o: bytecode.h bytecode.c
	gcc --std=c99 -c bytecode.c

constant_pool_out.o: bytecode.h constant_pool_out.h constant_pool_out.c
	gcc --std=c99 -c constant_pool_out.c

clean:
	@echo "clean project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean
