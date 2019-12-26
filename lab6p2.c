#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//  Author: John Cody
//  Date created: 03/14/2018
//  Program Description: This program checks to find any diagonals in an array. 

void read_mat(FILE *in, int x[][7]);
int CheckDiagonals(int x[][7], int TestInt);

int main(void) {
	
	int array[6][7];
	FILE * input = fopen("test_diagonals_2.txt", "r");

	if (input == NULL) {
		printf("The program was unable to open the test_diagonals_2.txt file.\n");
		return -1;
	}

	read_mat(input, array);

	printf("\t    / %d %d %d %d %d %d %d \\\n", array[0][0], array[0][1], array[0][2], array[0][3], array[0][4], array[0][5], array[0][6]);
	printf("\t    | %d %d %d %d %d %d %d |\n", array[1][0], array[1][1], array[1][2], array[1][3], array[1][4], array[1][5], array[1][6]);
	printf("\tB = | %d %d %d %d %d %d %d |\n", array[2][0], array[2][1], array[2][2], array[2][3], array[2][4], array[2][5], array[2][6]);
	printf("\t    | %d %d %d %d %d %d %d |\n", array[3][0], array[3][1], array[3][2], array[3][3], array[3][4], array[3][5], array[3][6]);
	printf("\t    | %d %d %d %d %d %d %d |\n", array[4][0], array[4][1], array[4][2], array[4][3], array[4][4], array[4][5], array[4][6]);
	printf("\t    \\ %d %d %d %d %d %d %d /\n", array[5][0], array[5][1], array[5][2], array[5][3], array[5][4], array[5][5], array[5][6]);

	if (CheckDiagonals(array, 1)) {
		printf("At least one diagonal of four 1's exists in the matrix\n");
	}
	if (CheckDiagonals(array, 2)) {
		printf("At least one diagonal of four 2's exists in the matrix\n");
	}

	fclose(input);

	return 0;
}

int CheckDiagonals(int x[][7], int TestInt) {
	int i = 0, t = 0, sum = 0;
	TestInt = TestInt * 4;
	
	for (i = 0; i < 3; i++) {
		for (t = 7; t > 3; t--) {
			sum = x[i][7 - t] + x[i + 1][8 - t] + x[i + 2][9 - t] + x[i + 3][10 - t];
			if (sum == TestInt) {
				return 1;
			}
		}
	}
	return 0;
}

void read_mat(FILE *in, int x[][7]) {
	int j = 0, c = 0;

	for (j = 0; j < 6; j++) {
		for (c = 7; c > 0; c--) {
			fscanf(in, " %d", &x[j][7 - c]);
		}
	}
}