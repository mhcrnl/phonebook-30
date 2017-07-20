CC=gcc
CFLAGS=-I.
DEPS = phonebook01.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

phonebook01: phonebook01.o 
	gcc -o phonebook01 phonebook01.o -I.
	

