# 🔧 Traitement d'image PPM – Foncement d'une image

## 📚 Description

Ce projet consiste à écrire une fonction en langage C permettant de **foncer une image au format PPM (Portable Pixmap Format)**. Le traitement est effectué en modifiant les valeurs RGB des pixels pour réduire leur intensité lumineuse.

Ce travail a été réalisé dans le cadre d'un devoir academique.

---

## 🧠 Objectif

L'objectif principal était de :

- Lire une image au format `.ppm` (type P3 – texte),
- Parcourir les pixels de l'image,
- Appliquer un facteur de foncement (par exemple diviser les valeurs RGB par un certain coefficient),
- Sauvegarder l'image modifiée dans un nouveau fichier `.ppm`.

---

## 🗂️ Fichiers fournis

- `fonceur.c` – Contient l'implémentation de la fonction de foncement d'image.
- `fonceur.h` – Contient les déclarations de fonctions et les inclusions nécessaires.
- (Facultatif : ajouter un fichier `main.c` si tu as fait une démonstration ou un test).

---

## 🛠️ Compilation

Utilisez `gcc` pour compiler le projet. Par exemple :

```bash
gcc -o fonceur fonceur.c main.c
