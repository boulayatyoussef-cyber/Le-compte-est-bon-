#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

// On pose les bases : 6 nombres max et une cible qui monte jusqu'à 999.
#define MAX_NUM 6
#define MAX_TARGET 999
// Buffer assez large pour pas que le solveur sature quand il écrit le chemin.
#define MAX_OPS_STR 1024 

// Les ID pour nos opérations de base.
#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_DIV 4

// Petite structure pour que le solveur se souvienne de ce qu'il a trouvé de mieux.
typedef struct {
    int resultat;
    char sequence[MAX_OPS_STR];
} Solution;

// ==== LES PETITS OUTILS PRATIQUES ==== //

/**
 * Juste pour choper un nombre au hasard dans le tableau.
 */
int random_choice(int arr[], int n) {
    return arr[rand() % n];
}

/**
 * On vide la file d'attente du clavier pour éviter que le programme s'emballe.
 */
void vider_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- MODE 1 : GÉNÉRATION AUTOMATIQUE --- //

/**
 * On sort 6 nombres au pif dans la liste officielle et on fixe un objectif.
 */
void generer_instances(int numbers[], int *target, int n) {
    int possibles[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75, 100};
    int taille = sizeof(possibles) / sizeof(int);

    printf("\n--- C'est parti, voici le tirage ---\n");
    printf("Tes nombres : ");
    for (int i = 0; i < n; i++) {
        numbers[i] = random_choice(possibles, taille);
        printf("%d ", numbers[i]);
    }

    // La cible entre 100 et 999, pour que ce soit un vrai challenge.
    *target = rand() % 900 + 100; 
    printf("\nObjectif à atteindre : %d\n", *target);
    printf("------------------------------------\n");
}

// --- MODE 2 : À TOI DE JOUER --- //

/**
 * Le mode interactif. Tu choisis tes nombres, ton calcul, et on voit ce que ça donne.
 */
void jouer(int numbers_initial[], int n, int target) {
    // On travaille sur une copie pour garder les originaux intacts.
    int current_numbers[MAX_NUM];
    memcpy(current_numbers, numbers_initial, n * sizeof(int));
    int current_count = n; 

    printf("\n=== Mode 2 : À toi de jouer ! ===\n");
    printf("Cible : %d\n", target);

    while (current_count > 1) {
        int val1_input, val2_input; 
        int idx1 = -1, idx2 = -1; 
        char op_char_input;   
        int op = 0;           

        printf("\nNombres que tu peux utiliser : ");
        for (int i = 0; i < current_count; i++) {
             printf("%d ", current_numbers[i]);
        }
        printf("\n");
        
        // --- ÉTAPE 1 : CHOIX DES NOMBRES ---
        printf("Prends deux nombres dans la liste : ");
        if (scanf("%d %d", &val1_input, &val2_input) != 2) { 
            printf("Oula, saisis deux vrais nombres stp.\n");
            vider_buffer(); 
            continue;
        }
        
        // On checke si les nombres sont bien dispo dans le tableau.
        for (int i = 0; i < current_count; i++) {
            if (current_numbers[i] == val1_input) {
                idx1 = i;
                break;
            }
        }
        for (int i = 0; i < current_count; i++) {
            if (current_numbers[i] == val2_input && i != idx1) {
                idx2 = i;
                break; 
            }
        }

        if (idx1 == -1 || idx2 == -1) {
            printf("Ces nombres ne sont pas dans la liste (ou tu essaies d'utiliser le même deux fois). Réessaie.\n");
            continue;
        }
        
        int n1_calc = val1_input;
        int n2_calc = val2_input;

        // On trie les indices pour simplifier le nettoyage du tableau après.
        if (idx1 > idx2) { int temp = idx1; idx1 = idx2; idx2 = temp; }
        
        // --- ÉTAPE 2 : CHOIX DE L'OPÉRATION ---
        printf("\nTu veux faire quoi avec %d et %d ? (+, -, *, /) : ", n1_calc, n2_calc);
        
        if (scanf(" %c", &op_char_input) != 1) {
            printf("C'est pas un signe valide ça.\n");
            vider_buffer();
            continue;
        }
        
        if (op_char_input == '+') op = OP_ADD;
        else if (op_char_input == '-') op = OP_SUB;
        else if (op_char_input == '*') op = OP_MUL;
        else if (op_char_input == '/') op = OP_DIV;
        else {
            printf("Signe inconnu. On reste sur +, -, * ou /.\n");
            continue;
        }
        
        int res = 0;
        int legal = 1;

        // --- ÉTAPE 3 : CALCUL ET VÉRIFICATION DES RÈGLES ---
        if (op == OP_ADD) {
            res = n1_calc + n2_calc;
        } else if (op == OP_SUB) {
            res = n1_calc - n2_calc;
            if (res <= 0) legal = 0; // Pas de résultats négatifs ou nuls ici.
        } else if (op == OP_MUL) {
            res = n1_calc * n2_calc;
        } else if (op == OP_DIV) {
            if (n2_calc == 0 || n1_calc % n2_calc != 0) {
                legal = 0; // Division par zéro interdite et on veut des entiers.
            } else {
                res = n1_calc / n2_calc;
            }
        }
        
        if (!legal) {
            printf("Calcul impossible (règles : entier positif uniquement). Recommence.\n");
            continue;
        }

        printf("Ok : %d %c %d = %d\n", n1_calc, op_char_input, n2_calc, res);

        // --- ÉTAPE 4 : MISE À JOUR DU JEU ---
        // On remplace le premier par le résultat et on dégage le deuxième.
        current_numbers[idx1] = res; 
        for (int i = idx2; i < current_count - 1; i++) {
            current_numbers[i] = current_numbers[i + 1];
        }

        current_count--; 

        if (res == target) {
            printf("\n🎯 BIEN JOUÉ ! Le compte est bon !\n");
            return;
        }
    }

    // Si on arrive au bout sans le bon chiffre.
    int last = (current_count == 1) ? current_numbers[0] : -1;
    if (last != -1) {
        printf("\nTerminé ! Ton score final : %d\n", last);
        printf("Il te manquait %d pour avoir %d.\n", abs(target - last), target);
    }
}

