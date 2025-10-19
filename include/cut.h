#ifndef CUT_H
#define CUT_H

typedef struct {
    int r, g, b;
} pixel;

typedef struct {
    int width;
    int height;
    int max_value;
    pixel **pixels;
} ImagePPM;

ImagePPM *lire_PPM(const char *nom_fichier);
void ecrire_PPM(const char *nom_fichier, ImagePPM *image);
ImagePPM *decouperPPM(ImagePPM *image, int l1, int l2, int c1, int c2);
void libererPPM(ImagePPM *image);

#endif
