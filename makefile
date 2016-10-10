llinkedlist: linked-list.c
	gcc linked-list.c -o linked-list

clean:
	rm *~

run: linked-list
	./linked-list
