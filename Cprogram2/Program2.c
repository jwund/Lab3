/*
 * Program2.c
 *
 *  Created on: Feb 10, 2023
 *      Author: j787w862
 */


#include <stdio.h>

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to stop\nEnter a score: ");
        scanf("%d", &score);
        if (score <= 1) {
            break;
        }

        for (int a = 0; a < (score / 8) + 1; a++) {
            for (int b = 0; b < (score / 7) + 1; b++) {
                for (int c = 0; c < (score / 6) + 1; c++) {
                    for (int d = 0; d < (score / 3) + 1; d++) {
                        for (int e = 0; e < (score / 2) + 1; e++) {
                            if (8*a + 7*b + 6*c + 3*d + 2*e == score) {
                                printf("%d TD+2pt %d TD+1pt %d TD %d FG %d SF\n", a, b, c, d, e);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
