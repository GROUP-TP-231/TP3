#ifndef SIZE_H
#define SIZE_H

#include <stdio.h>

// Structure de base d'une image PPM
typedef struct {
    int largeur;
    int hauteur;
    int maxval;
} image;

// Lit les infos d'une image PPM et retourne 0 si succès, 1 sinon
int lire_taille_ppm(const char *nom_fichier, image *img);

#endif
