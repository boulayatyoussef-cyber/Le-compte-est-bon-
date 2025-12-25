# 🎯 Le Compte est Bon !

Projet d'informatique (MPI) consistant à implémenter le célèbre jeu mathématique **"Le Compte est Bon"**.  
Ce programme permet de **générer des tirages**, de **jouer de manière interactive** ou de **laisser l'ordinateur résoudre le problème** automatiquement.

---

## 📋 Présentation du projet

Le but du jeu est d'atteindre un nombre **cible** (entre 100 et 999) en utilisant **6 nombres** de départ parmi :  
`1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100`.  

Chaque nombre ne peut être utilisé qu'une seule fois et seules les **quatre opérations de base** sont autorisées : `+`, `-`, `*`, `/`.

### Règles principales :
* Les résultats intermédiaires doivent être des **entiers strictement positifs**.
* La **division** n'est autorisée que si le résultat est un entier (le diviseur doit être un diviseur exact du dividende).

---

## 🛠️ Structures de données utilisées

Le programme repose sur deux structures principales :

1. **Tableaux dynamiques (`int[]`)** :  
   Pour stocker et mettre à jour la liste des nombres disponibles au fur et à mesure des calculs.

2. **Structure `Solution`** :  
   Une structure personnalisée utilisée par le solveur pour mémoriser :
   - le **meilleur résultat atteint**  
   - la **séquence d'opérations** ayant conduit à ce résultat (pour l'affichage détaillé).

---

## 🚀 Modes de fonctionnement

Le programme propose **3 modes indépendants**, accessibles via le menu principal :

1. **Générer des instances** :  
   Affiche un tirage aléatoire de 6 nombres et une cible à atteindre.

2. **Le Jeu (Interactif)** :  
   L'utilisateur saisit ses calculs étape par étape.  
   Le programme **vérifie automatiquement la validité des opérations** et met à jour la liste des nombres restants jusqu'à atteindre la cible ou épuiser les nombres.

3. **Le Solveur automatique** :  
   L'ordinateur teste toutes les combinaisons possibles grâce à un **algorithme récursif**.
   - Affiche **"Le compte est bon !"** si la solution exacte est trouvée.
   - Propose d'afficher la **séquence détaillée des opérations**.
   - Si le compte exact est impossible, il indique le **résultat le plus proche** trouvé.

---

## 💻 Installation et Compilation

### Prérequis
* Un compilateur C (comme `gcc`).

### Compilation
Ouvrez un terminal dans le dossier du projet et tapez :

```bash
gcc jeu.c -o compte_est_bon
