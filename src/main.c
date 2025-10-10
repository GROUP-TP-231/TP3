#include <stdio.h>
#include <string.h>
#include "gris.h"
#include "size.h"
#include "cut.h"
#include "negatif.h"
#include "foncer.h"
#include "mediane.h"


int main() {
    printf("Application de traitement d’images PPM réalisée par XXX.\n");
    char cmd[10], fichier[50];
    char entree[100], sortie[100];
    int l1, l2, c1, c2;
    char fichier1[100], fichier2[100];
    char coul;
    int val;
    while (1) {
        printf("ppmviewer > ");
        scanf("%s", cmd);

        if (strcmp(cmd, "gris") == 0) {
            scanf("%s", fichier);
            char sortie[60];
            sprintf(sortie, "%s_gris.ppm", fichier);
            convertir_en_gris(fichier, sortie);
            printf("Opération effectuée\n");
        }else if (strcmp(cmd, "size") == 0) {
            scanf("%s", fichier);
            image img;
            if (lire_taille_ppm(fichier, &img) == 0) {
                printf("Dimensions: %d x %d\n", img.largeur, img.hauteur);
                printf("Opération effectuée\n");
            }
        }else if (strcmp(cmd, "cut") == 0) {
                scanf("%s", entree);
                ImagePPM *img = lire_PPM(entree);
                if (!img) {
                    printf("Erreur lors de la lecture du fichier.\n");
                    return 1;
                }
                scanf("%d %d %d %d", &l1, &l2, &c1, &c2);

                ImagePPM *decoupe = decouperPPM(img, l1, l2, c1, c2);
                scanf("%s", sortie);

                ecrire_PPM(sortie, decoupe);
                printf("Operation effectuée %s\n", sortie);

                libererPPM(img);
                libererPPM(decoupe);        

        }else if (strcmp(cmd, "neg") == 0) {
            scanf("%s", entree);
            scanf("%s", sortie);

            Images *img = lire_image_ppm(entree);
            if (img == NULL) return 1;

            creer_negatif(img);
            ecrire_image_ppm(sortie, img);

            printf("Négatif créé avec succès dans %s\n", sortie);

            liberer_image(img);

        }else if (strcmp(cmd, "dom") == 0) {
            scanf(" %c %d %s", &coul, &val, fichier1);
            Image *img = lirePPM(fichier1);
            if (img) {
                ajusterDominante(img, coul, val, fichier1);
                libererImage(img);
            }
        }else if (strcmp(cmd, "fil") == 0) {
            scanf("%s %s", fichier1, fichier2);
            Image *img = lirePPM(fichier1);
            if (img) {
                filtreMedian(img, fichier2);
                libererImage(img);
            }
        }       
        else if (strcmp(cmd, "quit") == 0){
        printf("fin de l execution aurevoir....\n");
        break;
        } else {
            printf("Commande inconnue. Commandes disponibles : gris, size, cut, neg, dom, fil, quit\n");
        }
    }
    return 0;
}
