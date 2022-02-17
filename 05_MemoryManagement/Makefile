.PHONY: all
allmain: prog 17 prog16 prog15 prog14 prog13 prog1 prog2 prog3 prog4 prog5 prog6 prog7 prog8 prog9 prog10 prog11 prog12

.PHONY: all
prog17:
	cd build && \
	g++ -Wall -o 17_rvalue_ref ../src/17_rvalue_ref.cpp
prog16:
	cd build && \
	g++ -Wall -o 16_l_r_values ../src/16_l_r_values.cpp
prog15:
	cd build && \
	g++ -Wall -o 15_shared_ownership ../src/15_shared_ownership.cpp
prog14:
	cd build && \
	g++ -Wall -o 14_deep_copying ../src/14_deep_copying.cpp
prog13:
	cd build && \
	g++ -Wall -o 13_exclusive_ownership ../src/13_exclusive_ownership.cpp
prog1:
	cd build && \
	g++ -Wall -o 01_debug ../src/01_debug.cpp
prog2: 
	cd build && \
	g++ -Wall -o 02_chrono ../src/02_chrono_example.cpp
prog3: 
	cd build && \
	g++ -Wall -o 03_stack ../src/03_stack_example.cpp
prog4:
	cd build && \
	g++ -Wall -o 04_valRef ../src/04_call_by_value_ref.cpp
prog5:
	cd build && \
	g++ -g -Wall -o 05_memAlloc ../src/05_alloc_memory.cpp
prog6:
	cd build && \
	g++ -g -Wall -o 06_mallocNew ../src/06_malloc_v_new.cpp
prog7:
	cd build && \
	g++ -g -Wall -o 07_overloadNew ../src/07_overload_new.cpp
prog8:
	cd build && \
	g++ -g -Wall -o 08_makeArrayNew ../src/08_new_array.cpp
prog9:
	cd build && \
	g++ -g -Wall -o 09_memoryProblems ../src/09_memory_problems.cpp
prog10:
	cd build && \
	g++ -g -Wall -o 10_memoryProblems2 ../src/10_valgind_test.cpp
prog11:
	cd build && \
	g++ -g -Wall -o 11_raiiCheck ../src/11_raii_1.cpp
prog12:
	cd build && \
	g++ -g -Wall -o 12_noCopyPolicy ../src/12_nocopypolicy.cpp

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
