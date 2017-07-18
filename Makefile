CC=gcc
CFLAGS=-I.
DEPS = phonebook.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

phonebook: phonebook.o 
	gcc -o phonebook phonebook.o -I.
	

