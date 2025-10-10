#include "size.h"
#include <stdlib.h>

int lire_taille_ppm(const char *nom_fichier, image *img) {
    FILE *fp = fopen(nom_fichier, "r");
    if (!fp) {
        printf("Erreur : impossible d’ouvrir %s\n", nom_fichier);
        return 1;
    }

    char format[3];
    if (fscanf(fp, "%2s", format) != 1 || format[0] != 'P' || format[1] != '3') {
        printf("Erreur : format non supporté (P3 attendu)\n");
        fclose(fp);
        return 1;
    }

    // Ignorer les commentaires
    int c = fgetc(fp);
    while (c == '#') {
        while (c != '\n' && c != EOF) c = fgetc(fp);
        c = fgetc(fp);
    }
    ungetc(c, fp);

    // Lire les dimensions et la valeur max
    if (fscanf(fp, "%d %d %d", &img->largeur, &img->hauteur, &img->maxval) != 3) {
        printf("Erreur : lecture des dimensions échouée\n");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    return 0;
}
