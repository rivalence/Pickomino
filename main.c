#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.c"

int main(void)
{
    int choix_menu = 0, nbre_de_joueurs = 0;
    Liste *pickominos = init();

    // viderBuffer();
    menu();
    scanf("%d", &choix_menu);
    switch (choix_menu)
    {
    case 1:
        nbre_de_joueurs = 2;
        break;

    case 2:
        printf("Entrez le nombre de joueurs pour la partie (max = 7): ");
        scanf("%d", &nbre_de_joueurs);
        while (nbre_de_joueurs < 2 || nbre_de_joueurs > 7)
        {
            printf("Pour le multijoueur, il faut 2 a 7 joueurs :");
            scanf("%d", &nbre_de_joueurs);
        }
        break;

    case 3:
        printf("Sortie du jeu...");
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
    exec(nbre_de_joueurs, pickominos, choix_menu);
    viderBuffer();

    return 0;
}