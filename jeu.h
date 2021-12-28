#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char nom[10];
    Pile *pickominos;
    int *table_joueur;
    int score;
};

Liste *init();
void affichepicko(Liste *);
int *lancede(int);
