#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.h"
#include "jeu.c"

int main(void){
    int nbrede =8;
    Liste *maliste = init() ; 
    /*choix_joueur(); */
    afficherListe(maliste);
    return 0 ; 
}