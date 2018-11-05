help:
	@echo "make help"
	@echo "make all"
ADT_llist.o:ADT_llist.c
	g++ -c ADT_llist.c
main.o:main.c
	g++ -c main.c
create_map.o:create_map.c
	g++ -c create_map.c
all:main.o ADT_llist.o create_map.o
	g++ -o path main.o ADT_llist.o
	g++ -o map create_map.o
run:all
	./path
	./map
	firefox gps.html
clean:
	rm -rf *.o *.in *.swp *.html path map