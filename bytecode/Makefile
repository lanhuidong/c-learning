main: main.o util.o bytecode.o constant_pool_parse.o constant_pool_out.o
	gcc --std=c99 -Wall -lm main.o util.o bytecode.o constant_pool_parse.o constant_pool_out.o -o main

main.o: main.c
	gcc --std=c99 -Wall  -c main.c

util.o: util.c
	gcc --std=c99 -Wall -c util.c

bytecode.o: bytecode.h bytecode.c
	gcc --std=c99 -Wall -c bytecode.c

constant_pool_parse.o: bytecode.h constant_pool_parse.c
	gcc --std=c99 -Wall -c constant_pool_parse.c

constant_pool_out.o: bytecode.h constant_pool_out.c
	gcc --std=c99 -Wall -c constant_pool_out.c

clean:
	@echo "clean project"
	-rm main *.o
	@echo "clean completed"

.PHONY: clean
