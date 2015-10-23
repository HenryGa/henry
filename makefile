all: equations generate

equations: main.cpp Matrix.o Polywnymo_mhtrwwn.o Pinakas_syntelestwn.o Sylvester.o Pinakas_polywnymou_mhtrwwn.o Handler.o
	g++ -o equations Matrix.o Handler.o Polywnymo_mhtrwwn.o Pinakas_syntelestwn.o Sylvester.o Pinakas_polywnymou_mhtrwwn.o main.cpp main.hpp  -g3

Matrix.o: libMatrix/Matrix.cpp
	g++ -c libMatrix/Matrix.cpp libMatrix/Matrix.h

generate: generate_functions.cpp
	g++ -o generate generate_functions.cpp

Pinakas_syntelestwn.o: libMatrix/Pinakas_syntelestwn.cpp
	g++ -c libMatrix/Pinakas_syntelestwn.cpp libMatrix/Pinakas_syntelestwn.hpp

Polywnymo_mhtrwwn.o: libMatrix/Polywnymo_mhtrwwn.cpp
	g++ -c libMatrix/Polywnymo_mhtrwwn.cpp libMatrix/Polywnymo_mhtrwwn.h

Pinakas_polywnymou_mhtrwwn.o: libMatrix/Pinakas_polywnymou_mhtrwwn.cpp
	g++ -c libMatrix/Pinakas_polywnymou_mhtrwwn.cpp libMatrix/Pinakas_polywnymou_mhtrwwn.h

Sylvester.o: libMatrix/Sylvester.cpp
	g++ -c libMatrix/Sylvester.cpp libMatrix/Sylvester.h

Handler.o: Handler.cpp
	g++ -c Handler.cpp Handler.h

clean:
	rm -f *.o equations generate *.gch generated_functions.txt
