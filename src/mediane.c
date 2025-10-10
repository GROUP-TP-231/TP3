#include <stdio.h>
#include <stdlib.h>
#include "mediane.h"

static int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void filtreMedian(Image *img, const char *fichierResultat) {
    Image *res = malloc(sizeof(Image));
    *res = *img;
    res->pixels = malloc(img->hauteur * sizeof(Pixel*));

    for (int i = 0; i < img->hauteur; i++) {
        res->pixels[i] = malloc(img->largeur * sizeof(Pixel));

        for (int j = 0; j < img->largeur; j++) {
            int R[9], G[9], B[9], k = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < img->hauteur && nj >= 0 && nj < img->largeur) {
                        R[k] = img->pixels[ni][nj].r;
                        G[k] = img->pixels[ni][nj].g;
                        B[k] = img->pixels[ni][nj].b;
                        k++;
                    }
                }
            }
            qsort(R, k, sizeof(int), cmp);
            qsort(G, k, sizeof(int), cmp);
            qsort(B, k, sizeof(int), cmp);

            res->pixels[i][j].r = R[k/2];
            res->pixels[i][j].g = G[k/2];
            res->pixels[i][j].b = B[k/2];
        }
    }

    ecrirePPM(fichierResultat, res);
    libererImage(res);
    printf("opération effectuée\n");
}
