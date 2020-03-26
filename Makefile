#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: SOLE
	./SOLE

SOLE: obj/main.o obj/LinearEquations.o obj/Matrix.o obj/Vector.o
	g++ -Wall -pedantic -o SOLE obj/main.o obj/Vector.o\
                                   obj/Matrix.o obj/LinearEquations.o

obj/main.o: src/main.cpp inc/LinearEquations.hh inc/Matrix.hh inc/Vector.hh\
        inc/size.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LinearEquations.o: src/LinearEquations.cpp inc/LinearEquations.hh
	g++ ${CPPFLAGS} -o obj/LinearEquations.o src/LinearEquations.cpp

obj/Matrix.o: src/Matrix.cpp inc/Matrix.hh 
	g++ ${CPPFLAGS} -o obj/Matrix.o src/Matrix.cpp

obj/Vector.o: src/Vector.cpp inc/Vector.hh inc/size.h
	g++ ${CPPFLAGS} -o obj/Vector.o src/Vector.cpp

clean:
	rm -f obj/*.o SOLE