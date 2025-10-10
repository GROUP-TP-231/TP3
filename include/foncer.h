#ifndef FONCER_H
#define FONCER_H

typedef struct {
    int r, g, b;
} Pixel;

typedef struct {
    char version[3];
    int largeur, hauteur, max_val;
    Pixel **pixels;
} Image;

Image* lirePPM(const char *nomFichier);
void ecrirePPM(const char *nomFichier, Image *img);
void libererImage(Image *img);
void ajusterDominante(Image *img, char couleur, int valeur, const char *nomFichier);

#endif
