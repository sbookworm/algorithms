all: node.cpp red_black_tree.cpp main.cpp
	g++ node.cpp red_black_tree.cpp main.cpp -g -o main.out
	valgrind --tool=memcheck --leak-check=full ./main.out
clean:
	rm main.out
