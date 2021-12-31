#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "jeu.h"

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

int *lancede(int nombrede, int *tablede)
{
    /*nombrede est le nombre de dé qu'il lui reste à lancer*/
    srand(time(NULL));
    int i, tirage;
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
    }

    return (tablede);
}

int majTableJoueur(int *tablede, int taille_tablede, int choix_joueur, Joueur *joueur)
{
    int c = 1, j = MAXTABLE - taille_tablede; // c va servir à vérifier si le joueur continue son tour ou pas
    for (int i = 0; i < MAXTABLE; i++)
    {
        if (choix_joueur == joueur->table_joueur[i])
        {
            c = -1;
            return c; // on sort de la fonction si le joueur comporte déjà la valeur qu'il a choisi sur la table
        }
    }

    c = 1;
    for (int i = 0; i < taille_tablede; i++)
    {
        if (choix_joueur == tablede[i])
        {
            joueur->table_joueur[j] = choix_joueur;
            c = 1;
            j += 1;
        }
    }

    if (j == (MAXTABLE - taille_tablede))
    {
        c = -1;
    }

    return c; // c vaudra -1 si el choix du joueur ne figure pas dans la table de dé proposée. Il passera alors son tour
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
    Element *sentinelle = malloc(sizeof(*sentinelle));

    if (picko == NULL || vingt_un == NULL)
    {
        exit(EXIT_FAILURE);
    }
    picko->premier = vingt_un;
    picko->dernier = trente_six;
    sentinelle->valeur = 0;
    sentinelle->point = 0;
    sentinelle->suivant = vingt_un;
    sentinelle->precedent = trente_six;
    vingt_un->valeur = 21;
    vingt_un->point = 1;
    vingt_un->suivant = vingt_deux;
    vingt_un->precedent = sentinelle;
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
    trente_six->suivant = sentinelle;
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

void menu()
{
    printf("************************\n");
    printf("*       PICKOMINO      *\n");
    printf("************************\n\n");
    printf("1. Jouer contre IA\n");
    printf("2. Jouer en multijoueur\n");
    printf("3. Sortir\n");
}

Joueur *initJoueur(Joueur *joueur, char *nom)
{
    strcpy(joueur->nom, nom);
    joueur->score = 0;
    for (int i = 0; i < MAXTABLE; i++)
    {
        joueur->table_joueur[i] = 0;
    }

    joueur->pickominos = NULL;
    return joueur;
}

void deroulement_jeu(int choix_menu, Liste *pickos)
{
    char nom[15];
    int nbre_de_joueurs = 2, tour = 0, *tablede = malloc(MAXTABLE * sizeof(int)), nbrede = 8, choix_joueur = 0, verif = 0, j = 0, i = 0, total_val = 0;
    Joueur *joueur = malloc(sizeof(*joueur));
    switch (choix_menu)
    {
    case 1:
        printf("Entrez le nom du joueur: ");
        scanf("%s", nom);
        joueur = initJoueur(joueur, nom);
        tour = 1; // quiCommence(nbre_de_joueurs);
        while (pickos->premier != NULL)
        {
            if (tour == 1)
            {
                printf("\nAu tour de %s de jouer\n", joueur->nom);
                while (nbrede > 0)
                {
                    printf("\nVotre table -> [ ");
                    i = 0;
                    while (joueur->table_joueur[i] != 0)
                    {
                        printf("%d ", joueur->table_joueur[i]);
                        i++;
                    }

                    printf("]\n");
                    printf("Appuyez sur ENTRER pour lancer les des\n");
                    system("pause");
                    tablede = lancede(nbrede, tablede);
                    printf("\nQuel numero gardez-vous ? (V -> numero 6): ");
                    scanf("%d", &choix_joueur);
                    verif = majTableJoueur(tablede, nbrede, choix_joueur, joueur);
                    if (verif == -1)
                    {
                        printf("\nVous avez choisi une valeur de de que vous avez deja ou qui n'existe pas. Votre tour s'arrete.\nVeuillez appuyer sur ENTRER");
                        getchar();
                        tour++;
                        nbrede = 0;
                    }
                    else
                    {
                        j = 0;
                        while (joueur->table_joueur[j] != 0)
                        {
                            j++;
                        }

                        nbrede = MAXTABLE - j;
                        if (nbrede == 0)
                        {
                            j = 0;
                            total_val = 0;
                            while (j < 8)
                            { // On prend le total de tous les lancés de dé
                                total_val += joueur->table_joueur[j];
                                j++;
                            }

                            if (pickos->premier->valeur == 0)
                            {
                                pickos->premier = pickos->premier->suivant;
                            }

                            verif = -1;
                            while (pickos->premier->valeur != 0 || verif == 1)
                            {
                                if (total_val == pickos->premier->valeur)
                                {
                                    joueur->pickominos->premier = pickos->premier;
                                    pickos->premier->precedent->suivant = pickos->premier->suivant;
                                    pickos->premier->suivant->precedent = pickos->premier->precedent;
                                    verif = 1;
                                }
                                else
                                {
                                    pickos->premier = pickos->premier->suivant;
                                }
                            }

                            if (verif == -1)
                            { // Verif vaut -1 si aucun pickomino n'a été alloué au joueur, sinon, il vaut 1
                                printf("\nVotre total ne correspond à aucun pickomino.");
                                tour++;
                            }
                            else
                            {
                                printf("\nVos pickos -> [ ");
                                i = 0;
                            }

                            if (tour > 2)
                            {
                                tour = 1;
                            }
                        }
                    }
                }
            }
        }
        free(joueur);
        break;

    default:
        break;
    }

    free(tablede);
}

int quiCommence(int nbre_de_joueurs)
{ // on tire aléatoirement un nombre entre 1 et le nombre de joueurs, les joueurs ayant chacun choisi un nombre. Celui qui a le nombre est tiré au sort commence
    int n = 0;
    srand(time(NULL));
    n = rand() % nbre_de_joueurs + 1;
    return n;
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

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}