test: saver.o driver.o linkedlist.o
	gcc -o lltest saver.o linkedlist.o driver.o

saver.o: saver.c
	gcc -c saver.c

ll: linkedlist.o driver.o
	gcc -o ll linkedlist.o driver.o

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

driver.o: driver.c
	gcc -c driver.c

save: saver.c
	gcc -o save saver.c

clean:
	rm -f *.o