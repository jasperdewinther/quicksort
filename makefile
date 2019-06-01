compiler := g++
CppVersion := -std=c++17
extraFlags := -Werror -Wall -Wextra -g -Ofast


CPPFLAGS := $(compiler) $(CppVersion) $(extraFlags)

SRC_DIR := ./src
OBJ_DIR := ./obj
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
HDR_FILES := $(wildcard $(SRC_DIR)/*.hpp)
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(SRC_FILES))


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CPPFLAGS) -c $< -o $@

program: $(OBJ_FILES) $(HDR_FILES)
	$(CPPFLAGS) $^ -o $@

make:
	program

build:
	make

brun:
	make
	./program

run:
	./program

.PHONY: clean
clean:
	rm *.o program

rebuild:
	make clean || make build

rebrun:
	make clean || make brun