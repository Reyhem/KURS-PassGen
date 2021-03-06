CFLAGS= -I./tests -I./source
VPATH = SRC INCLUDE 

main: main.o generator.o mtest.o test.o 
	mkdir bin
	gcc ${CFLAGS} -o bin/main obj/main.o obj/generator.o -lm
	gcc ${CFLAGS} -o bin/test obj/mtest.o obj/test.o  obj/generator.o -lm

main.o: source/main.c
	mkdir obj
	gcc -c ${CFLAGS} source/main.c -o obj/main.o -lm

mtest.o: test/main.c 
	gcc -c ${CFLAGS} test/main.c -o obj/mtest.o  -lm

test.o: test/test.c
	gcc -c ${CFLAGS} test/test.c -o obj/test.o -lm

generator.o: source/generator.c 
	gcc -c ${CFLAGS} source/generator.c -o obj/generator.o -lm

clean:
	rm -f obj/*.o
	rm -f bin/*.exe
	rmdir obj
	rmdir bin	
	