
#include <stdio.h>
#include <stdlib.h>
#include "negatif.h"

// Lire une image PPM (P3)
Images* lire_image_ppm(const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return NULL;
    }

    char type[3];
    fscanf(f, "%2s", type);
    if (type[0] != 'P' || type[1] != '3') {
        printf("Format non supporté (P3 attendu)\n");
        fclose(f);
        return NULL;
    }

    int largeur, hauteur, max_val;
    fscanf(f, "%d %d %d", &largeur, &hauteur, &max_val);

    // Allocation mémoire
    Images *img = malloc(sizeof(Images));
    img->largeur = largeur;
    img->hauteur = hauteur;
    img->max_val = max_val;

    img->R = malloc(hauteur * sizeof(int*));
    img->G = malloc(hauteur * sizeof(int*));
    img->B = malloc(hauteur * sizeof(int*));

    for (int i = 0; i < hauteur; i++) {
        img->R[i] = malloc(largeur * sizeof(int));
        img->G[i] = malloc(largeur * sizeof(int));
        img->B[i] = malloc(largeur * sizeof(int));
    }

    // Lecture des pixels
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            fscanf(f, "%d %d %d", &img->R[i][j], &img->G[i][j], &img->B[i][j]);
        }
    }

    fclose(f);
    return img;
}

// Écrire une image PPM
void ecrire_image_ppm(const char *nom_fichier, Images *img) {
    FILE *f = fopen(nom_fichier, "w");
    if (!f) {
        perror("Erreur écriture fichier");
        return;
    }

    fprintf(f, "P3\n%d %d\n%d\n", img->largeur, img->hauteur, img->max_val);

    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            fprintf(f, "%d %d %d ", img->R[i][j], img->G[i][j], img->B[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

// Créer le négatif
void creer_negatif(Images *img) {
    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            img->R[i][j] = 255 - img->R[i][j];
            img->G[i][j] = 255 - img->G[i][j];
            img->B[i][j] = 255 - img->B[i][j];
        }
    }
}

// Libérer la mémoire
void liberer_image(Images *img) {
    for (int i = 0; i < img->hauteur; i++) {
        free(img->R[i]);
        free(img->G[i]);
        free(img->B[i]);
    }
    free(img->R);
    free(img->G);
    free(img->B);
    free(img);
}
