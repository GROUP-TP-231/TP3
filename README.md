# Projet INF231 — Traitement d’images PPM (TP3)

##  Équipe de projet

| Nom & Prénom | Matricule | Rôle principal |
|---------------|------------|----------------|
| BILOA NGUEMA ALPHONSE KHAREL|24F2549|à travailler sur la fonction size et filtre  median |
|YEPMO WANMEGNI DAREL CEDRIK |24G2460 | à travailler sur la fonction negatif d une image ppm |
|NDZESSA EMMANUEL FREDY |24F2868| la fonction pour mettre en gris et le main ,organisation et structuration du projet |
|NKWELLE NGADE ULRICH MIGUEL |24H2305| à travailler sur la fonction pour foncer une image ppm |
|TANKEU TSAFACK ALVARO YVO |24F2525| à travailler sur la fonction pour foncer une image ppm |

---

## 🎯 Sujet du projet

Ce projet est réalisé dans le cadre du **cours INF231 – Techniques de Conception d’Algorithmes et Structures de Données**.  
L’objectif est de développer une **application de traitement d’images au format PPM (type P3)**, capable d’exécuter plusieurs opérations de base sur les images, notamment :

1. **Foncer / Éclaircir** les pixels selon leur **dominante** de couleur (`dom`).
2. **Conversion en niveaux de gris** (`gris`).
3. **Création du négatif** (`neg`).
4. **Affichage de la taille** d’une image (`size`).
5. **Découpage** d’une sous-image (`cut`).
6. **Application d’un filtre médian** (`fil`).

Le programme fonctionne en mode interactif, avec une invite de commande :

---

##  Organisation du dépôt

Le travail a été organisé en **branches individuelles** sur GitHub, chaque membre ayant travaillé sur sa partie du code.  
Une intégration finale a été faite sur la branche `main`.

### Structure du projet :
├── src/ # Contient les fichiers sources (.c)
│ ├── main.c
│ ├── foncer.c
│ ├── mediane.c
│ ├── gris.c
│ ├── size.c
│ ├── cut.c
│ └── negatif.c
│
├── include/ # Contient les fichiers d’en-têtes (.h)
│ ├── foncer.h
│ ├── mediane.h
│ ├── gris.h
│ ├── size.h
│ ├── cut.h
│ └── negatif.h
│
├── bin/ # Contient l’exécutable compilé
│ └── ppmviewer
│
├── doc/ # Fiches de progression et documentation
│ ├── progression1.pdf
│ └── progression2.pdf
│
├── Makefile # Automatisation de la compilation
└── README.md # Ce fichier


---

##  Compilation

Le projet se compile à l’aide du **Makefile** fourni.  
Depuis la racine du projet, exécutez :

```bash
make
Pour l execution
./bin/ppmviewer

```
## exemple d execution
```bash
$ ./bin/ppmviewer
Application de traitement d’images PPM réalisée par Groupe X.
ppmviewer > size image1.ppm
Dimensions: 100 x 205
Opération effectuée
ppmviewer > dom R 5 image1.ppm
opération effectuée ; image1.ppm_dom.ppm créé
ppmviewer > fil image1.ppm image_fil.ppm
opération effectuée
ppmviewer > quit
fin de l’exécution, au revoir...
```




