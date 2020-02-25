all: tresMayor

tresMayor: tresMayor.o verificarTres.o
	$(CXX) -o $@ $^

tresMayor.o: tresMayor.cpp tresMayor.h

verificarTres.o: verificarTres.cpp tresMayor.h

clean: rm -f tresMayor.o verificarTres.o