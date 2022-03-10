.PHONY: all
allmain: ex3 ex2 ex1 prog20 prog19 prog18 prog17 prog16 prog15 prog14 prog13 prog1 prog2 prog3 prog4 prog5 prog6 prog7 prog8 prog9 prog10 prog11 prog12

.PHONY: all
ex3:
	cd build && \
	g++ -Wall -o 5_mv_ex3 ../src/Excercise/mv_ex3.cpp
ex2:
	cd build && \
	g++ -Wall -o 5_mv_ex2 ../src/Excercise/mv_ex2.cpp
ex1:
	cd build && \
	g++ -Wall -o 5_mv_ex1 ../src/Excercise/mv_ex1.cpp
prog20:
	cd build && \
	g++ -std=c++11 -Wall -o 5_20_rule_of_five ../src/20_rule_of_five.cpp
prog19:
	cd build && \
	g++ -Wall -o 5_19_rule_of_three ../src/19_rule_of_three.cpp
prog18:
	cd build && \
	g++ -Wall -o 5_18_move_semantics ../src/18_move_semantics.cpp
prog17:
	cd build && \
	g++ -Wall -o 5_17_rvalue_ref ../src/17_rvalue_ref.cpp
prog16:
	cd build && \
	g++ -Wall -o 5_16_l_r_values ../src/16_l_r_values.cpp
prog15:
	cd build && \
	g++ -Wall -o 5_15_shared_ownership ../src/15_shared_ownership.cpp
prog14:
	cd build && \
	g++ -Wall -o 5_14_deep_copying ../src/14_deep_copying.cpp
prog13:
	cd build && \
	g++ -Wall -o 5_13_exclusive_ownership ../src/13_exclusive_ownership.cpp
prog1:
	cd build && \
	g++ -Wall -o 5_01_debug ../src/01_debug.cpp
prog2: 
	cd build && \
	g++ -Wall -o 5_02_chrono ../src/02_chrono_example.cpp
prog3: 
	cd build && \
	g++ -Wall -o 5_03_stack ../src/03_stack_example.cpp
prog4:
	cd build && \
	g++ -Wall -o 5_04_valRef ../src/04_call_by_value_ref.cpp
prog5:
	cd build && \
	g++ -g -Wall -o 5_05_memAlloc ../src/05_alloc_memory.cpp
prog6:
	cd build && \
	g++ -g -Wall -o 5_06_mallocNew ../src/06_malloc_v_new.cpp
prog7:
	cd build && \
	g++ -g -Wall -o 5_07_overloadNew ../src/07_overload_new.cpp
prog8:
	cd build && \
	g++ -g -Wall -o 5_08_makeArrayNew ../src/08_new_array.cpp
prog9:
	cd build && \
	g++ -g -Wall -o 5_09_memoryProblems ../src/09_memory_problems.cpp
prog10:
	cd build && \
	g++ -g -Wall -o 5_10_memoryProblems2 ../src/10_valgind_test.cpp
prog11:
	cd build && \
	g++ -g -Wall -o 5_11_raiiCheck ../src/11_raii_1.cpp
prog12:
	cd build && \
	g++ -g -Wall -o 5_12_noCopyPolicy ../src/12_nocopypolicy.cpp

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
