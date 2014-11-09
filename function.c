typedef struct list list;
typedef struct element element;
list *l,*s,*d,*undo,*redo;
struct element
{
char *desc;
char *tag;
char *task;
char *date;
char *priority;
char *state;
element *next;
};

struct list
{
    element *head,*tail;
    int num;
};


void create_file()
{FILE *file;
char *fname;
fname="write.txt";
file=fopen(fname,"w+");

}

list* init_list()
{list *l;
l=(list*)malloc(sizeof(list));
l->head=NULL;
l->tail=NULL;
l->num=0;
return(l);

}

void write_data_into_file(list *l) {

	element *tmp;
    tmp = l->head;

    FILE *file;
    char *fname;
    fname = "write.txt";
    file = fopen(fname, "w+");

    while (tmp != NULL){
        fputs(tmp->task, file);
    	fputs("|", file);
    	fputs(tmp->desc, file);
    	fputs("|", file);
    	fputs(tmp->date, file);
    	fputs("|", file);
        fputs(tmp->tag, file);
    	fputs("|", file);
    	fputs(tmp->priority, file);
    	fputs("|", file);
    	fputs(tmp->state, file);
    	fputs("|\n", file);
        tmp = tmp->next;

    }
    fclose(file);
}

void load_all_record_to_liste() {

  	//Record example;
  	FILE *file;
    char *fname;
    fname = "write.txt";
    file = fopen(fname, "r");
    char content[100];
    char str[50];

    while (fgets(content, 100, file) != NULL) {
    	strcpy(str,content);
	  	char * pch;
  		char splitted_string[6][30];
  		pch = strtok (str,"|");
  		int index = 0;
  		while (pch != NULL) {
    		strcpy(splitted_string[index],pch);
    		pch = strtok(NULL, "|");
    		index++;
  		}
    ajout_d(splitted_string[0],splitted_string[1],splitted_string[2],splitted_string[3],splitted_string[4],splitted_string[5]);
};
    fclose(file);
}



void ajout_d(char *str,char *str1,char *str2,char *str3,char *str4,char *sta,list *l){
    element *tmp;

    tmp = (element*)malloc(sizeof(element));
    tmp->task=str;
    tmp->desc=str1;
    tmp->date=str2;
    tmp->tag= str3;
    tmp->priority= sta;
    tmp->state=str4;


if(l->num>0)
{
     tmp->next = l->head;
}
else
{
    l->tail=tmp;
    tmp->next=NULL;}

    l->head = tmp;
    l->num += 1;
write_data_into_file(l);
}