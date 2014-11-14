#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Element Element;
typedef struct List List;
typedef struct Contact Contact;

struct Contact
{
    char firstName[20], lastName[20], phoneNumber[20], sex[1], email[40], address[40];
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
void showList();
void writeIntoFile();
void readIntoList();

void menu();
void addNewContact();
void choose(int OPTION);


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

	menu();
	choose(OPTION);

	writeIntoFile();
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

void showList(){
    // printf("head -> \n");
    //
    // Element *tmp;
    // tmp = l->head;
    //
    // while (tmp != NULL){
    //     printf("[%s, %s, %s] -> \n", tmp->val.firstName, tmp->val.lastName, tmp->val.phoneNumber);
    //     tmp = tmp->tail;
    // }
    // printf("NULL\n");
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
    	fputs("|\n", file);
        tmp = tmp->tail;
    }

    fclose(file);
}

void readIntoList() {
  	Contact example;
  	FILE *file;
    char *fileName;
    fileName = "book.txt";
    file = fopen(fileName, "r");
    char content[100];
    char str[50];

    while (fgets(content, 100, file) != NULL) {
    	strcpy(str,content);
	  	char * pch;
  		char splitted_string[6][20];
  		pch = strtok (str,"|"); 
  		int index = 0;  
  		while (pch != NULL) {
    		strcpy(splitted_string[index],pch);
    		pch = strtok(NULL, "|");
    		index++;
  		}
    	strcpy(example.firstName, splitted_string[0]);
    	strcpy(example.lastName, splitted_string[1]);
    	strcpy(example.phoneNumber, splitted_string[2]);
		strcpy(example.sex, splitted_string[3]);
		strcpy(example.email, splitted_string[4]);
		strcpy(example.address, splitted_string[5]);
    	addToList(example);
    }
	
    fclose(file);
}

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
	scanf("%s", new_contact.address);
	
	addToList(new_contact);
}

void choose(OPTION) {
	switch (OPTION) {
		case 1:
			addNewContact();
			menu();
			break;
		case 2:
			printf("\nGood bye!!!\n");
			break;
		// case item:
		// 	statements;
		// 	break;
		default:
			printf("\nNo this option\n");
			printf("Troy to choose another option again please\n");
			menu();
			break;
	}
} 











