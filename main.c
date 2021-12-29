#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.c"

int main(void)
{
    int nbrede = 8, choix_menu = 0;
    Liste *pickominos = init();
    menu();
    scanf("%d", &choix_menu);
    deroulement_jeu(choix_menu, pickominos);
    /*choix_joueur(); */
    // affichepicko(pickominos);

    return 0;
}