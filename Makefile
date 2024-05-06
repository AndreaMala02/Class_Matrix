all: exe.out

exe.out: main.out class_matrix.out
	g++ main.out class_matrix.out -o exe.out

class_matrix.out: class_matrix.cpp class_matrix.h
	g++ -c class_matrix.cpp -o class_matrix.out

main.out: main.cpp
	g++ -c main.cpp -o main.out

run: 
	./exe.out

clear: 
	rm *.out

clear_out:
	rm output.txt