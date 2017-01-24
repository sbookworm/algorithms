all: node.cpp avl_tree.cpp main.cpp
	g++ node.cpp avl_tree.cpp main.cpp -g -o main.out
	valgrind --tool=memcheck --leak-check=full ./main.out
clean:
	rm main.out
