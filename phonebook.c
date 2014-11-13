#include <stdio.h>
#include <string.h>
#include <stdlib.h>l

typedef struct Element Element;
typedef struct List List;
typedef struct Contact Contact;

struct Contact
{
    char firstName[100], lastName[100], phoneNumber[100], sex[100], email[100], address[100];
};

struct Element{
    Contact val;
    Element *tail;
};

struct List{
    Element *head;
    int size;
};

List * initList(){
    List *l;
    l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;
    return l;
}

//Global variable
int OPTION; //the chosen option
List *l; //initialize list which is container of whole program

//Prototype of all the functions

void addToList(Contact val);
void deleteFromList(int pos);
void deleteAllFromList();
void writeIntoFile();
void readIntoList();

void displayByLastName();
void displayByFirstName();
void displayAllContacts();
void updateContact();
void deleteContact();

void menu();
void addNewContact();
void chooseOption(int OPTION);


///////////////////////////////////////////////
////////////////Program start//////////////////
///////////////////////////////////////////////

int main() {
    FILE *file;
    char *fileName;
    fileName = "book.txt";
    file = fopen(fileName, "a");
    l = initList();
    readIntoList();

	printf("Welcome!!!\n");

	while(1) {
        menu();
        chooseOption(OPTION);
	}

	return 0;
}

///////////////////////////////////////////////
////////////////Program end////////////////////
///////////////////////////////////////////////


void addToList(Contact val){
    if (l->size == 0) {
	    Element *tmp;
	    tmp = (Element*)malloc(sizeof(Element));
	    strcpy(tmp->val.firstName, val.firstName);
	    strcpy(tmp->val.lastName, val.lastName);
	    strcpy(tmp->val.phoneNumber, val.phoneNumber);
		strcpy(tmp->val.sex, val.sex);
		strcpy(tmp->val.email, val.email);
		strcpy(tmp->val.address, val.address);
	    tmp->tail = l->head;
	    l->head = tmp;
	    l->size += 1;
    }
    else{
        Element *tmp, *queue;
        tmp = (Element*)malloc(sizeof(Element));
	    strcpy(tmp->val.firstName, val.firstName);
	    strcpy(tmp->val.lastName, val.lastName);
	    strcpy(tmp->val.phoneNumber, val.phoneNumber);
		strcpy(tmp->val.sex, val.sex);
		strcpy(tmp->val.email, val.email);
		strcpy(tmp->val.address, val.address);
        tmp->tail = NULL;
        queue = l->head;
        while (queue->tail != NULL){
            queue = queue->tail;
        }
        queue->tail = tmp;
        l->size += 1;
    }
}

void deleteFromList(int pos){
    if (pos == 0) {
    	Element *tmp;
    	tmp = l->head;
	    l->head = l->head->tail;
	    free(tmp);
	    l->size -= 1;
    }
    else{
        Element *tmp, *tmp2;
        tmp2 = l->head;
        int i;
        for (i=1; i<=pos-1; i++){
            tmp2 = tmp2->tail;
        }
        tmp = tmp2->tail;
        tmp2->tail = tmp->tail;
        free(tmp);
        l->size -= 1;
    }
}

void deleteAllFromList(){
    while(l->size > 0){
        Element *tmp;
    	tmp = l->head;
	    l->head = l->head->tail;
	    free(tmp);
	    l->size -= 1;
    }
}

void displayAllContacts(){
     Element *tmp;
     tmp = l->head;
     int noContact = 1;

     while (tmp != NULL){
        printf("yes display all contacts\n"); //design interface of all contacts
        //sample interface: printf("[%s, %s, %s] -> \n", tmp->val.firstName, tmp->val.lastName, tmp->val.phoneNumber);
        noContact = 0;
        tmp = tmp->tail;
     }

    if (noContact) {
        printf("There are no contacts in your phone books!!!\n");
    }
}

void displayByLastName() {
    Element *tmp;
    char lastName[20];
    int notFound = 1;

    printf("\nInput the last name: ");
    scanf("%s", lastName);

    tmp = l->head;

    while (tmp != NULL) {
        if (strcmp(tmp->val.lastName, lastName) == 0) {
            printf("yes last contact found\n"); //design interface to display found contact
            notFound = 0;
        }
        tmp = tmp->tail;
    }

    if (notFound) {
        printf("Contact not found!!!\n");
    }
}