// --- MODE 3 : LE SOLVEUR AUTOMATIQUE --- //

/**
 * C'est ici que l'ordi teste absolument tout par récursion.
 */
int solveur_rec(int nums[], int n, int target, Solution *best_sol, char current_ops[]) {
    
    // À chaque tour, on regarde si un des nombres est la cible ou s'en rapproche.
    for (int i = 0; i < n; i++) {
        int diff = abs(nums[i] - target);
        if (diff < abs(best_sol->resultat - target)) {
            best_sol->resultat = nums[i];
            strcpy(best_sol->sequence, current_ops);
        }
        if (nums[i] == target) return 1; // On a trouvé le Graal !
    }
    
    if (n <= 1) return 0; // Plus rien à combiner.

    // On teste toutes les paires possibles.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = nums[i], b = nums[j];
            int temp[MAX_NUM];
            
            // On prépare la liste pour le prochain tour (sans les deux qu'on utilise).
            int k = 0;
            for (int t = 0; t < n; t++) {
                if (t != i && t != j) temp[k++] = nums[t];
            }

            // On définit les tests : +, *, a-b, b-a, a/b, b/a.
            typedef struct { char op_char; int n1; int n2; int res; } Operation;
            Operation ops_to_test[6];
            int num_ops_to_test = 0;

            ops_to_test[num_ops_to_test++] = (Operation){'+', a, b, a + b};
            ops_to_test[num_ops_to_test++] = (Operation){'*', a, b, a * b};
            if (a > b) ops_to_test[num_ops_to_test++] = (Operation){'-', a, b, a - b};
            if (b > a) ops_to_test[num_ops_to_test++] = (Operation){'-', b, a, b - a};
            if (b != 0 && a % b == 0) ops_to_test[num_ops_to_test++] = (Operation){'/', a, b, a / b};
            if (a != 0 && b % a == 0 && a != b) ops_to_test[num_ops_to_test++] = (Operation){'/', b, a, b / a};
            
            for (int o = 0; o < num_ops_to_test; o++) {
                Operation current_op = ops_to_test[o];
                if (current_op.res <= 0) continue; 
                
                char next_op_str[MAX_OPS_STR];
                sprintf(next_op_str, "(%d %c %d = %d)", current_op.n1, current_op.op_char, current_op.n2, current_op.res);
                
                char new_ops[MAX_OPS_STR];
                if (strlen(current_ops) + strlen(next_op_str) >= MAX_OPS_STR) continue;

                strcpy(new_ops, current_ops);
                strcat(new_ops, next_op_str);
                
                // On relance la recherche avec le nouveau résultat dans la liste.
                temp[k] = current_op.res;
                if (solveur_rec(temp, k + 1, target, best_sol, new_ops)) return 1;
            }
        }
    }
    return 0;
}

/**
 * On prépare le terrain et on lance le calcul.
 */
void solveur(int numbers_initial[], int n, int target) {
    Solution best_sol;
    best_sol.resultat = 0; 
    best_sol.sequence[0] = '\0';

    printf("\nCible : %d\n", target);
    printf("L'ordi réfléchit... ça peut prendre une seconde.\n");
    
    int numbers_copy[MAX_NUM];
    memcpy(numbers_copy, numbers_initial, n * sizeof(int));
    
    char reponse;
    if (solveur_rec(numbers_copy, n, target, &best_sol, "")) {
        printf("\n🎯 Trouvé ! Le compte est pile poil bon.\n");
        printf("Tu veux voir la solution ? (o/n) : ");
        if (scanf(" %c", &reponse) == 1 && (reponse == 'o' || reponse == 'O')) {
            printf("Le chemin : %s\n", best_sol.sequence);
        }
    } else {
        printf("\nDésolé, impossible de tomber pile sur %d avec ces nombres.\n", target);
    }
}

// --- LE CŒUR DU PROGRAMME --- //
int main() {
    srand(time(NULL));

    int mode;
    printf("=== LE COMPTE EST BON ===\n");
    printf("1. Tirage aléatoire\n2. Lancer une partie\n3. Utiliser le solveur (manuel)\nTon choix : ");
    
    if (scanf("%d", &mode) != 1) {
        printf("Saisie incorrecte, salut !\n");
        return 1;
    }
    vider_buffer(); 

    int n = MAX_NUM;
    int numbers[MAX_NUM];
    int target = 0; 

    if (mode == 1) {
        generer_instances(numbers, &target, n);
    } else if (mode == 2) {
        generer_instances(numbers, &target, n);
        jouer(numbers, n, target);
    } else if (mode == 3) {
        printf("\nEntrer tes %d nombres (séparés par un espace) : ", n);
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &numbers[i]) != 1) return 1;
        }
        printf("Cible à atteindre : ");
        if (scanf("%d", &target) != 1) return 1;
        
        solveur(numbers, n, target);
    } else {
        printf("Mode inconnu, bye !\n");
    }

    return 0;
}
