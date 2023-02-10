/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: j787w862
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	printf("Monthly sales report for 2023:\n");
	float numbers[12];
	char months[12][15] = {"January", "February", "March", "April", "May", "June", "July",
	"August", "September", "October", "November", "December"};
	FILE* file_input = fopen("input.txt", "r");
	for (int i = 0; i < 12; i++) {
		fscanf(file_input, "%f", &numbers[i]);
	}
	fclose(file_input);

	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++) {
		if (strlen(months[i]) < 8) {
			printf("%s\t\t$%.2f\n", months[i], numbers[i]);
		} else {
			printf("%s\t$%.2f\n", months[i], numbers[i]);
		}
	}

	float minimum = numbers[0];
	int min_month = 0;
	for (int i = 1; i < 12; i++) {
		if (numbers[i] < minimum) {
			minimum = numbers[i];
			min_month = i;
		}
	}
	float maximum = numbers[0];
	int max_month = 0;
	for (int i = 1; i < 12; i++) {
		if (numbers[i] > maximum) {
			maximum = numbers[i];
			max_month = i;
		}
	}
	float sum = 0;
	for (int i = 0; i < 12; i++) {
		sum += numbers[i];
	}
	float average = sum / 12;

	printf("\nSales summary:\n");
	printf("Minimum sales:\t$%.2f\t(%s)\n", minimum, months[min_month]);
	printf("Maximum sales:\t$%.2f\t(%s)\n", maximum, months[max_month]);
	printf("Average sales:\t$%.2f\n", average);

	printf("\nSix-Month Moving Average Report:\n");
	for (int i = 0; i < 7; i++) {
		sum = 0;
		average = 0;
		for (int j = i; j < i + 6; j++) {
			sum += numbers[j];
		}
		average = sum / 6;
		if (i == 0) {
			printf("%s\t\t- %s\t\t%.2f\n", months[i], months[i+5], average);
		} else if (strlen(months[i]) < 8) {
			if (strlen(months[i+5]) < 8) {
				printf("%s\t\t- %s\t%.2f\n", months[i], months[i+5], average);
			} else {
				printf("%s\t\t- %s\t%.2f\n", months[i], months[i+5], average);
			}
		} else {
			if (strlen(months[i+5]) < 8) {
				printf("%s\t- %s\t\t%.2f\n", months[i], months[i+5], average);
			} else {
				printf("%s\t- %s\t%.2f\n", months[i], months[i+5], average);
			}
		}
	}

	printf("\nSales Report (Highest to Lowest):\n");
	float numbers_duplicate[12];
	memcpy(numbers_duplicate, numbers, sizeof numbers_duplicate);
	float sorted_numbers[12];
	float max = 0;
	for (int i = 0; i < 12; i++) {
		max = 0;
		for (int j = 0; j < 12; j++) {
			if (numbers_duplicate[j] > max) {
				max = numbers_duplicate[j];
			}
		}
		for (int j = 0; j < 12; j++) {
			if (max == numbers_duplicate[j]) {
				numbers_duplicate[j] = 0;
			}
		}
		sorted_numbers[i] = max;
	}
	printf("Month\t\tSales\n");
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (sorted_numbers[i] == numbers[j]) {
				if (strlen(months[j]) < 8) {
					printf("%s\t\t$%.2f\n", months[j], numbers[j]);
				} else {
					printf("%s\t$%.2f\n", months[j], numbers[j]);
				}
			}
		}
	}

	return 0;
}
