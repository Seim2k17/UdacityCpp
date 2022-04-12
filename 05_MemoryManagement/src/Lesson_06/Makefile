.PHONY: all
allmain:transfer2 transfer1 smart2 smart1 ex3 ex2 ex1 smartp1

.PHONY: all
transfer3:
	cd ../../build && \
	g++ -Wall -o 6_12_smart_transfer ../src/Lesson_06/12_transfer_smart_pnt_3.cpp
transfer2:
	cd ../../build && \
	g++ -Wall -o 6_11_smart_transfer ../src/Lesson_06/11_transfer_smart_pnt_2.cpp
transfer1:
	cd ../../build && \
	g++ -Wall -o 6_10_smart_transfer ../src/Lesson_06/10_transfer_smart_pnt_1.cpp
smart6:
	cd ../../build && \
	g++ -Wall -o 6_09_smart_conversion ../src/Lesson_06/09_smart_pnt_conversion.cpp
smart5:
	cd ../../build && \
	g++ -Wall -o 6_08_smart_weak2 ../src/Lesson_06/08_smart_weak_pnt2.cpp
smart4:
	cd ../../build && \
	g++ -Wall -o 6_07_smart_weak ../src/Lesson_06/07_smart_weak_pnt.cpp
smart3:
	cd ../../build && \
	g++ -Wall -o 6_06_smart_circular ../src/Lesson_06/06_smart_pnt_circular.cpp
smart2:
	cd ../../build && \
	g++ -Wall -o 6_05_smart_2 ../src/Lesson_06/05_smart_pnt_2.cpp
smart1:
	cd ../../build && \
	g++ -Wall -o 6_04_smart_1 ../src/Lesson_06/04_smart_pnt_1.cpp
ex3:
	cd ../../build && \
	g++ -Wall -o 6_03_raii_3 ../src/Lesson_06/03_raii_example3.cpp
ex2:
	cd ../../build && \
	g++ -Wall -o 6_02_raii_2 ../src/Lesson_06/02_raii_example2.cpp
ex1:
	cd ../../build && \
	g++ -Wall -o 6_01_raii_1 ../src/Lesson_06/01_raii_example.cpp
smartp1:
	cd ../../build && \
	g++ -Wall -o 6_smartp1 ../src/Lesson_06/6_6_practice_smart_pointers.cpp

.PHONY: debug
debug:
	mkdir -p build
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=debug .. && \
	make

.PHONY: clean
clean:
	rm -rf build
