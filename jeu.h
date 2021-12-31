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
    Element *premier;
};

struct Joueur
{
    char nom[15];
    Pile *pickominos;
    int table_joueur[8];
    int score;
};

Liste *init();
void affichepicko(Liste *);
int *lancede(int, int *);
int majTableJoueur(int *, int, int, Joueur *);
void menu();
Joueur *initJoueur(Joueur *, char *);
int quiCommence(int);
void viderBuffer();