SRC=src
BIN=bin

CXXFLAGS ?= -std=c++17 -g -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable

build: $(BIN)/dynamic_arrays $(BIN)/doubly_linked_list $(BIN)/linked_list $(BIN)/tower_of_hanoi $(BIN)/stack $(BIN)/queue $(BIN)/binary_search_tree

$(BIN)/dynamic_arrays: $(SRC)/dynamic_arrays.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN)/doubly_linked_list: $(SRC)/doubly_linked_list.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN)/linked_list: $(SRC)/linked_list.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN)/tower_of_hanoi: $(SRC)/tower_of_hanoi.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN)/stack: $(SRC)/stack.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN)/queue: $(SRC)/queue.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BIN)/binary_search_tree: $(SRC)/binary_search_tree.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BIN)/dynamic_arrays $(BIN)/doubly_linked_list $(BIN)/linked_list $(BIN)/tower_of_hanoi $(BIN)/stack $(BIN)/queue $(BIN)/binary_search_tree

test:
	$(BIN)/binary_search_tree