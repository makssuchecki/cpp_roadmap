CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -MMD -MP
TARGET   = program
SRCS     = $(wildcard src/*.cpp)
OBJS     = $(SRCS:src/%.cpp=build/%.o)
DEPS     = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean run

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build $(TARGET)