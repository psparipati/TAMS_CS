# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -pedantic
TARGET = bank_system

# Source files
SRCS = main.cpp Account.cpp Accounts.cpp AccountSystem.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Account.h Accounts.h AccountSystem.h

# Default target
all: $(TARGET)

# Create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Object file dependencies
main.o: main.cpp Account.h Accounts.h AccountSystem.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Account.o: Account.cpp Account.h
	$(CXX) $(CXXFLAGS) -c Account.cpp

Accounts.o: Accounts.cpp Accounts.h Account.h
	$(CXX) $(CXXFLAGS) -c Accounts.cpp

AccountSystem.o: AccountSystem.cpp AccountSystem.h Accounts.h Account.h
	$(CXX) $(CXXFLAGS) -c AccountSystem.cpp

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Rebuild everything
rebuild: clean all

# Phony targets (not actual files)
.PHONY: all clean rebuild