# Le Compte est Bon ! 🎯

Projet d'informatique (MPI) consistant à implémenter le célèbre jeu mathématique "Le Compte est Bon". Ce programme permet de générer des tirages, de jouer interactivement ou de laisser l'ordinateur résoudre le problème.

## 📋 Présentation du projet
[cite_start]Le but du jeu est d'atteindre un nombre **cible** (entre 100 et 999) en utilisant **6 nombres** de départ (parmi : 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100)[cite: 9]. 
[cite_start]Chaque nombre ne peut être utilisé qu'une seule fois avec les quatre opérations de base : `+`, `-`, `*`, `/`[cite: 10].

### Règles respectées :
* [cite_start]Les résultats intermédiaires doivent être des entiers strictement positifs[cite: 11, 24].
* [cite_start]La division n'est autorisée que si le résultat est un entier (le diviseur doit être un diviseur exact du dividende)[cite: 11].

## 🛠️ Structures de Données utilisées

Le programme repose sur deux structures principales :
1.  [cite_start]**Tableaux dynamiques (Arrays) :** Pour stocker et mettre à jour la liste des nombres disponibles lors des calculs[cite: 5, 26].
2.  [cite_start]**Structure `Solution` :** Une structure personnalisée utilisée par le solveur pour mémoriser le meilleur résultat atteint et la chaîne de caractères (string) détaillant le chemin parcouru[cite: 29, 33, 35].



## 🚀 Modes de fonctionnement
[cite_start]Le programme propose 3 modes indépendants via un menu principal[cite: 5, 6]:

1.  [cite_start]**Générer des instances :** Affiche simplement un tirage aléatoire de 6 nombres et une cible[cite: 18, 19].
2.  **Le Jeu (Interactif) :** L'utilisateur saisit ses calculs étape par étape. [cite_start]L'ordinateur vérifie la validité et met à jour la liste des nombres restants jusqu'à atteindre la cible ou épuiser les nombres[cite: 20, 23, 26].
3.  **Le Solveur :** L'ordinateur utilise un algorithme récursif pour tester toutes les combinaisons possibles. 
    * [cite_start]Il affiche "Le compte est bon !" s'il trouve la solution exacte[cite: 32].
    * [cite_start]Il propose d'afficher la séquence d'opérations[cite: 33].
    * [cite_start]Si le compte exact est impossible, il donne le résultat le plus proche trouvé[cite: 34].



## 💻 Installation et Compilation

### Prérequis
* Un compilateur C (comme `gcc`).

### Compilation
Ouvrez un terminal dans le dossier du projet et tapez :
```bash
gcc jeu.c -o compte_est_bon
