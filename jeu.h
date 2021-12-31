#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDE 6
#define MINDE 1
#define MAXTABLE 8

typedef struct Element Element;
typedef struct Liste Liste;
typedef struct Joueur Joueur;
typedef struct Pile Pile;
struct Element
{
    int valeur;
    int point;
    Element *suivant;
    Element *precedent;
};

struct Liste
{
    Element *premier;
    Element *dernier;
};

struct Pile
{
    Element *dernier;
};

struct Joueur
{
    char *nom;
    Pile *pickominos;
    int table_joueur[8];
    int score;
};

Liste *init();
void affichepicko(Liste *);
int *lancede(int);
int majTableJoueur(int *, int, int, Joueur *);
void menu();
Joueur *initJoueur(Joueur *, char *);
void sauv_score(int score1 , int score2) ;
void lire_score_joueur(void) ;
