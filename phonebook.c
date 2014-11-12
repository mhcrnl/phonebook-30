#include <stdio.h>
#include <stdlib.h>

//Global variable
int OPTION;

typedef struct Contact Contact;
typedef struct Element Element;
typedef struct List List;

struct Contact {
  char firstName[20], lastName[20], phoneNumber[20];
};

struct Element {
    Contact data;
    Element *tail;
};

struct List {
    Element *head;
    int size;
};



void menu() {
	
	printf("\n*****************************************\n\n");
	printf("*\tPossible Option\t\t\t*\n");
	printf("*\t1. Add a new contact\t\t*\n");
	printf("*\t2. Exit the program\t\t*\n");
	printf("\n*****************************************\n\n");
	printf("Choose an operation[1-2]: ");
	scanf("%d", &OPTION);
}

void addNewContact() {
	
	Contact new_contact;
	
	printf("\nNew Contact\n");
	printf("Input your last name: ");
	scanf("%s", new_contact.firstName);
	printf("Input your first name: ");
	scanf("%s", new_contact.lastName);
	printf("Input your phone number: ");
	scanf("%s", new_contact.phoneNumber);
	
	writeIntoFile(new_contact);
}

void choose(OPTION) {

	switch (OPTION) {
		case 1: addNewContact(); break;
		case 2: printf("2\n");; break;
		// case item: statements; break;
		default: printf("No this option\n");; break;
	}
} 

//Program run from here

int main() {
	
	printf("Welcome!!!\n");

	menu();
	choose(OPTION);

	printf("\nGood bye!!!\n");
	return 0;
}










