#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////////////////
//////////////////// STRUCTURA CONTACT //////////////
/////////////////////////////////////////////////////
typedef struct Contact {
    int id;
    char firstName[20];
    char lastName[20];
    char phoneNumber[13];
    char email[40];
} Contact;
/**
    Variabile globale
*/
char OPTION;
//////////////////////////////////////////////////////////////
//////////////////////// menu() /////////////////////////////
////////////////////////////////////////////////////////////
void menu(){
    printf (" ****** Meniul Aplicatiei *******\n ");
    printf ("1. Adauga contact \n");
    printf ("2. Afiseaza contact \n");
    printf ("3. Iesirea din program \n");
    printf ("4. Iesirea din program \n");
    printf ("0. Push codul pe GITHUB \n");
    printf("Alege o operatie [1-7]: ");
    scanf("%c", &OPTION );
}
//////////////////////////////////////////////////////////////
///////////////////// runProgram(char OPTION) ///////////////
////////////////////////////////////////////////////////////
int runProgram(char OPTION){
    char answer;
    switch(OPTION){
        case '1':
            return 1;
        case '2':
            break;
        case '3':
            break;
        case '4':
            exit(0);
            break;
        case '0':
            system("./gitpush.sh");
            return 0;
        default:
            printf("Alegerea dvs. nu este in meniu.");
            break;
    }

}

int main(){
    printf("**Aplicatia agenda telefonica**");
    int ret;
    do{
        menu();
        ret = runProgram(OPTION);
    }while(ret == 1);

	return 0;
}

