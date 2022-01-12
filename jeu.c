#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "jeu.h"

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

int majTableJoueur(int *tablede, int taille_tablede, int choix_joueur, Joueur *joueur, int nbrede)
{
    int c = 1, j = MAXTABLE - taille_tablede; // c va servir à vérifier si le joueur continue son tour ou pas
    printf("Appuyez sur ENTRER pour lancer les des\n");
    getch();
    tablede = lancede(nbrede, tablede);
    printf("\nQuel numero gardez-vous ? (V -> numero 6): ");
    scanf("%d", &choix_joueur);
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

    if (j == (MAXTABLE - taille_tablede)) // on renvoie un booléen négatif si la valeur choisie par le joueur n'existe pas dans les valeurs des dés
    {
        c = -1;
    }

    return c; // c vaudra -1 si le choix du joueur ne figure pas dans la table de dé proposée. Il passera alors son tour
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

void initJoueur(Joueur *joueur, Pile *pickominos)
{
    joueur->score = 0;
    for (int i = 0; i < MAXTABLE; i++)
    {
        joueur->table_joueur[i] = 0;
    }

    joueur->pickominos = pickominos;
    joueur->pickominos->premier->valeur = 0;
    joueur->pickominos->premier->point = 0;
    joueur->pickominos->premier->precedent = NULL;
    joueur->pickominos->premier->suivant = NULL;
}

void reInitTable(Joueur *joueur)
{ // On remet la table du joueur à 0
    for (int i = 0; i < MAXTABLE; i++)
    {
        joueur->table_joueur[i] = 0;
    }
}

int eligiblePicko(Joueur *joueur)
{
    int v = 0, i = 0;
    while (i < 8)
    {
        if (joueur->table_joueur[i] == 6)
        {
            v++;
            return v;
        }
        else
        {
            i++;
        }
    }

    return v;
}

int execJoueur(Joueur *joueur, int tour, int nbrede, int *tablede, int nbre_de_joueurs, Liste *pickos)
{
    int choix_joueur = 0, verif = 0, total_val = 0, i = 0, j = 0, compt = 0, accepteLance = 1, vers = 0;
    char validLance;

    affichepicko(pickos);
    printf("\n\nAu tour de %s de jouer\n", joueur[tour - 1].nom);
    while (nbrede > 0)
    {
        printf("\nVotre table -> [ ");
        i = 0;
        while (joueur[tour - 1].table_joueur[i] != 0)
        {
            if (joueur[tour - 1].table_joueur[i] == 6)
            {
                printf("V ");
                i++;
            }
            else
            {
                printf("%d ", joueur[tour - 1].table_joueur[i]);
                i++;
            }
        }

        printf("]\n");
        if (compt == 0)
        {
            verif = majTableJoueur(tablede, nbrede, choix_joueur, &joueur[tour - 1], nbrede);
            compt++;
        }
        else
        {
            printf("\nVoulez-vous relancer vos des ?: [O/N] :");
            scanf("%c", &validLance);
            while (validLance != "O" && validLance != "o" && validLance != "n" && validLance != "N")
            { // test de validité de l'entrée du joueur
                printf("Repondez par O (oui) ou N (non): ");
                scanf("%c", &validLance);
            }

            if (validLance == "o" || validLance == "O")
            {
                verif = majTableJoueur(tablede, nbrede, choix_joueur, &joueur[tour - 1], nbrede);
            }
            else
            { // si le joueur entre N (pour ne plus lancer de dé), accepteLance vaut 1 et on compte le total de sa table.
                nbrede = 0;
                accepteLance = 1;
            }
        }

        if (verif == -1) // Mauvais choix du joueur, on passe son tour
        {
            printf("\nVous avez choisi une valeur de de que vous avez deja ou qui n'existe pas. Votre tour s'arrete.\nVeuillez appuyer sur ENTRER");
            getchar();
            tour++;
            nbrede = 0;
            reInitTable(&joueur[tour - 1]); // On remet la table du joueur à 0
        }
        else
        {
            j = 0;
            while (joueur[tour - 1].table_joueur[j] != 0)
            {
                j++;
            }

            nbrede = MAXTABLE - j;
            if (nbrede == 0 || accepteLance == 1)
            {
                vers = eligiblePicko(&joueur[tour - 1]);
                if (vers == 0)
                {
                    printf("\nVous ne comportez aucun vers dans votre table. Vous ne pouvez donc prendre aucun pickomino de la brochette.\nRestitution de votre pickomino visible...");
                    // appeler rendrePicko()
                    tour++;
                }
                else
                {
                    j = 0;
                    total_val = 0;
                    while (j < 8)
                    { // On prend le total de tous les lancés de dé
                        if (joueur[tour - 1].table_joueur[j] == 6)
                        {
                            joueur[tour - 1].table_joueur[j] = 5;
                        }
                        total_val += joueur[tour - 1].table_joueur[j]; // on rajoute à total_val la somme de ses lancés de dé
                        j++;
                    }

                    while (pickos->premier->valeur != 0) // On se positionne sur le premier élément de la liste des pickos
                    {
                        pickos->premier = pickos->premier->suivant;
                    }

                    pickos->premier = pickos->premier->suivant;
                    printf("\nPickominos visibles: \n"); // affichage du pickomino visible de chaque joueur
                    for (i = 0; i < nbre_de_joueurs; i++)
                    {
                        printf("%s -> [ %d ]\n", joueur[i].nom, joueur[i].pickominos->premier->valeur);
                    }

                    affichepicko(pickos);
                    printf("\nVOTRE TOTAL SUR LES LANCES -> %d", total_val);
                    if (total_val < 21 || total_val > 36)
                    { // Si le total est éligible ou pas au choix d'un pickomino
                        verif = 1;
                    }
                    else
                    {
                        verif = -1;
                    }
                    /*CHERCHER LES PICKOMINOS VISIBLES ET PROPOSER AU JOUEUR CE QU'IL PEUT OBTENIR.
                    LE CAS ECHEANT, PASSER SON TOUR*/

                    while (pickos->premier->valeur != 0 && verif == -1) // Fin des lancés de dés, on parcoure les pickominos et on vérifie si lee total du joueur fait qu'il en bénéficie d'un.
                    {
                        if (total_val == pickos->premier->valeur)
                        {
                            joueur[tour - 1].pickominos->premier = pickos->premier;
                            pickos->premier->precedent->suivant = pickos->premier->suivant;
                            pickos->premier->suivant->precedent = pickos->premier->precedent;
                            verif = 1; // Notre booléen prend la valeur un si un pickomino est attribué avec succès à un jour
                        }
                        else
                        {
                            pickos->premier = pickos->premier->suivant;
                        }
                    }

                    reInitTable(&joueur[tour - 1]); // On remet la table du joueur à 0
                    if (verif == -1)
                    { // Verif vaut -1 si aucun pickomino n'a été alloué au joueur, sinon, il vaut 1
                        printf("\nVotre total ne correspond à aucun pickomino.");
                        tour++;
                    }
                    else
                    {
                        tour++;
                    }
                }
            }
        }

        if (tour > nbre_de_joueurs)
        {
            tour = 1;
        }
    }

    return tour;
}

void deroulementJeu(Liste *pickos, Joueur *joueur, int *tablede, int nbre_de_joueurs, int choix_menu)
{
    int tour = 0, nbrede = 8;
    Pile *pickominos = malloc(nbre_de_joueurs * sizeof(*pickominos));

    for (int i = 0; i < nbre_de_joueurs; i++) // initialisation des données de chaque joueur
    {
        initJoueur(&joueur[i], &pickominos[i]);
        printf("Entrez le nom du joueur %d: ", i + 1);
        scanf("%s", joueur[i].nom);
    }

    tour = quiCommence(nbre_de_joueurs);

    if (nbre_de_joueurs == 2 && choix_menu == 1)
    {
        while (pickos->premier != NULL)
        {
            if (tour == 1)
            {
                tour = execJoueur(joueur, tour, nbrede, tablede, nbre_de_joueurs, pickos);
            }
        }
    }
    else
    {
        while (pickos->premier != NULL)
        {
            tour = execJoueur(joueur, tour, nbrede, tablede, nbre_de_joueurs, pickos);
        }
    }
}

void exec(int nbre_de_joueurs, Liste *pickos, int choix_menu)
{
    int *tablede = malloc(MAXTABLE * sizeof(int));
    Joueur *joueur = malloc(nbre_de_joueurs * sizeof(*joueur));

    deroulementJeu(pickos, joueur, tablede, nbre_de_joueurs, choix_menu);

    free(tablede);
    free(joueur);
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

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}