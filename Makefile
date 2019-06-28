#Riya Baphna
#Lab 103
#rb4nk
#Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -O2 -std=c++11
OFILES = BinarySearchTree.o BinaryNode.o BSTPathTest.o
 .SUFFIXES: .o .cpp

BinarySearchTree: $(OFILES)
	$(CXX) $(OFILES)
        
	
clean:
	 -rm -f *.o *~ hashTable

hashTable.o: hashTable.cpp hashTable.h timer.h
timer.o: timer.cpp timer.h
timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h

