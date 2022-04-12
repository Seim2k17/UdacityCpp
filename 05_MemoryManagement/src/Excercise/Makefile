.PHONY: all
allmain: pract1

.PHONY: all
pract1:
	cd ../../build && \
	g++ -Wall -o 6_p1_smart_pointer ../src/Excercise/practice_smart_pnt.cpp
	

.PHONY: debug
debug:
	mkdir -p build
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=debug .. && \
	make

.PHONY: clean
clean:
	rm -rf build
