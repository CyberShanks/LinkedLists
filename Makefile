test: misc.o driver.o linkedlist.o
	gcc -o lltest misc.o linkedlist.o driver.o

misc.o: misc.c
	gcc -c misc.c

ll: linkedlist.o driver.o
	gcc -o ll linkedlist.o driver.o

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

driver.o: driver.c
	gcc -c driver.c

misc: misc.c
	gcc -o save misc.c

clean:
	rm -f *.o