ADT_llist.o:ADT_llist.c
	g++ -c ADT_llist.c
main.o:main.c
	g++ -c main.c
all:main.o ADT_llist.o
	g++ -o list main.o ADT_llist.o
	./list
clean:
	rm -rf *.o list