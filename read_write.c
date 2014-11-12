#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Element Element;
typedef struct List List;
typedef struct Contact Contact;

struct Contact
{
    char firstName[20], lastName[20], phoneNumber[20];
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
//initialize list which is container of whole program
List *l;


// void add(Contact val){
//     Element *tmp;
//     tmp = (Element*)malloc(sizeof(Element));
//     strcpy(tmp->val.firstName, val.firstName);
//     strcpy(tmp->val.lastName, val.lastName);
//     strcpy(tmp->val.phoneNumber, val.phoneNumber);
//     tmp->tail = l->head;
//     l->head = tmp;
//     l->size += 1;
// }

void add(Contact val){
    if (l->size == 0) {
	    Element *tmp;
	    tmp = (Element*)malloc(sizeof(Element));    
	    strcpy(tmp->val.firstName, val.firstName);
	    strcpy(tmp->val.lastName, val.lastName);
	    strcpy(tmp->val.phoneNumber, val.phoneNumber);
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
        tmp->tail = NULL;
        queue = l->head;
        while (queue->tail != NULL){
            queue = queue->tail;
        }
        queue->tail = tmp;
        l->size += 1;
    }
}

void delete(int pos){
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

void deleteList(){
    while(l->size > 0){
        Element *tmp;
    	tmp = l->head;
	    l->head = l->head->tail;
	    free(tmp);
	    l->size -= 1;
    }
}

void showList(){
    printf("head -> \n");
    
    Element *tmp;
    tmp = l->head;

    while (tmp != NULL){
        printf("[%s, %s, %s] -> \n", tmp->val.firstName, tmp->val.lastName, tmp->val.phoneNumber);
        tmp = tmp->tail;
    }
    printf("NULL\n");
}

void writeIntoFile() {

	Element *tmp;
    tmp = l->head;

    FILE *file;
    char *fileName;
    fileName = "phonebook.txt";
    file = fopen(fileName, "w+");

    while (tmp != NULL){
        fputs(tmp->val.firstName, file);
    	fputs("|", file);
    	fputs(tmp->val.lastName, file);
    	fputs("|", file);
    	fputs(tmp->val.phoneNumber, file);
    	fputs("|\n", file);
        tmp = tmp->tail;
    }

    fclose(file);
}

void readIntoList() {

  	Contact example;
  	FILE *file;
    char *fileName;
    fileName = "phonebook.txt";
    file = fopen(fileName, "r");
    char content[100];
    char str[50];

    while (fgets(content, 100, file) != NULL) {
    	strcpy(str,content);
	  	char * pch;
  		char splitted_string[3][20];
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
    	add(example);
    }
    fclose(file);
}


int main() {


    FILE *file;
    
    char *fileName;

    fileName = "phonebook.txt";

    file = fopen(fileName, "a");

    l = initList();

    readIntoList();


    Contact example;
    
    strcpy(example.firstName, "ab");
    strcpy(example.lastName, "bc");
    strcpy(example.phoneNumber, "cca");
    
    add(example);


    //delete(2);
    
    //deleteList();

    showList();
    
    writeIntoFile();




    //showList();
    return(0);
}



















