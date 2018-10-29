
CXX=g++
CXXFLAGS=-Wall -g -Wextra -pedantic -Werror -std=c++11
OPTFLAGS=-O3
LDFLAGS=$(CXXFLAGS) $(OPTFLAGS)

all: test_tree

test_tree: tree.o test_tree.o
	$(CXX) $(LDFLAGS) test_tree.o tree.o -o test_tree

tree.o: tree.cc tree.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c tree.cc -o tree.o

test_tree.o: test_tree.cc tree.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c test_tree.cc -o test_tree.o

clean:
	rm -rf *.o test_tree
