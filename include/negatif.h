#ifndef NEGATIF_H
#define NEGATIF_H

typedef struct {
    int largeur;
    int hauteur;
    int max_val;
    int **R;
    int **G;
    int **B;
} Images;

Images* lire_image_ppm(const char *nom_fichier);
void ecrire_image_ppm(const char *nom_fichier, Images *img);
void creer_negatif(Images *img);
void liberer_image(Images *img);

#endif
