.PHONY: all
allmain: ex1 ex2

.PHONY: all
ex2:
	cd build && \
	g++ -Wall -o 02_ex2 ../src/02_example_2.cpp
ex1:
	cd build && \
	g++ -Wall -o 01_ex1 ../src/01_example_1.cpp

test1:
	cd build && \
	g++ -Wall -pthread -o 00_testThread ../src/00_testThread.cpp

.PHONY: all
all: format test build

.PHONY: format
format:
	clang-format src/* include/* -i

.PHONY: build
build:
	mkdir -p build
	cd build && \
	cmake .. && \
	make

.PHONY: debug
debug:
	mkdir -p build
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=debug .. && \
	make

.PHONY: clean
clean:
	rm -rf build