void displayByFirstName() {
    Element *tmp;
    char firstName[20];
    int notFound = 1;

    printf("\nInput the first name: ");
    scanf("%s", firstName);

    tmp = l->head;

    while (tmp != NULL) {
        if (strcmp(tmp->val.firstName, firstName) == 0) {
            printf("yes first contact found\n"); //design interface to display found contact
            notFound = 0;
        }
        tmp = tmp->tail;
    }

    if (notFound) {
        printf("Contact not found!!!\n");
    }
}

void writeIntoFile() {
	Element *tmp;
    tmp = l->head;

    FILE *file;
    char *fileName;
    fileName = "book.txt";
    file = fopen(fileName, "w+");

    while (tmp != NULL){
        fputs(tmp->val.firstName, file);
    	fputs("|", file);
    	fputs(tmp->val.lastName, file);
    	fputs("|", file);
    	fputs(tmp->val.phoneNumber, file);
    	fputs("|", file);
    	fputs(tmp->val.sex, file);
    	fputs("|", file);
    	fputs(tmp->val.email, file);
    	fputs("|", file);
    	fputs(tmp->val.address, file);
        tmp = tmp->tail;
    }

    fclose(file);
}

void readIntoList() {
  	Contact new_contact;
  	FILE *file;
    char *fileName;
    fileName = "book.txt";
    file = fopen(fileName, "r");
    char content[1000];
    char str[50];

    while (fgets(content, 1000, file) != NULL) {
    	strcpy(str,content);
	  	char * pch;
  		char splitted_string[6][100];
  		pch = strtok (str,"|");
  		int index = 0;
  		while (pch != NULL) {
    		strcpy(splitted_string[index],pch);
    		pch = strtok(NULL, "|");
    		index++;
  		}
    	strcpy(new_contact.firstName, splitted_string[0]);
    	strcpy(new_contact.lastName, splitted_string[1]);
    	strcpy(new_contact.phoneNumber, splitted_string[2]);
		strcpy(new_contact.sex, splitted_string[3]);
		strcpy(new_contact.email, splitted_string[4]);
		strcpy(new_contact.address, splitted_string[5]);

    	addToList(new_contact);
    }

    fclose(file);
}

void menu() {
	printf("\n*********************************************************\n\n");
	printf("*\tPossible Option\t\t\t\t\t*\n");
	printf("*\t1. Add a new contact\t\t\t\t*\n");
	printf("*\t2. Display all contacts\t\t\t\t*\n");
	printf("*\t3. Display contact(s) by last name\t\t*\n");
	printf("*\t4. Display contact(s) by first name\t\t*\n");
	printf("*\t5. Update a contact (by using phone number)\t*\n");
	printf("*\t6. Delete a contact (by using phone number)\t*\n");
	printf("*\t7. Exit the program\t\t\t\t*\n");
	printf("\n*********************************************************\n\n");
	printf("Choose an operation[1-7]: ");
	scanf("%d", &OPTION);
}

void addNewContact() {
	Contact new_contact;

	printf("\nNew Contact\n");
	printf("Input your last name: ");
	scanf("%s", new_contact.lastName);
	printf("Input your first name: ");
	scanf("%s", new_contact.firstName);
	printf("Input your phone number: ");
	scanf("%s", new_contact.phoneNumber);
	printf("Input your gender [M/F]: ");
	scanf("%s", new_contact.sex);
	printf("Input your email: ");
	scanf("%s", new_contact.email);
	printf("Input your address: ");
    fgets(new_contact.address, 100, stdin);
    fgets(new_contact.address, 100, stdin);

	addToList(new_contact);
}

void chooseOption(OPTION) {
	switch (OPTION) {
		case 1:
			addNewContact();
			break;
        case 2:
            displayAllContacts();
            break;
        case 3:
            displayByLastName();
		 	break;
        case 4:
            displayByFirstName();
            break;
		case 7:
			printf("\nGood bye!!!\n");
			writeIntoFile();
			exit(0);
			break;
        default:
			printf("\nNo this option\n");
			printf("Try to choose another option again please\n");
			break;
	}
}











