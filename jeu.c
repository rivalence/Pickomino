#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jeu.h"
#define MAXDE 6
#define MINDE 1

/*int de()
{
    int max, min, tirage;
    srand(time(NULL));
    max = 6;
    min = 1;
    tirage = min + (rand() % (max + 1 - min));
    printf("%d", tirage);
    return tirage;
}*/

int *lancede(int nombrede)
{
    /*nombrede est le nombre de dé qu'il lui reste à lancer*/
    srand(time(NULL));
    int i, tirage;
    int *tablede;
    tablede = malloc(nombrede * sizeof(int));
    for (i = 0; i < nombrede; i++)
    {
        tirage = rand() % MAXDE + MINDE;
        tablede[i] = tirage;
        if (tirage == 6)
        {
            printf("de%d = V ", i);
        }
        else
        {
            printf("de%d = %d ", i, tirage);
        }
        /*printf("tableau[%d] = %d\n",i, tablede[i-1]);*/
    }

    return (tablede);
}

int majTableJoueur(int *tablede, int choix_joueur, Joueur *joueur)
{
    int c; // va servir à vérifier si le joueur continue son tour ou pas
    while (tablede)
    {
        if (choix_joueur == *tablede)
        {
            while (joueur->table_joueur)
            {
                if (choix_joueur == joueur->table_joueur)
                {
                    c = -1;
                    break;
                }
                else
                {
                    joueur->table_joueur = &joueur->table_joueur + 1;
                    c = 0;
                }
            }
        } // A revoir
    }
}

Liste *init()
{ /*au final faudra une doublement chainee*/
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
    picko->premier = vingt_un;
    picko->dernier = trente_six;
    vingt_un->valeur = 21;
    vingt_un->point = 1;
    vingt_un->suivant = vingt_deux;
    vingt_un->precedent = picko->dernier;
    vingt_deux->valeur = 22;
    vingt_deux->point = 1;
    vingt_deux->suivant = vingt_trois;
    vingt_deux->precedent = vingt_un;
    vingt_trois->valeur = 23;
    vingt_trois->point = 1;
    vingt_trois->suivant = vingt_quatre;
    vingt_trois->precedent = vingt_deux;
    vingt_quatre->valeur = 24;
    vingt_quatre->point = 1;
    vingt_quatre->suivant = vingt_cinq;
    vingt_quatre->precedent = vingt_trois;
    vingt_cinq->valeur = 25;
    vingt_cinq->point = 2;
    vingt_cinq->suivant = vingt_six;
    vingt_cinq->precedent = vingt_quatre;
    vingt_six->valeur = 26;
    vingt_six->point = 2;
    vingt_six->suivant = vingt_sept;
    vingt_six->precedent = vingt_cinq;
    vingt_sept->valeur = 27;
    vingt_sept->point = 2;
    vingt_sept->suivant = vingt_huit;
    vingt_sept->precedent = vingt_six;
    vingt_huit->valeur = 28;
    vingt_huit->point = 2;
    vingt_huit->suivant = vingt_neuf;
    vingt_huit->precedent = vingt_sept;
    vingt_neuf->valeur = 29;
    vingt_neuf->point = 3;
    vingt_neuf->suivant = trente;
    vingt_neuf->precedent = vingt_huit;
    trente->valeur = 30;
    trente->point = 3;
    trente->suivant = trente_un;
    trente->precedent = trente_deux;
    trente_un->valeur = 31;
    trente_un->point = 3;
    trente_un->suivant = trente_deux;
    trente_un->precedent = trente;
    trente_deux->valeur = 32;
    trente_deux->point = 3;
    trente_deux->suivant = trente_trois;
    trente_deux->precedent = trente_un;
    trente_trois->valeur = 33;
    trente_trois->point = 4;
    trente_trois->suivant = trente_quatre;
    trente_trois->precedent = trente_deux;
    trente_quatre->valeur = 34;
    trente_quatre->point = 4;
    trente_quatre->suivant = trente_cinq;
    trente_quatre->precedent = trente_trois;
    trente_cinq->valeur = 35;
    trente_cinq->point = 4;
    trente_cinq->suivant = trente_six;
    trente_cinq->precedent = trente_quatre;
    trente_six->valeur = 36;
    trente_six->point = 4;
    trente_six->suivant = picko->premier;
    trente_six->precedent = trente_cinq;

    return picko;
}

void affichepicko(Liste *pickos)
{
    Element *e = pickos->premier;
    do
    {
        printf(" __ ");
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        printf("|%d|", e->valeur);
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        printf(" __ ");
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        printf("|%.2d|", e->point);
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        printf(" __ ");
        e = e->suivant;
    } while (e != pickos->premier);
}

int choix_joueur(void)
{
    int *reslancede;
    int nbrede_de_restant;
    nbrede_de_restant = 8;
    reslancede = lancede(&nbrede_de_restant);

    return (0);
}

void rendre_picko(Liste *plateau, Element *picko)
{
    /*vu que je n'ai pas encore de listes doublement chainées, je vais rajoutter en debut de liste*/
    /*picko = malloc(sizeof(picko));*/
    if (plateau == NULL || picko == NULL)
    {
        exit(EXIT_FAILURE);
    }
    picko->suivant = plateau->premier;
    plateau->premier = picko;
}

void retirer_picko(Liste *plateau)
{
    if (plateau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    /*...*/
}

/*void afficherListe(Liste *liste)
{
    int i = 0;
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->valeur);
        actuel = &(actuel->suivant);
    }
    printf("NULL\n");
}*/
