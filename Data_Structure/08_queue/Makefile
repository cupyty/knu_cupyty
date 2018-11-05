chart.o:chart.c
	g++ -c chart.c
ADT_queue.o:ADT_queue.c
	g++ -c ADT_queue.c
main.o:main.c
	g++ -c main.c
all:ADT_queue.o main.o chart.o
	g++ -o queue ADT_queue.o main.o chart.o
run:all
	./queue > chart.html
clean:
	rm -rf *.o queue

