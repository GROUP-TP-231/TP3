# Cahier de suivi - NDZESSA EMMANUEL FREDY  
**Matricule : 24F2868**  


## seance 3 - Projet INF231 : Traitement d’images PPM
 **Rôle principal :** Organisation générale du projet, écriture du programme principal (`main.c`), rédaction du `README.md`, et implémentation de la fonction de conversion en niveaux de gris (`gris`).

---

## 🧩 Contexte du projet

Ce projet s’inscrit dans le cadre du **TP Série 1 du cours INF231 — Techniques de Conception d’Algorithmes et Structures de Données**.  
Le but est de concevoir une application en langage **C** permettant de manipuler des images au format **PPM (Portable PixMap, type P3)**.  
L’application doit offrir plusieurs fonctionnalités : affichage de la taille, conversion en gris, création du négatif, découpage, filtrage médian, etc.

J’ai participé à la conception, à l’organisation du projet et au développement de plusieurs parties essentielles.

---

## 🔧 Mes contributions principales

### 🗂️ 1. Organisation du projet

- J’ai mis en place la **structure du dépôt GitHub** en suivant une logique claire :
- - J’ai créé le **Makefile** pour automatiser la compilation et générer l’exécutable dans `bin/`.
- J’ai aidé à la configuration du dépôt Git (création de branches, intégration sur `main`).

---

### 💻 2. Développement du `main.c`

- J’ai conçu le **programme principal** qui sert d’interface utilisateur en ligne de commande.
- Ce programme lit les commandes saisies après le prompt `ppmviewer >` et exécute les fonctions correspondantes :
- `size`, `gris`, `cut`, `neg`, `dom`, `fil`, `quit`
- J’ai veillé à respecter la **trace d’exécution** fournie dans le sujet du TP.
- J’ai ajouté une gestion d’erreurs claire et un message de fin convivial :
- J’ai corrigé les erreurs de logique (par ex. : accolade manquante dans le `if quit`) et supprimé les warnings liés à `coul` et `val`.

---

### 🌫️ 3. Implémentation de la fonction `gris`

- J’ai développé la fonction qui convertit une image en **niveaux de gris**.
- Cette fonction lit le fichier PPM ligne par ligne, calcule la moyenne `(R + G + B) / 3` pour chaque pixel, puis écrit le résultat dans un nouveau fichier.
- J’ai veillé à ce que la nouvelle image conserve les bonnes dimensions et le même en-tête que le fichier source.
- Le fichier de sortie porte le nom `<fichier>_gris.ppm`.

Extrait représentatif :
```c
int gris = (p->r + p->g + p->b) / 3;
p->r = p->g = p->b = gris;
```
## Séance 2 - mise en place du programme d ajout en tete et en queu dans une liste chainée circulaire et organisation du travail  

### Travail effectué :  
- **Organisation du projet** :  
  - Structuration du repository pour une meilleure lisibilité du code et des fichiers  
  - Création d’un dossier `doc/` pour centraliser la documentation technique et les comptes-rendus  
- **Développement algorithmique** :  
  - **Branche `liste_chaine_circulaire`** :  
    - Début de l’implémentation de la structure de données "liste chaînée circulaire"  
    - Étude des opérations de base (insertion en tete,insertion en queu,creation d une liste,affichage)  
    - Premiers tests sur de petits cas simples  

### Difficultés rencontrées :  
- Prise en main de la logique particulière des **listes chaînées circulaires**  
- Organisation des fichiers de documentation avec Git pour éviter les conflits  

### Solutions apportées :  
- Mise en place d’une **nomenclature claire** pour les fichiers de documentation  
- Étude et application d’exemples simples de listes circulaires avant une généralisation  

### Prochaines tâches :  
- Finaliser les opérations d’insertion et afficahge sur la **liste chaînée circulaire**  
- Ajouter des tests unitaires pour valider le bon fonctionnement  
- Compléter la documentation dans le dossier `doc/`  

### Objectifs atteints :  
- ✅ Repository mieux organisé  
- ✅ Création du dossier `doc/`  
- ✅ Début de développement sur la branche **`liste_chaine_circulaire`**  jusqua implementation



## Séance 1 - Première prise en main de Git/GitHub  

### Travail effectué :  
- **Création des comptes GitHub** : Suivi du tutoriel pour créer le compte personnel et l'organisation  
- **Configuration du dépôt** : Création du repository pour le projet TPE  
- **Organisation des branches** : Création et gestion de deux branches dédiées :  
  - **Branche `trié_tableau`** : Développement des algorithmes de tri  
  - **Branche `Inverser_Tableau`** : Développement de l'algorithme d'inversion  
- **Développement algorithmique** :  
  - **Branche `Inverser_Tableau`** : Implémentation complète de la fonction d'inversion de tableau  
  - **Branche `trié_tableau`** : Implémentation complète de la fonction de tri de tableau  
  - Tests et validation des deux algorithmes  
- **Gestion de version** :  
  - Commits réguliers dans les deux branches  
  - Organisation du code par fonctionnalité  
- **Documentation** :  
  - Mise à jour du README.md  
  - Prise en main de la syntaxe Markdown  

### Détails techniques par branche :  
**Branche `Inverser_Tableau` :**  
- Algorithme pour inverser l'ordre des éléments d'un tableau  
- Gestion des tableaux de différentes tailles  
- Optimisation de la complexité algorithmique (O(n))  
- Tests avec différents types de données  

**Branche `trié_tableau` :**  
- Implémentation d'un algorithme de tri efficace  
- Choix de l'algorithme : tri à bulle  
- Gestion des tableaux numériques et alphanumériques  
- Validation des résultats de tri  

### Difficultés rencontrées :  
- **Gestion multiple de branches** : Synchronisation entre `trié_tableau` et `Inverser_Tableau`  
- **Optimisation algorithmique** : Recherche des meilleures approches pour l'inversion et le tri  
- **Tests complets** : Validation sur tous les cas limites  
- **Documentation** : Adaptation entre le code et les consignes de documentation  

### Solutions apportées :  
- **Stratégie de branches** : Une branche par fonctionnalité pour un travail organisé  
- **Recherche algorithmique** : Documentation sur les meilleures pratiques  
- **Tests progressifs** : Validation étape par étape  
- **Intégration continue** : Préparation des merges vers la branche principale  

### Prochaines tâches :  
- **Développement** :  
  - Finaliser les tests unitaires sur les deux branches  
  - Préparer la fusion des deux branches vers `main`  
  - Optimiser les performances des algorithmes  
- **Documentation** :  
  - Commenter le code source de manière détaillée  
  - Créer un guide d'utilisation des fonctions  
- **Intégration** :  
  - Synchroniser avec le travail des autres membres  
  - Préparer les Pull Requests pour l'intégration  

### Objectifs atteints :  
- ✅ Compte GitHub personnel et organisation créés  
- ✅ Repository du projet initialisé  
- ✅ **Branche `Inverser_Tableau`** créée et développée  
- ✅ **Branche `trié_tableau`** créée et développée  
- ✅ Fonction d'inversion de tableau implémentée et testée  
- ✅ Fonction de tri de tableau implémentée et testée  
- ✅ Commits réguliers effectués sur les deux branches  
- ✅ Début de documentation avec README.md  

---

