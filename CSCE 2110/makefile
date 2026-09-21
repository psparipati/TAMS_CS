CXX = g++
CXXFLAGS = -Wall -std=c++11
OBJECTS = clientNode.o clientLinkedList.o clientStack.o clientQueue.o
EXECUTABLE = clientsystem

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS)

clientNode.o: clientNode.cpp clientNode.hpp
	$(CXX) $(CXXFLAGS) -c clientNode.cpp

clientLinkedList.o: clientLinkedList.cpp clientLinkedList.hpp clientNode.hpp
	$(CXX) $(CXXFLAGS) -c clientLinkedList.cpp

clientStack.o: clientStack.cpp clientStack.hpp clientNode.hpp
	$(CXX) $(CXXFLAGS) -c clientStack.cpp

clientQueue.o: clientQueue.cpp clientQueue.hpp clientNode.hpp
	$(CXX) $(CXXFLAGS) -c clientQueue.cpp

main.o: main.cpp clientNode.hpp clientLinkedList.hpp clientStack.hpp clientQueue.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: all clean
