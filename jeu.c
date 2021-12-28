#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jeu.h"
#define MAXDE 6
#define MINDE 1 



typedef struct Element Element ; 
typedef struct Liste Liste ; 
struct Element
{
    int valeur ; 
    int point ; 
    Element *suivant ; 
};

struct Liste
{
    Element *premier ; 
};

int de(void){
    int max, min, tirage ; 
    srand(time(NULL));
    max = 6; 
    min = 1;
    tirage = min + (rand() % (max + 1 - min));
    printf("%d", tirage); 
    return tirage ;
}

int* lancede( int* nombrede){
    /*nombre est le nombrede de dé qu'il lui reste à lancer*/
    srand(time(NULL)) ; 
    int nombre , i , tirage ; 
    int * tablede ; 
    nombre = *nombrede ; 
    tablede = malloc(nombre * sizeof(int)) ; 
    for (i = 1; i <= nombre; i++)
    {
        tirage = MINDE + (rand() % MAXDE + 1 - MINDE); 
        tablede[i-1] = tirage ; 
        if (tirage == 6)
        {
            printf("de%d = V\n", i);
        }else{
            printf("de%d = %d\n", i,tirage);
        }
        /*printf("tableau[%d] = %d\n",i, tablede[i-1]);*/
    }
    
    return(tablede);
}

int affichepicko(void){
    /*A modifier les nombres ne doivent pas etre ecrits à la main mais par appelle d'un pointeurs ou d'une fonction  au cas ou un picko est retiré*/
    printf(" __  __  __  __  __  __  __  __  __  __  __  __  __  __  __  __\n");
    printf("|  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  ||  |\n");
    printf("|21||22||23||24||25||26||27||28||29||30||31||32||33||34||35||36|\n");
    printf("|__||__||__||__||__||__||__||__||__||__||__||__||__||__||__||__|\n");
    printf("| 1|| 1|| 1|| 1|| 2|| 2|| 2|| 2|| 3|| 3|| 3|| 3|| 4|| 4|| 4|| 4|\n");
    printf("|__||__||__||__||__||__||__||__||__||__||__||__||__||__||__||__|\n");

    
    return 0 ; 
}

void affunpicko(int valeur , int point){
    printf(" __ \n") ;
    printf("|  |\n") ; 
    printf("|%d|\n", valeur) ;
    printf("|__|\n") ;
    printf("| %d|\n", point) ;
    printf("|__|\n") ; 
}

int choix_joueur(void){
    int* reslancede ;
    int nbrede_de_restant; 
    nbrede_de_restant = 8 ;
    reslancede  = lancede(&nbrede_de_restant); 

    return(0) ;
}

Liste *init(void){/*au final faudra une doublement chainee*/
    Liste *picko = malloc(sizeof(*picko)); 
    Element *vingt_un = malloc(sizeof(*vingt_un));
    Element *vingt_deux = malloc(sizeof(*vingt_deux)); 
    Element *vingt_trois = malloc(sizeof(*vingt_trois));
    Element *vingt_quatre = malloc(sizeof(*vingt_quatre));
    Element *vingt_cinq = malloc(sizeof(*vingt_cinq));
    Element *vingt_six = malloc(sizeof(*vingt_six));
    Element *vingt_sept = malloc(sizeof(*vingt_sept));
    Element *vingt_huit = malloc(sizeof(*vingt_huit));
    Element *vingt_neuf = malloc(sizeof(*vingt_neuf));
    Element *trente = malloc(sizeof(*trente));
    Element *trente_un = malloc(sizeof(*trente_un));
    Element *trente_deux = malloc(sizeof(*trente_deux));
    Element *trente_trois = malloc(sizeof(*trente_trois));
    Element *trente_quatre = malloc(sizeof(*trente_quatre));
    Element *trente_cinq = malloc(sizeof(*trente_cinq));
    Element *trente_six = malloc(sizeof(*trente_six));




    if (picko == NULL || vingt_un == NULL)
    {
        exit(EXIT_FAILURE);
    }
    vingt_un -> valeur = 21 ; 
    vingt_un-> point = 1 ; 
    vingt_un ->suivant = &vingt_deux; 
    vingt_deux -> valeur = 22 ; 
    vingt_deux-> point = 1 ;
    vingt_deux ->suivant = &vingt_trois; 
    vingt_trois-> valeur = 23 ; 
    vingt_trois-> point = 1 ;
    vingt_trois ->suivant = &vingt_quatre ; 
    vingt_quatre -> valeur = 24 ; 
    vingt_quatre-> point = 1 ;
    vingt_quatre -> suivant= &vingt_cinq ; 
    vingt_cinq-> valeur = 25 ; 
    vingt_cinq-> point = 2 ;
    vingt_cinq ->suivant = &vingt_six;
    vingt_six -> valeur = 26 ; 
    vingt_six-> point = 2 ;
    vingt_six->suivant = &vingt_sept ; 
    vingt_sept-> valeur = 27 ; 
    vingt_sept-> point = 2 ;
    vingt_sept->suivant = &vingt_huit ; 
    vingt_huit -> valeur = 28 ; 
    vingt_huit-> point = 2 ;
    vingt_huit -> suivant = &vingt_neuf ; 
    vingt_neuf-> valeur = 29 ; 
    vingt_neuf-> point = 3 ;
    vingt_neuf ->suivant = &trente ; 
    trente -> valeur = 30 ; 
    trente-> point = 3 ;
    trente ->suivant = &trente_un ; 
    trente_un-> valeur = 31 ; 
    trente_un-> point = 3 ;
    trente_un ->suivant = &trente_deux ; 
    trente_deux -> valeur = 32 ; 
    trente_deux-> point = 3 ;
    trente_deux ->suivant = &trente_trois ; 
    trente_trois-> point = 33 ; 
    trente_trois-> point = 4 ;
    trente_trois -> suivant = &trente_quatre ; 
    trente_quatre -> valeur = 34 ; 
    trente_quatre-> point = 4 ;
    trente_quatre->suivant = &trente_cinq ; 
    trente_cinq-> point = 35 ; 
    trente_cinq-> point = 4 ;
    /*trente_cinq -> suivant = &trente_six ;*/ 
    trente_six -> valeur = 36 ;
    trente_six-> point = 4 ; 
    trente_six-> suivant = NULL;
    picko ->premier = vingt_un ; 

    return picko ; 
}

void rendre_picko (Liste *plateau , Element *picko ){
    /*vu que je n'ai pas encore de listes doublement chainées, je vais rajoutter en debut de liste*/
    /*picko = malloc(sizeof(picko));*/
    if (plateau == NULL || picko == NULL)
    {
        exit(EXIT_FAILURE); 
    }
    picko -> suivant = plateau->premier ; 
    plateau ->premier = picko ;
    
}

void retirer_picko(Liste *plateau){
   if (plateau == NULL)
    {
        exit(EXIT_FAILURE); 
    }
    /*...*/
}
void afficherListe(Liste *liste)
{
    int i = 0 ; 
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->valeur);
        actuel =& (actuel->suivant);
    }
    printf("NULL\n");
}

