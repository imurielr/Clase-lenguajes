all: secuencia

secuencia: secuencia.o
	$(CXX) -o $@ $^

secuencia.o: secuencia.cpp

clean: rm -f secuencia*.o