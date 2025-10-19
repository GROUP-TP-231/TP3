#include <stdio.h>
#include <stdlib.h>
#include "cut.h"

ImagePPM *lire_PPM(const char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return NULL;
    }

    char format[3];
    fscanf(f, "%2s", format);
    if (format[0] != 'P' || format[1] != '3') {
        printf("Format PPM non supporté (seul P3 est accepté)\n");
        fclose(f);
        return NULL;
    }

    ImagePPM *img = malloc(sizeof(ImagePPM));
    fscanf(f, "%d %d", &img->width, &img->height);
    fscanf(f, "%d", &img->max_value);

    img->pixels = malloc(img->height * sizeof(pixel *));
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = malloc(img->width * sizeof(pixel));
        for (int j = 0; j < img->width; j++) {
            fscanf(f, "%d %d %d", &img->pixels[i][j].r, &img->pixels[i][j].g, &img->pixels[i][j].b);
        }
    }

    fclose(f);
    return img;
}

void ecrire_PPM(const char *nom_fichier, ImagePPM *image) {
    FILE *f = fopen(nom_fichier, "w");
    if (!f) {
        perror("Erreur ouverture fichier écriture");
        return;
    }

    fprintf(f, "P3\n%d %d\n%d\n", image->width, image->height, image->max_value);
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fprintf(f, "%d %d %d ", image->pixels[i][j].r,
                                    image->pixels[i][j].g,
                                    image->pixels[i][j].b);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

ImagePPM *decouperPPM(ImagePPM *image, int l1, int l2, int c1, int c2) {
    if (l1 < 0) l1 = 0;
    if (l2 > image->height) l2 = image->height;
    if (c1 < 0) c1 = 0;
    if (c2 > image->width) c2 = image->width;

    int new_height = l2 - l1;
    int new_width = c2 - c1;

    ImagePPM *decoupe = malloc(sizeof(ImagePPM));
    decoupe->width = new_width;
    decoupe->height = new_height;
    decoupe->max_value = image->max_value;

    decoupe->pixels = malloc(new_height * sizeof(pixel *));
    for (int i = 0; i < new_height; i++) {
        decoupe->pixels[i] = malloc(new_width * sizeof(pixel));
        for (int j = 0; j < new_width; j++) {
            decoupe->pixels[i][j] = image->pixels[l1 + i][c1 + j];
        }
    }

    return decoupe;
}

void libererPPM(ImagePPM *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}
