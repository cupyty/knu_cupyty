ADT_tree.o:ADT_tree.c
	g++ -c ADT_tree.c
main.o:main.c
	g++ -c main.c
all:ADT_tree.o main.o
	g++ -o tree ADT_tree.o main.o
run:all
	./tree
clear:
	rm -rf ADT_tree.o main.o tree