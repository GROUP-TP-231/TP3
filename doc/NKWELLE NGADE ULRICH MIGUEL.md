# 🖼️ Projet Image PPM — `foncer.c`

## 📘 Description du projet

Ce projet en **langage C** permet de **lire, traiter et enregistrer des images au format PPM (Portable Pixmap)**.  
Le programme utilise des structures pour représenter une image et ses pixels, lit les données d’un fichier `.ppm`, et peut ensuite enregistrer une nouvelle image après traitement (ex : fonçage, éclaircissement, filtrage, etc.).  
Le fichier `foncer.c` contient les fonctions principales de lecture et d’écriture d’images PPM.

---

## ⚙️ Structure du projet

```
📂 Projet_PPM
│
├── foncer.c        → Fonctions de lecture/écriture PPM
├── foncer.h        → Définitions des structures et prototypes
├── main.c          → Programme principal
└── image.ppm       → Exemple d’image d’entrée
```

---

## 🧩 Structures principales

```c
typedef struct {
    int r, g, b;  // Composantes Rouge, Vert, Bleu
} Pixel;

typedef struct {
    char version[3];  // "P3" pour format PPM
    int largeur;
    int hauteur;
    int max_val;      // valeur maximale d’intensité (souvent 255)
    Pixel **pixels;   // matrice dynamique de pixels
} Image;
```

---

## 🚀 Fonctionnalités principales

| Fonction | Description |
|-----------|--------------|
| `lirePPM(const char *nomFichier)` | Lit un fichier PPM et charge ses pixels en mémoire |
| `ecrirePPM(const char *nomFichier, Image *img)` | Écrit une image PPM à partir de la structure mémoire |
| *(autres fonctions)* | Appliquent un traitement sur l’image (ex : foncer, éclaircir, etc.) |

---

## 💻 Compilation et exécution

### 🧱 Compilation
Utilisez **gcc** pour compiler le projet :

```bash
gcc -o imagePPM main.c foncer.c
```

Si vous utilisez un fichier d’en-tête séparé :

```bash
gcc -o imagePPM main.c foncer.c -I.
```

### ▶️ Exécution

Assurez-vous d’avoir une image `image.ppm` dans le même dossier que le programme.

```bash
./imagePPM
```

---

## 🧪 Exemple d’exécution

```bash
$ ./imagePPM
Lecture du fichier image.ppm...
Traitement de l’image (fonçage)...
Écriture du résultat dans sortie.ppm
Opération terminée avec succès !
```

---

## 📄 Format PPM rappel

Le format **PPM** (type P3) est un format texte très simple :

```
P3
largeur hauteur
valeur_max
R G B R G B ...
```

Chaque triplet `(R, G, B)` représente un pixel de l’image.

---

## 🧠 Notes techniques

- Utilisation d’**allocations dynamiques (`malloc`)** pour stocker les pixels.  
- Vérification d’ouverture de fichier (`fopen`) pour éviter les erreurs.  
- Structure de données claire et modulaire.  
- Code facilement extensible pour ajouter des filtres ou effets.

---
