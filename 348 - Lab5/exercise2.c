#include <stdio.h>

// Function to find all possible scoring combinations for a given score
void findScoringCombinations(int score, int combination[], int index) {
    // If the score is less than or equal to 1, print the combination
    if (score <= 1) {
        if (score == 0) {
            for (int i = 0; i < index; i++) {
                if (i > 0) {
                    printf(" + ");
                }
                if (combination[i] == 6) {
                    printf("Touchdown (TD)");
                } else if (combination[i] == 3) {
                    printf("Field Goal (FG)");
                } else if (combination[i] == 2) {
                    printf("Safety");
                } else if (combination[i] == 8) {
                    printf("Touchdown (TD) + 2-point conversion");
                } else if (combination[i] == 7) {
                    printf("Touchdown (TD) + 1-point field goal");
                }
            }
            printf("\n");
        }
        return;
    }

    // Recursively explore different scoring options
    if (score >= 6) {
        combination[index] = 6;  // Touchdown (TD)
        findScoringCombinations(score - 6, combination, index + 1);
    }

    if (score >= 3) {
        combination[index] = 3;  // Field Goal (FG)
        findScoringCombinations(score - 3, combination, index + 1);
    }

    if (score >= 2) {
        combination[index] = 2;  // Safety
        findScoringCombinations(score - 2, combination, index + 1);
    }

    if (score >= 8) {
        combination[index] = 8;  // Touchdown (TD) + 2-point conversion
        findScoringCombinations(score - 8, combination, index + 1);
    }

    if (score >= 7) {
        combination[index] = 7;  // Touchdown (TD) + 1-point field goal
        findScoringCombinations(score - 7, combination, index + 1);
    }
}

int main() {
    int score =2;
    while (1) {
        printf("Enter an NFL score (enter 1 or less to terminate): ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible scoring combinations for %d:\n", score);
        int combination[50];  // Assuming no more than 100 scoring plays
        findScoringCombinations(score, combination, 0);
    }

    printf("Program terminated.\n");
    return 0;
}
