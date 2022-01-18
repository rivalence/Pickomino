#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
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
            printf("[V] ");
        }
        else
        {
            printf("[%d] ", tirage);
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

void init(Liste *picko, int liberer)
{ /*au final faudra une doublement chainee*/
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
    if (liberer == 1)
    {
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
        trente->precedent = vingt_neuf;
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
    }
    else
    {
        free(picko);
        free(vingt_un);
        free(vingt_deux);
        free(vingt_trois);
        free(vingt_quatre);
        free(vingt_cinq);
        free(vingt_six);
        free(vingt_sept);
        free(vingt_huit);
        free(vingt_neuf);
        free(trente);
        free(trente_un);
        free(trente_deux);
        free(trente_trois);
        free(trente_quatre);
        free(trente_cinq);
        free(trente_six);
    }
}

void affichepicko(Liste *pickos)
{
    Element *e = pickos->premier;
    do
    {
        if (e->valeur == 0)
        {
            e = e->suivant;
            continue;
        }
        printf(" __ ");
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        if (e->valeur == 0)
        {
            e = e->suivant;
            continue;
        }
        printf("|%d|", e->valeur);
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        if (e->valeur == 0)
        {
            e = e->suivant;
            continue;
        }
        printf(" __ ");
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        if (e->valeur == 0)
        {
            e = e->suivant;
            continue;
        }
        printf("|%.2d|", e->point);
        e = e->suivant;
    } while (e != pickos->premier);

    printf("\n");
    do
    {
        if (e->valeur == 0)
        {
            e = e->suivant;
            continue;
        }
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
    printf("3. Consulter les scores\n");
    printf("4. Sortir\n");
}

void initJoueur(Joueur *joueur)
{
    joueur->score = 0;
    for (int i = 0; i < MAXTABLE; i++)
    {
        joueur->table_joueur[i] = 0;
    }

    joueur->pickominos = NULL;
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

void reInitPicko(Liste *pickos)
{
    while (pickos->premier->valeur != 0) // On se positionne sur le premier élément de la liste des pickos
    {
        pickos->premier = pickos->premier->suivant;
    }

    pickos->premier = pickos->premier->suivant;
}

int execJoueur(Joueur *joueur, int tour, int *tablede, int nbre_de_joueurs, Liste *pickos)
{
    int choix_joueur = 0, verif = 0, total_val = 0, i = 0, j = 0, compt = 0, accepteLance = 1, vers = 0, choix_picko = 0, nbrede = 8;
    char validLance;

    reInitPicko(pickos);
    affichepicko(pickos);
    printf("\n\nAu tour de %s de jouer\n", joueur[tour - 1].nom);
    while (nbrede > 0)
    {
        affichePickosVisibles(joueur, nbre_de_joueurs);
        printf("\n\nVotre table -> [ "); // Affiche la table du joueur
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
        affichepicko(pickos);
        printf("\n");
        if (compt == 0)
        {
            verif = majTableJoueur(tablede, nbrede, choix_joueur, &joueur[tour - 1], nbrede);
            compt++;
        }
        else
        {
            printf("\nVoulez-vous relancer vos des ?: [O/N] :");
            validLance = getchar();
            while (validLance != 'O' && validLance != 'o' && validLance != 'n' && validLance != 'N')
            { // test de validité de l'entrée du joueur
                printf("Repondez par O (oui) ou N (non): ");
                validLance = getchar();
            }

            if (validLance == 'o' || validLance == 'O')
            {
                verif = majTableJoueur(tablede, nbrede, choix_joueur, &joueur[tour - 1], nbrede);
            }
            else
            { // si le joueur entre N (pour ne plus lancer de dé), accepteLance vaut 1 et on compte le total de sa table.
                nbrede = 0;
                accepteLance = 0;
            }
        }

        if (verif == -1) // Mauvais choix du joueur, on passe son tour
        {
            printf("\nVous avez choisi une valeur de de que vous avez deja ou qui n'existe pas. Votre tour s'arrete.\nRestitution de votre picnkomino visible en cours...\n");
            rendrePicko(pickos, &joueur[tour - 1]);
            nbrede = 0;
            reInitTable(&joueur[tour - 1]); // On remet la table du joueur à 0
            tour++;
        }
        else
        {
            j = 0;
            while (joueur[tour - 1].table_joueur[j] != 0)
            {
                j++;
            }

            nbrede = MAXTABLE - j;
            if (nbrede == 0 || accepteLance == 0)
            {
                vers = eligiblePicko(&joueur[tour - 1]);
                if (vers == 0)
                {
                    printf("\nVous ne comportez aucun vers dans votre table. Vous ne pouvez donc prendre aucun pickomino de la brochette.\nRestitution de votre pickomino visible...\n");
                    rendrePicko(pickos, &joueur[tour - 1]);
                    reInitTable(&joueur[tour - 1]); // On remet la table du joueur à 0
                    nbrede = 0;
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

                    affichePickosVisibles(joueur, nbre_de_joueurs);
                    reInitPicko(pickos);
                    affichepicko(pickos);
                    if (total_val < 21 || total_val > 36)
                    { // Si le total est éligible ou pas au choix d'un pickomino
                        verif = 0;
                    }
                    else
                    {
                        verif = -1;
                    }

                    printf("\nQuel pickomino souhaitez-vous prendre %s? :", joueur[tour - 1].nom);
                    scanf("%d", &choix_picko);
                    verif = majPileJoueur(total_val, choix_picko, tour, joueur, verif, pickos, nbre_de_joueurs); // On met à jour la pile du joueur (empile ou desempile)
                    reInitTable(&joueur[tour - 1]);                                                              // On remet la table du joueur à 0
                    if (verif == 0)
                    { // Verif vaut -1 si aucun pickomino n'a été alloué au joueur, sinon, il vaut 1
                        printf("\nVotre choix ne correspond a aucun pickomino eligible.\nRestitution de votre pickomino visible en cours...\n");
                        rendrePicko(pickos, &joueur[tour - 1]);
                        tour++;
                        nbrede = 0;
                    }
                    else
                    {
                        tour++;
                        nbrede = 0;
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

int execIA(Liste *pickos, Joueur *joueur, int tour, int nbre_de_joueurs, int *tablede)
{
    int nbrede = 8, i = 0, verif = 0, j = 0, total_val = 0, vers = 0, tab_inter[MAXTABLE];
    reInitPicko(pickos);
    affichepicko(pickos);
    printf("\n\nAu tour de %s de jouer\n", joueur[tour - 1].nom);
    while (nbrede > 0)
    {
        affichePickosVisibles(joueur, nbre_de_joueurs);
        printf("\n\nVotre table -> [ ");
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
        reInitPicko(pickos);
        affichepicko(pickos);
        printf("\n");
        verif = majTableIA(tablede, nbrede, &joueur[tour - 1]);
        Sleep(1500);
        if (verif != 1)
        {
            printf("\n%s passe son tour.\nRestitution de son pickomino visible en cours...\n", joueur[tour - 1].nom);
            reInitTable(&joueur[tour - 1]);
            rendrePicko(pickos, &joueur[tour - 1]);
            nbrede = 0;
            tour++;
        }
        else
        {
            j = 0;
            while (joueur[tour - 1].table_joueur[j] != 0)
            {
                j++;
            }

            nbrede = MAXTABLE - j;
            j = 0;
            total_val = 0;
            while (j < 8)
            { // On prend le total de tous les lancés de dé
                if (joueur[tour - 1].table_joueur[j] == 6)
                {
                    tab_inter[j] = 5;
                }
                else
                {
                    tab_inter[j] = joueur[tour - 1].table_joueur[j];
                }
                total_val += tab_inter[j]; // on rajoute à total_val la somme de ses lancés de dé
                j++;
            }

            reInitPicko(pickos);
            if ((total_val < pickos->dernier->valeur && total_val > pickos->premier->valeur)) // On arrête de lancer les dés de l'IA quand son total rentre dans la zone des pickominos
            {
                // diff = pickos->dernier->valeur - total_val;
                // if (diff < (nbrede * 5))
                //{
                vers = eligiblePicko(&joueur[tour - 1]); // Si sur sa table l'IA n'a pas de vers, on passe son tour
                if (vers == 0)
                {
                    printf("\n%s passe son tour.\nRestitution de son pickomino visible en cours...\n", joueur[tour - 1].nom);
                    rendrePicko(pickos, &joueur[tour - 1]);
                    nbrede = 0;
                    reInitTable(&joueur[tour - 1]);
                    tour++;
                }
                else
                {
                    verif = -1;
                    if (total_val == joueur[tour - 2].pickominos->valeur)
                    {
                        verif = majPileJoueur(total_val, total_val, tour, joueur, verif, pickos, nbre_de_joueurs); // L'IA empile le pickomino visible de l'adversaire
                        reInitTable(&joueur[tour - 1]);
                    }
                    else
                    {
                        reInitPicko(pickos);
                        while (total_val > pickos->premier->valeur && pickos->premier->valeur != 0)
                        { // On cherche si le total de l'IA correspond à un pickomino, sinon, à la valeur inférieur la plus proche
                            pickos->premier = pickos->premier->suivant;
                        }

                        if (total_val == pickos->premier->valeur)
                        { // On prend le pickomino correspondant
                            verif = majPileJoueur(total_val, total_val, tour, joueur, verif, pickos, nbre_de_joueurs);
                        }
                        else if (total_val < pickos->premier->valeur)
                        { // On prend le pickomino de valeur inférieure
                            total_val = pickos->premier->precedent->valeur;
                            verif = majPileJoueur(total_val, total_val, tour, joueur, verif, pickos, nbre_de_joueurs);
                        }

                        reInitTable(&joueur[tour - 1]);
                    }

                    if (verif != 1)
                    {
                        printf("\n%s passe son tour.\nRestitution de son pickomino visible en cours...\n", joueur[tour - 1].nom);
                        rendrePicko(pickos, &joueur[tour - 1]);
                        nbrede = 0;
                        reInitTable(&joueur[tour - 1]);
                        tour++;
                    }

                    nbrede = 0;
                    tour++;
                }
                //}
            }
        }
    }

    if (tour > nbre_de_joueurs)
    {
        tour = 1;
    }

    return tour;
}

int majTableIA(int *tablede, int nbrede, Joueur *joueur)
{
    int index_max = 0, j = 0, i = 0, taille_tab_ia = 0;
    tablede = lancede(nbrede, tablede);
    while (joueur->table_joueur[j] != 0)
    { // On prend le nombre d'éléments de la table de l'IA
        taille_tab_ia++;
        j++;
    }

    if (taille_tab_ia > 0)
    {
        do
        {
            while (i < nbrede)
            { // On prend le max des valeurs obtenues dans le lancé en s'assurant qu'elle n'existe pas dans la table de l'IA
                if (tablede[index_max] < tablede[i])
                {
                    index_max = i;
                    i++;
                }
                else
                {
                    i++;
                }
            }

            j = 0;
            while (joueur->table_joueur[j] != 0 && i != 0 && j < 8)
            {
                if (joueur->table_joueur[j] == tablede[index_max])
                { // si la valeur max est déjà dans la table de l'IA, on lui affecte la valeur 0 et on re-cherche le max
                    tablede[index_max] = 0;
                    index_max = 0;
                    i = 0;
                }
                else
                {
                    j++;
                }
            }
        } while (i == 0);
    }
    else
    {
        i = 0;
        while (i < nbrede)
        { // La table IA est vide, on prend simplement le max des dés
            if (tablede[index_max] < tablede[i])
            {
                index_max = i;
                i++;
            }
            else
            {
                i++;
            }
        }
    }

    if (tablede[index_max] != 0)
    { // on a bien un max qui est eligible et qu'on peut remplir dans la table IA
        for (i = 0; i < nbrede; i++)
        {
            if (tablede[index_max] == tablede[i])
            {
                joueur->table_joueur[taille_tab_ia] = tablede[index_max];
                taille_tab_ia++;
            }
        }
        printf("\n");
        return 1;
    }
    else
    {
        return -1;
    }
}

void affichePickosVisibles(Joueur *joueur, int nbre_de_joueurs)
{
    printf("\nPickominos visibles: \n"); // affichage du pickomino visible de chaque joueur
    for (int i = 0; i < nbre_de_joueurs; i++)
    {
        if (joueur[i].pickominos == NULL)
        {
            printf("%s -> [ ]\n", joueur[i].nom);
        }
        else
        {
            printf("%s -> [ %d ]\n", joueur[i].nom, joueur[i].pickominos->valeur);
        }
    }
}

int majPileJoueur(int total_val, int choix_picko, int tour, Joueur *joueur, int verif, Liste *pickos, int nbre_de_joueurs)
{
    int nbre_element_liste = 0;
    reInitPicko(pickos);
    if (verif == 0)
    { // le total des dés est une valeur erronée, on renvoie un booléan FALSE
        return verif;
    }

    nbre_element_liste = comptElt(pickos);
    while (pickos->premier->valeur != 0 && verif != 1) // Fin des lancés de dés, on parcoure les pickominos et on vérifie si lee total du joueur fait qu'il en bénéficie d'un.
    {
        if (choix_picko == pickos->premier->valeur && choix_picko == total_val) // séquence de changement quand la valeur exacte est choisie
        {
            if (nbre_element_liste == 2)
            {
                if (joueur[tour - 1].pickominos != NULL)
                {
                    joueur[tour - 1].pickominos->suivant = pickos->premier;
                    pickos->premier->precedent->suivant = NULL;
                    pickos->premier->precedent->precedent = NULL;
                    pickos->premier = pickos->premier->precedent;
                    joueur[tour - 1].pickominos->suivant->precedent = joueur[tour - 1].pickominos;
                    joueur[tour - 1].pickominos->suivant->suivant = NULL;
                    joueur[tour - 1].pickominos = joueur[tour - 1].pickominos->suivant;
                }
                else
                { // Quand le joueur prend son premier pickomino
                    joueur[tour - 1].pickominos = pickos->premier;
                    pickos->premier->precedent->suivant = NULL;
                    pickos->premier->precedent->precedent = NULL;
                    pickos->premier = pickos->premier->precedent;
                    joueur[tour - 1].pickominos->suivant = NULL;
                    joueur[tour - 1].pickominos->precedent = NULL;
                }
            }
            else
            {
                if (joueur[tour - 1].pickominos != NULL)
                {
                    joueur[tour - 1].pickominos->suivant = pickos->premier;
                    pickos->premier->precedent->suivant = pickos->premier->suivant;
                    pickos->premier->suivant->precedent = pickos->premier->precedent;
                    pickos->premier = pickos->premier->suivant;
                    joueur[tour - 1].pickominos->suivant->precedent = joueur[tour - 1].pickominos;
                    joueur[tour - 1].pickominos->suivant->suivant = NULL;
                    joueur[tour - 1].pickominos = joueur[tour - 1].pickominos->suivant;
                }
                else
                { // Quand le joueur prend son premier pickomino
                    joueur[tour - 1].pickominos = pickos->premier;
                    pickos->premier->precedent->suivant = pickos->premier->suivant;
                    pickos->premier->suivant->precedent = pickos->premier->precedent;
                    pickos->premier = pickos->premier->suivant;
                    joueur[tour - 1].pickominos->suivant = NULL;
                    joueur[tour - 1].pickominos->precedent = NULL;
                }
            }

            verif = 1; // Notre booléen prend la valeur un si un pickomino est attribué avec succès à un jour
        }
        else
        {
            pickos->premier = pickos->premier->suivant;
        }
    }

    if (verif != 1)
    { // Si le choix du picko voulu n'est plus sur la brochette, on vérifie d'abord s'il est visible sur la pile d'un joueur
        for (int i = 0; i < nbre_de_joueurs; i++)
        {
            if (i == tour - 1)
            {
                continue;
            }
            else
            {
                if (choix_picko == joueur[i].pickominos->valeur)
                { // Le joueur actuel prend le pickomino visible d'un autre joueur
                    joueur[tour - 1].pickominos->suivant = joueur[i].pickominos;
                    joueur[i].pickominos = joueur[i].pickominos->precedent;
                    joueur[i].pickominos->suivant = NULL;
                    joueur[tour - 1].pickominos->suivant->precedent = joueur[tour - 1].pickominos;
                    joueur[tour - 1].pickominos = joueur[tour - 1].pickominos->suivant;
                    joueur[tour - 1].pickominos->suivant = NULL;
                    verif = 1;
                    break;
                }
            }
        }
    }

    if (verif != 1)
    {
        reInitPicko(pickos);
        verif = verifInferieurProche(pickos, choix_picko, total_val); // On vérifie si le joueur a bien choisi la valeur inférieure la plus proche à celle qu'il devait avoir

        if (verif == 1)
        {
            total_val = choix_picko;
            verif = -1;
            verif = majPileJoueur(total_val, choix_picko, tour, joueur, verif, pickos, nbre_de_joueurs);
        }
    }

    return verif;
}

int verifInferieurProche(Liste *pickos, int choix_picko, int total_val)
{ // on vérifie si le choix du joueur est vraiment la valeur inférieure proche, sinon il passera son tour et perdra un pickomino
    int egal = 0;
    while (pickos->premier->valeur != choix_picko)
    {
        if (pickos->premier->valeur == 0)
        {
            break;
        }

        pickos->premier = pickos->premier->suivant;
    }

    if (pickos->premier->valeur == choix_picko)
    {
        egal = 1;
    }

    if (egal == 1)
    {
        if (pickos->premier->suivant->valeur > total_val)
        {
            egal = 1;
        }
        else
        {
            egal = 0;
        }
    }

    return egal;
}

void deroulementJeu(Liste *pickos, Joueur *joueur, int *tablede, int nbre_de_joueurs, int choix_menu)
{
    int tour = 0, tailleListe = 5, i = 0;
    // pickominos = malloc(nbre_de_joueurs * sizeof(Pile));
    clock_t tic = 0, toc = 0; // On partira sur des parties de 10 min maximum

    tour = quiCommence(nbre_de_joueurs);

    if (choix_menu == 1) // Si IA
    {
        for (int i = 0; i < nbre_de_joueurs; i++) // initialisation des données de chaque joueur
        {
            initJoueur(&joueur[i]);
        }
        printf("Entrez le nom du joueur : (Pas de point)");
        scanf("%s", joueur[0].nom);
        strcpy(joueur[1].nom, "IA");

        tic = clock();
        while (tailleListe != 1) // On joue tant que la brochette comporte des pickominos (taille > 1)
        {
            if (tour == 1)
            {
                tour = execJoueur(joueur, tour, tablede, nbre_de_joueurs, pickos);
                toc = clock();                                 // On récupère l'heure à chaque changement de tour
                if ((double)(toc - tic) / CLOCKS_PER_SEC > 60) // On arrête la partie si on joue depuis 10 min ou plus
                {
                    // viderPickos(pickos);
                    tailleListe = 1;
                }
                else
                {
                    tailleListe = comptElt(pickos);
                }
            }
            else
            {
                tour = execIA(pickos, joueur, tour, nbre_de_joueurs, tablede);
                tailleListe = comptElt(pickos);
            }
        }
    }
    else
    {
        for (i = 0; i < nbre_de_joueurs; i++) // initialisation des données de chaque joueur
        {
            initJoueur(&joueur[i]);
            printf("Entrez le nom du joueur %d: (Pas de point)", i + 1);
            scanf("%s", joueur[i].nom);
        }

        tic = clock();
        while (tailleListe != 1) // On joue tant que la brochette comporte des pickominos (taille > 1)
        {
            tour = execJoueur(joueur, tour, tablede, nbre_de_joueurs, pickos);
            toc = clock();                                // On récupère l'heure à chaque changement de tour
            if ((double)(toc - tic) / CLOCKS_PER_SEC > 5) // On arrête la partie si on joue depuis 10 min ou plus
            {
                // viderPickos(pickos);
                tailleListe = 1;
            }
            else
            {
                tailleListe = comptElt(pickos);
            }
        }
    }

    comptPoints(joueur, nbre_de_joueurs);  // On comptabilise les scores de chacun pour la délibération
    deliberation(joueur, nbre_de_joueurs); // Affichage des scores
}

void viderPickos(Liste *pickos)
{
    reInitPicko(pickos);
    if (comptElt(pickos) > 1)
    {
        pickos->premier = pickos->premier->precedent;
        pickos->premier->suivant = NULL;
        pickos->premier->precedent = NULL;
    }
}

void comptPoints(Joueur *joueur, int nbre_de_joueurs)
{
    for (int i = 0; i < nbre_de_joueurs; i++)
    {
        if (joueur[i].pickominos != NULL)
        {
            do
            {
                joueur[i].score += joueur[i].pickominos->point;
                joueur[i].pickominos = joueur[i].pickominos->precedent;
            } while (joueur[i].pickominos != NULL);
        }
    }
}

int quiCommence(int nbre_de_joueurs)
{ // on tire aléatoirement un nombre entre 1 et le nombre de joueurs, les joueurs ayant chacun choisi un nombre. Celui qui a le nombre est tiré au sort commence
    int n = 0;
    srand(time(NULL));
    n = rand() % nbre_de_joueurs + 1;
    return n;
}

void rendrePicko(Liste *pickos, Joueur *joueur)
{
    int val = 0;
    Element *p = NULL; // pointeur intermédiaire pour garder l'elt à restituer sur la brochette
    reInitPicko(pickos);
    if (joueur->pickominos != NULL)
    {
        val = joueur->pickominos->valeur;
        if (val != 0)
        {
            while (pickos->premier->valeur < val) // On cherche l'emplacement exact dans la liste
            {
                pickos->premier = pickos->premier->suivant;
            }

            p = joueur->pickominos;
            joueur->pickominos = joueur->pickominos->precedent;
            joueur->pickominos->suivant = NULL;
            p->suivant = pickos->premier;
            p->precedent = pickos->premier->precedent;
            pickos->premier->precedent->suivant = p;
            pickos->premier->precedent = p;
        }
    }
}

int comptElt(Liste *pickos)
{
    int val = pickos->premier->valeur, compt = 1;
    if (pickos->premier->suivant != NULL)
    {
        pickos->premier = pickos->premier->suivant;
    }

    while (pickos->premier->valeur != val)
    {
        compt++;
        pickos->premier = pickos->premier->suivant;
    }

    return compt;
}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void deliberation(Joueur *joueur, int nbre_de_joueurs)
{
    printf("\n\nFIN DE LA PARTIE.\nScores : ");
    for (int i = 0; i < nbre_de_joueurs; i++)
    { // boucle de comparaison du max de pickos gagnés
        printf("%s : %d\t", joueur[i].nom, joueur[i].score);
    }

    printf("\n\n");
}

char *maj(Joueur *joueur)
{
    int i;
    /*printf("\n Entrez la chaîne à convertir en majuscule: ");
    gets(str);*/
    for (i = 0; joueur->nom[i] != '\0'; i++)
    {
        /* si les caractères sont en minuscules, convertissez-les
            en majuscules en soustrayant 32 de leur valeur ASCII. */
        if (joueur->nom[i] >= 'a' && joueur->nom[i] <= 'z')
        {
            joueur->nom[i] = joueur->nom[i] - 32;
        }
    }
    return (joueur->nom);
}

void lireScoreJoueur()
{
    FILE *fichier = NULL;
    int i = 0, compt = 0, existe = 0;
    char nom_joueur[20];
    ListeNOM liste[8];

    fichier = fopen("scores.txt", "r");
    if (fichier != NULL)
    {
        /*printf("fichier ouvert , vous pouvez work wit\n");*/
        printf("ENTREZ SVP LE NOM DU JOUEUR DONT VOUS VOULEZ AFFICHER LES SCORES : ");
        scanf("%s", nom_joueur);
        for (i = 0; nom_joueur[i] != '\0'; i++)
        {
            /* si les caractères sont en minuscules, convertissez-les
                en majuscules en soustrayant 32 de leur valeur ASCII. */
            if (nom_joueur[i] >= 'a' && nom_joueur[i] <= 'z')
            {
                nom_joueur[i] = nom_joueur[i] - 32;
            }
        }

        while (!feof(fichier))
        {
            i = -1;

            do
            {
                i++;
                fscanf(fichier, "%s %d ", liste[i].nom, &liste[i].score); // Lecture d'une ligne complète du fichier
            } while (strcmp(liste[i].nom, ".") != 0);

            compt = i;
            i = 0;
            while (i < 7)
            {
                if (strstr(liste[i].nom, nom_joueur) != NULL)
                {
                    i = 10;
                }
                else
                {
                    i++;
                }
            }

            if (i == 10) // On affiche les résultats si le nom existe dans la base de données
            {
                existe = 1;
                for (int j = 0; j < compt - 1; j++)
                {
                    printf("%s: %d vs ", liste[j].nom, liste[j].score);
                }
                printf("%s: %d\n", liste[compt - 1].nom, liste[compt - 1].score);
            }
            else
            {
                existe = 0;
            }
        }

        if (existe == 0)
        {
            printf("\nCe nom n'existe pas en tant joueur\n");
        }
    }
    else
    {
        fprintf(stderr, "Can't open score file. Please try again later\n");
    }
}

void sauvScore(Joueur *joueur, int mode, FILE *fichier) /*cette fonction permet d'ecrire les scores dans un fichier en mettant en maj la premier lettre*/
{
    int i = 0;
    printf("Sauvegarde...\n");
    fichier = fopen("scores.txt", "a"); // Ouverture du fichier. Celui-ci sera créé s'il n'existe pas
    // printf("On pass l'ouverture");

    if (fichier != NULL)
    { // verification de l'ouverture du fichier
        for (i = 0; i < mode; i++)
        {
            strcpy(joueur[i].nom, maj(&joueur[i]));
            fprintf(fichier, "%s %d ", joueur[i].nom, joueur[i].score);
        }

        fprintf(fichier, ".\n");
        fclose(fichier);
    }
    else
    { // en cas de non ouverture du fichier
        perror("ERREUR LORS DE L'OUVERTURE DU FICHIER...");
    }
}