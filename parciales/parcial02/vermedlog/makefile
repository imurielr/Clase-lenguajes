all: vermedlog

vermedlog: vermedlog.o
	$(CXX) -o $@ $^

vermedlog.o: vermedlog.cpp

clean: rm -f vermedlog*.o
