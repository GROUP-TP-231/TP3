🧾 Cahier de Suivi de TP3 UE INF 231
Titre : Donner le négatif d’une image
🔹 1. Identification

Nom et prénom : Yepmo Wanmegni Darel Cedrik

Matricule : 24G2460

Niveau : Licence 2 – Informatique



🔹 2. Contexte du TP

Ce travail s’inscrit dans le cadre de l’étude du traitement d’images au format PPM (Portable PixMap), dans le but de se familiariser avec les fichiers, les tableaux et la manipulation des données structurées en langage C.

L’objectif du projet global est de concevoir une application de traitement d’images permettant diverses opérations (éclaircir, foncer, gris, filtre, etc.).
Dans cette partie spécifique, il s’agit de créer le négatif d’une image PPM.

🔹 3. Objectif du travail

L’objectif du TP est de :

Écrire un programme modulaire en langage C qui lit une image au format PPM (P3) et produit son négatif, en inversant les couleurs de chaque pixel selon la formule :

𝑅
′
=
255
−
𝑅
,
𝐺
′
=
255
−
𝐺
,
𝐵
′
=
255
−
𝐵
R
′
=255−R,G
′
=255−G,B
′
=255−B
🔹 4. Description du programme
🧩 Structure du projet

Le travail est organisé de manière modulaire :

ppm_negatif/
├── main.c       → programme principal
├── negatif.c      → fonctions de traitement d’images
├── negatif.h      → déclarations des structures et prototypes
└── Makefile     → compilation automatisée

📘 a) Structure de données
typedef struct {
    int largeur;
    int hauteur;
    int max_val;
    int **R, **G, **B;
} Image;

 b) Principe du programme

Lecture du fichier image .ppm (format P3).

Calcul du négatif (inversion des valeurs de chaque composante RGB).

Écriture de la nouvelle image dans un autre fichier.

Libération de la mémoire.

🔹 5. Exemple de fonctionnement
 Entrée :

Image source image1.ppm :

P3
2 2
255
255 0 0   0 255 0
0 0 255   255 255 255

🧮 Sortie :

Image négative image_neg.ppm :

P3
2 2
255
0 255 255   255 0 255
255 255 0   0 0 0

🔹 6. Compilation et exécution
📦 Compilation :
make

▶️ Exécution :
./negatif


L’utilisateur saisit ensuite :

Entrez le nom du fichier image PPM à traiter : image1.ppm
Entrez le nom du fichier résultat : image_neg.ppm

🔹 7. Résultats obtenus

Le programme génère correctement une nouvelle image .ppm contenant l’inversion des couleurs de l’image d’origine.
L’affichage terminal confirme :

✅ Négatif créé avec succès dans image_negatif.ppm

🔹 8. Difficultés rencontrées

Fichiers .ppm introuvables à cause de noms avec espaces.

Erreur de lecture au début liée au mauvais format d’image (jpg renommé en ppm).

Nécessité de créer ou convertir une vraie image P3.

Gestion de la mémoire (malloc et free).

🔹 9. Améliorations possibles

Ajouter une vérification automatique du format de fichier.

Créer une interface utilisateur (menu de commandes).

Ajouter d’autres filtres (gris, médian, luminosité…).

🔹 10. Conclusion

Ce TP a permis de comprendre :

La structure d’un fichier image au format PPM,

L’utilisation des tableaux dynamiques en C,

L’écriture d’un programme modulaire,

Et la manipulation de fichiers en lecture/écriture.

La réalisation du négatif d’une image illustre concrètement la puissance du langage C pour le traitement des données multimédias.
