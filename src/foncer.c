#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foncer.h"

Image * lirePPM(const char *nomFichier) {
    FILE *f = fopen(nomFichier, "r");
    if (!f) {
        printf("fichier non trouvé\n");
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(f, "%s", img->version);
    fscanf(f, "%d %d", &img->largeur, &img->hauteur);
    fscanf(f, "%d", &img->max_val);

    img->pixels = malloc(img->hauteur * sizeof(Pixel*));
    for (int i = 0; i < img->hauteur; i++) {
        img->pixels[i] = malloc(img->largeur * sizeof(Pixel));
        for (int j = 0; j < img->largeur; j++) {
            fscanf(f, "%d %d %d", &img->pixels[i][j].r, &img->pixels[i][j].g, &img->pixels[i][j].b);
        }
    }
    fclose(f);
    return img;
}

void ecrirePPM(const char *nomFichier, Image *img) {
    FILE *f = fopen(nomFichier, "w");
    fprintf(f, "%s\n%d %d\n%d\n", img->version, img->largeur, img->hauteur, img->max_val);
    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            fprintf(f, "%d %d %d ", img->pixels[i][j].r, img->pixels[i][j].g, img->pixels[i][j].b);
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

void libererImage(Image *img) {
    for (int i = 0; i < img->hauteur; i++)
        free(img->pixels[i]);
    free(img->pixels);
    free(img);
}

void ajusterDominante(Image *img, char couleur, int valeur, const char *nomFichier) {
    for (int i = 0; i < img->hauteur; i++) {
        for (int j = 0; j < img->largeur; j++) {
            Pixel *p = &img->pixels[i][j];
            char dom;
            if (p->r >= p->g && p->r >= p->b) dom = 'R';
            else if (p->g >= p->r && p->g >= p->b) dom = 'G';
            else dom = 'B';

            if (dom == couleur) {
                p->r += valeur; p->g += valeur; p->b += valeur;
                if (p->r > img->max_val) p->r = img->max_val;
                if (p->g > img->max_val) p->g = img->max_val;
                if (p->b > img->max_val) p->b = img->max_val;
                if (p->r < 0) p->r = 0;
                if (p->g < 0) p->g = 0;
                if (p->b < 0) p->b = 0;
            }
        }
    }

    char sortie[256];
    sprintf(sortie, "%s_dom.ppm", nomFichier);
    ecrirePPM(sortie, img);
    printf("opération effectuée ; %s créé\n", sortie);
}
