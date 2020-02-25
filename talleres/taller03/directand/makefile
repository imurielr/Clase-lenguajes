all: directand

directand: directand.o maindirectand.o
	$(CXX) -o $@ $^

directand.o: directand.cpp directand.h

maindirectand.o: maindirectand.cpp directand.h

clean: rm -f directand*.o