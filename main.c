#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.c"

int main(void)
{
    int choix_menu = 0, nbre_de_joueurs = 0, *tablede = (int *)malloc(MAXTABLE * sizeof(*tablede));
    Liste *pickominos = (Liste *)malloc(sizeof(pickominos));
    Joueur joueur[MAXJOUEUR];
    FILE *fichier = NULL; // creation d'un descripteur de fichier qui servira de passerelle pour manipuler le fichier
    init(pickominos, 1);
    do
    {
        printf("\n\n");
        menu();
        scanf("%d", &choix_menu);
        switch (choix_menu)
        {
        case 1:
            nbre_de_joueurs = 2;
            deroulementJeu(pickominos, joueur, tablede, nbre_de_joueurs, choix_menu);
            sauvScore(joueur, nbre_de_joueurs, fichier);
            break;

        case 2:
            printf("Entrez le nombre de joueurs pour la partie (max = 7): ");
            scanf("%d", &nbre_de_joueurs);
            while (nbre_de_joueurs < 2 || nbre_de_joueurs > 7)
            {
                printf("Pour le multijoueur, il faut 2 a 7 joueurs :");
                scanf("%d", &nbre_de_joueurs);
            }

            deroulementJeu(pickominos, joueur, tablede, nbre_de_joueurs, choix_menu);
            sauvScore(joueur, nbre_de_joueurs, fichier);
            break;

        case 3:
            lireScoreJoueur();
            break;

        default:
            printf("Sortie du jeu...");
            break;
        }
    } while (choix_menu == 1 || choix_menu == 2 || choix_menu == 3);

    if (tablede != NULL)
    {
        free(tablede);
    }

    init(pickominos, 0);
    viderBuffer();

    return 0;
}