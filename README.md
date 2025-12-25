# 🧮 Projet d’Informatique — Le Compte est Bon ! (C)

## Introduction
Ce projet consiste à implémenter le célèbre jeu **« Le compte est bon ! »** en langage C.  
L'objectif est de trouver une combinaison de 6 nombres (parmi une liste définie) pour atteindre une cible comprise entre 100 et 999.  
Le programme propose trois modes : génération d'instances, mode de jeu interactif et solveur automatique.

---

## Comment utiliser le programme

### Compilation
Pour compiler le programme, utilisez la commande suivante dans le terminal :

```bash
gcc jeu.c -o compte_est_bon
Exécution
Pour exécuter le programme compilé :

bash
Copier le code
./compte_est_bon
Le programme propose ensuite de choisir un mode de jeu :

Mode interactif (jouer)

Génération d’instances

Solveur automatique

Dans le mode interactif, le joueur sélectionne deux nombres et une opération (+, -, *, /). Le programme vérifie automatiquement la légalité de l'opération (pas de résultats négatifs ou nuls, pas de divisions avec reste) et met à jour la liste des nombres disponibles.

Structures de données choisies
1️⃣ Tableaux statiques (int[])
Les nombres disponibles pendant la partie sont stockés dans des tableaux d'entiers.

c
Copier le code
int numbers[MAX_NUM];
Justification :

Permet de stocker les 6 nombres initiaux et les résultats intermédiaires

Simple à manipuler pour ajouter ou retirer des éléments

Performant pour des opérations fréquentes de lecture et écriture

2️⃣ Structure personnalisée (struct Solution)
Pour le solveur automatique, une structure mémorise la meilleure solution trouvée.

c
Copier le code
typedef struct {
    int resultat;               // Valeur la plus proche de la cible
    char sequence[1024];        // Historique des calculs effectués
} Solution;
Justification :

Permet de garder le résultat final et toutes les étapes de calcul

Facilite l’affichage clair des solutions trouvées pour l’utilisateur

Structure compacte et adaptée à la récursion

Fonctions intermédiaires et affichage
Fonctions principales implémentées
void afficher_nombres(int numbers[], int taille) : affiche les nombres disponibles

int operation_legale(int a, int b, char op) : vérifie si une opération est valide

int mode_interactif() : gère le mode joueur avec saisie et calcul

void solveur_recursif(int numbers[], int taille, int cible, Solution *best) : explore toutes les combinaisons pour trouver la meilleure solution

void generer_instance(int numbers[]) : génère aléatoirement les nombres disponibles pour une partie

Fonctions d’affichage
void afficher_solution(Solution s) : affiche étape par étape le calcul trouvé par le solveur

void afficher_menu() : affiche le menu principal pour sélectionner le mode de jeu

Ces fonctions permettent de séparer la logique du programme et l’interface utilisateur, rendant le code plus lisible et maintenable.

Conclusion
Le programme respecte toutes les contraintes du jeu :

Gestion des opérations interdites

Recherche de solutions exactes ou approchées

Modes interactif et solveur automatique

Il met en œuvre :

Des structures de données efficaces

La récursion pour le solveur

Une logique algorithmique complète
