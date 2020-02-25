all: reloadtroquic

reloadtroquic: reloadtroquic.o
	$(CXX) -o $@ $^

reloadtroquic.o: reloadtroquic.cpp

clean: rm -f reaload*.o
