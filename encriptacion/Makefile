OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_Mensaje.o Cjt_Alfabeto.o Mensaje.o Alfabeto.o BinTree.o
	g++ -o program.exe program.o Cjt_Mensaje.o Cjt_Alfabeto.o Mensaje.o Alfabeto.o

Alfabeto.o: Alfabeto.cc Alfabeto.hh
	g++ -c -o $@ $< $(OPCIONS)

Mensaje.o: Mensaje.cc Mensaje.hh
	g++ -c -o $@ $< $(OPCIONS)

BinTree.o: BinTree.hh
	g++ -c -o $@ $< $(OPCIONS)

Cjt_Alfabeto.o: Cjt_Alfabeto.cc Cjt_Alfabeto.hh Alfabeto.hh
	g++ -c -o $@ $< $(OPCIONS)

Cjt_Mensaje.o: Cjt_Mensaje.cc Cjt_Mensaje.hh Mensaje.hh Cjt_Alfabeto.hh BinTree.hh
	g++ -c -o $@ $< $(OPCIONS)

program.o: program.cc Cjt_Mensaje.hh Cjt_Alfabeto.hh Mensaje.hh Alfabeto.hh
	g++ -c -o $@ $< $(OPCIONS)

practica.tar: Alfabeto.cc Alfabeto.hh Mensaje.cc Mensaje.hh Cjt_Alfabeto.cc Cjt_Alfabeto.hh Cjt_Mensaje.cc Cjt_Mensaje.hh BinTree.hh program.cc
	tar -cvf practica.tar *.cc *.hh *.zip Makefile

clean:
	rm *.o
	rm *.exe
#test:
#	make
#	./program.exe <sample.inp> z.out
#	kompare z.out sample.cor