#include <stdio.h>
#include <stdlib.h>
#include "gris.h"

void convertir_en_gris(const char *nom_fichier_entree, const char *nom_fichier_sortie) {
    FILE *in = fopen(nom_fichier_entree, "r");
    if (!in) {
        printf("Erreur : impossible d'ouvrir %s\n", nom_fichier_entree);
        return;
    }

    FILE *out = fopen(nom_fichier_sortie, "w");
    if (!out) {
        printf("Erreur : impossible de créer %s\n", nom_fichier_sortie);
        fclose(in);
        return;
    }

    char type[3];
    int largeur, hauteur, max_val;
    fscanf(in, "%s", type);
    fscanf(in, "%d %d", &largeur, &hauteur);
    fscanf(in, "%d", &max_val);
    fprintf(out, "%s\n%d %d\n%d\n", type, largeur, hauteur, max_val);

    int r, g, b;
    for (int i = 0; i < largeur * hauteur; i++) {
        fscanf(in, "%d %d %d", &r, &g, &b);
        int gris = (r + g + b) / 3;
        fprintf(out, "%d %d %d ", gris, gris, gris);
    }

    fclose(in);
    fclose(out);
}
