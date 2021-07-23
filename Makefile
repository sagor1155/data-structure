CXXFLAGS ?= -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable

build: dynamic_arrays doubly_linked_list

doubly_linked_list: doubly_linked_list.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

dynamic_arrays: dynamic_arrays.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f dynamic_arrays doubly_linked_list

test:
	./doubly_linked_list