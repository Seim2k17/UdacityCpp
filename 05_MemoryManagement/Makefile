.PHONY: all
allmain: prog1 prog2 prog3 prog4 prog5 prog6 prog7

.PHONY: all
prog1:
	cd build && \
	g++ -Wall -o debug ../src/01_debug.cpp
prog2: 
	cd build && \
	g++ -Wall -o chrono ../src/02_chrono_example.cpp
prog3: 
	cd build && \
	g++ -Wall -o stack ../src/03_stack_example.cpp
prog4:
	cd build && \
	g++ -Wall -o valRef ../src/04_call_by_value_ref.cpp
prog5:
	cd build && \
	g++ -g -Wall -o memAlloc ../src/05_alloc_memory.cpp
prog6:
	cd build && \
	g++ -g -Wall -o mallocNew ../src/06_malloc_v_new.cpp
prog7:
	cd build && \
	g++ -g -Wall -o overloadNew ../src/07_overload_new.cpp

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
