#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDE 6
#define MINDE 1
#define MAXTABLE 8
#define MAXJOUEUR 7

typedef struct Element Element;
typedef struct Liste Liste;
typedef struct Joueur Joueur;
typedef struct Pile Pile;
typedef struct ListeNOM ListeNOM;
struct ListeNOM
{
    char nom[15];
    int score;
};
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
    Element *elt;
};

struct Joueur
{
    char nom[15];
    Element *pickominos;
    int table_joueur[8];
    int score;
};

void init(Liste *, int);
void affichepicko(Liste *);
int *lancede(int, int *);
int majTableJoueur(int *, int, int, Joueur *, int);
void menu();
void initJoueur(Joueur *);
int quiCommence(int);
void viderBuffer();
void deroulementJeu(Liste *, Joueur *, int *, int, int);
int execJoueur(Joueur *, int, int *, int, Liste *);
void reInitTable(Joueur *);
int eligiblePicko(Joueur *);
void reInitPicko(Liste *);
int majPileJoueur(int, int, int, Joueur *, int, Liste *, int);
int verifInferieurProche(Liste *, int, int);
void rendrePicko(Liste *, Joueur *);
void affichePickosVisibles(Joueur *, int);
int comptElt(Liste *);
void comptPoints(Joueur *, int);
int execIA(Liste *, Joueur *, int, int, int *);
int majTableIA(int *, int, Joueur *);
void viderPickos(Liste *);
char *maj(Joueur *);
void lireScoreJoueur();
void sauvScore(Joueur *, int, FILE *);
void deliberation(Joueur *, int);