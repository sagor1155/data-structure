SRC=src
BIN=bin

CXXFLAGS ?= -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable

build: $(BIN)/dynamic_arrays $(BIN)/doubly_linked_list

$(BIN)/doubly_linked_list: $(SRC)/doubly_linked_list.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN)/dynamic_arrays: $(SRC)/dynamic_arrays.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BIN)/dynamic_arrays $(BIN)/doubly_linked_list

test:
	$(BIN)/doubly_linked_list