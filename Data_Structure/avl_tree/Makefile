AVL_tree.o:AVL_tree.c
	g++ -c AVL_tree.c
main.o:main.c
	g++ -c main.c
all:AVL_tree.o main.o
	g++ -o avl_tree AVL_tree.o main.o
	./avl_tree
run:all
	./avl_tree
clean:
	rm -rf *.o avl_tree