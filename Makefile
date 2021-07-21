CXXFLAGS ?= -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable

build: dynamic_arrays

dynamic_arrays: dynamic_arrays.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f dynamic_arrays

test:
	./dynamic_arrays