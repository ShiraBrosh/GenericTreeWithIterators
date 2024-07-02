CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -fPIC
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = main.cpp
TEST_SOURCES = Test.cpp
HEADERS = Node.hpp tree.hpp Complex.hpp
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

TARGET = tree
TEST_TARGET = test

.PHONY: all clean

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(SFMLFLAGS)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) -o $(TEST_TARGET) $(SFMLFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(SFMLFLAGS)

clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS) $(TARGET) $(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)
