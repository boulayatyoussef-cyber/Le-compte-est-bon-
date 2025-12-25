# Le-compte-est-bon-
# 🧮 Projet d’Informatique — Le Compte est Bon ! (C)

## Introduction
Ce projet consiste à implémenter le célèbre jeu **« Le compte est bon ! »** en langage C.  
L'objectif est de trouver une combinaison de 6 nombres (parmi une liste définie) pour atteindre une cible comprise entre 100 et 999.  
Le programme propose trois modes : génération d'instances, mode de jeu interactif et solveur automatique.

---

## Structures de Données Utilisées

### Tableaux Statiques (Arrays)
Les nombres de départ et les nombres intermédiaires sont stockés dans des tableaux d'entiers (`int[]`).

```c
int numbers[MAX_NUM];
