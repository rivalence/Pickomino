#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.c"

int main(void)
{
    int nbrede = 8;
    Liste *pickomino = init();
    /*choix_joueur(); */
    affichepicko(pickomino);
    return 0;
}
