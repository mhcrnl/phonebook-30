#include <stdio.h>
#include <stdlib.h>

/* It is important that you define a typedef first */
typedef struct Element Element;
typedef struct Liste Liste;

struct Element{
    int val;
    Element *succ;
};

struct Liste{
    Element *tete;
    int taille;
};

Liste * init_liste(){
    Liste *l;
    l = (Liste*)malloc(sizeof(Liste));
    l->tete = NULL;
    l->taille = 0;
    return l;
}

/* inserer un ele au debut de la liste */
void ajout_d(Liste *l, int val){
    Element *tmp;
    tmp = (Element*)malloc(sizeof(Element));
    tmp->val = val;
    tmp->succ = l->tete;
    l->tete = tmp;
    l->taille += 1;
}

/* inserer un ele a la fin de la liste */
void ajout_f(Liste *l, int val){
    if (l->taille == 0) ajout_d(l, val);
    else{
        Element *tmp, *queue;
        tmp = (Element*)malloc(sizeof(Element));
        tmp->val = val;
        tmp->succ = NULL;
        queue = l->tete;
        while (queue->succ != NULL){
            queue = queue->succ;
        }
        queue->succ = tmp;
        l->taille += 1;
    }
}

/* inserer un ele dans une pos quelconque */
void ajout_p(Liste *l, int val, int pos){
    if (pos == 0) ajout_d(l, val);
    else{
        Element *tmp, *tmp2;
        tmp = (Element*)malloc(sizeof(Element));
        tmp->val = val;
        tmp2 = l->tete;
        int i;
        for (i=1; i<=pos-1; i++){
            tmp2 = tmp2->succ;
        }
        tmp->succ = tmp2->succ;
        tmp2->succ = tmp;
        l->taille += 1;
    }
}

/* supprimer un ele au debut de la liste */
int supp_d(Liste *l){
    Element *tmp;
    tmp = l->tete;
    l->tete = l->tete->succ;
    int val = tmp->val;
    free(tmp);
    l->taille -= 1;
    return val;
}

/* supprimer un ele à la fin de la liste */
int supp_f(Liste *l){
    if (l->taille == 1){
        return supp_d(l);
    }else{
        Element *tmp, *tmp2;
        tmp2 = l->tete;
        int i;
        for (i=1; i<=l->taille-2; i++){
            tmp2 = tmp2->succ;
        }
        tmp = tmp2->succ;
        tmp2->succ = NULL;
        int val = tmp->val;
        free(tmp);
        l->taille -= 1;
        return val;
    }
}

/* supprimer un ele dans la pos quelconque */
int supp_p(Liste *l, int pos){
    if (pos == 0) return supp_d(l);
    else{
        Element *tmp, *tmp2;
        tmp2 = l->tete;
        int i;
        for (i=1; i<=pos-1; i++){
            tmp2 = tmp2->succ;
        }
        tmp = tmp2->succ;
        tmp2->succ = tmp->succ;
        int val = tmp->val;
        free(tmp);
        l->taille -= 1;
        return val;
    }
}

/* afficher tous les ele dans la liste */
void affic_liste(Liste *l){
    printf("\nTete -> ");
    Element *tmp;
    tmp = l->tete;
    while (tmp != NULL){
        printf("[%d] -> ", tmp->val);
        tmp = tmp->succ;
    }
    printf("NULL\n");
}

/* détruire tous les ele dans la liste */
void dest_liste(Liste *l){
    while(l->taille > 0){
        supp_d(l);
    }
}

main(){
    Liste *l;

    l = init_liste();
    affic_liste(l);

    ajout_d(l, 7);
    affic_liste(l);

    ajout_d(l, -5);
    affic_liste(l);

    ajout_d(l, 23);
    affic_liste(l);

    ajout_f(l, -1);
    affic_liste(l);

    ajout_f(l, 31);
    affic_liste(l);

    ajout_p(l, -12, 2);
    affic_liste(l);

    ajout_p(l, -2, 4);
    affic_liste(l);

    supp_p(l, 3);
    affic_liste(l);

    supp_d(l);
    affic_liste(l);

    supp_f(l);
    affic_liste(l);

    dest_liste(l);
    affic_liste(l);
}
