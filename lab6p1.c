#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//  Author: John Cody
//  Date created: 03/14/2018
//  Program Description: This program reads a file and uses that as input to populate an array. That array is then used to develop all of the parity values. 

void read_ar(FILE *in, int x[][5]);

int main(void) {

	int i = 0, tparity = 0;
	int array[5][5];
	int hparity[5];
	int vparity[5];
	FILE * input = fopen("array.txt", "r");

	if (input == NULL) {
		printf("The program was unable to open the array.txt file.\n");
		return -1;
	}

	read_ar(input, array);

	for (i = 0; i < 5; i++) {
		hparity[i] = (array[i][0] + array[i][1] + array[i][2] + array[i][3] + array[i][4]) % 2;
	}

	for (i = 0; i < 5; i++) {
		vparity[i] = (array[0][i] + array[1][i] + array[2][i] + array[3][i] + array[4][i]) % 2;
	}

	tparity = (hparity[0] + hparity[1] + hparity[2] + hparity[3] + hparity[4]) % 2;

	printf("\t    / %d %d %d %d %d \\ %d\n", array[0][0], array[0][1], array[0][2], array[0][3], array[0][4], hparity[0]);
	printf("\t    | %d %d %d %d %d | %d\n", array[1][0], array[1][1], array[1][2], array[1][3], array[1][4], hparity[1]);
	printf("\tA = | %d %d %d %d %d | %d\n", array[2][0], array[2][1], array[2][2], array[2][3], array[2][4], hparity[2]);
	printf("\t    | %d %d %d %d %d | %d\n", array[3][0], array[3][1], array[3][2], array[3][3], array[3][4], hparity[3]);
	printf("\t    \\ %d %d %d %d %d / %d\n", array[4][0], array[4][1], array[4][2], array[4][3], array[4][4], hparity[4]);
	printf("\t      %d %d %d %d %d\n\n", vparity[0], vparity[1], vparity[2], vparity[3], vparity[4]);

	printf("Horizontal parity word : %d %d %d %d %d\n", hparity[0], hparity[1], hparity[2], hparity[3], hparity[4]);
	printf("Vertical parity word : %d %d %d %d %d\n", vparity[0], vparity[1], vparity[2], vparity[3], vparity[4]);
	printf("Total parity bit : %d\n", tparity);

	fclose(input);

	return 0;
}

void read_ar(FILE *in, int x[][5]) {
	int j = 0, c = 0;

	for (j = 0; j < 5; j++) {
		for (c = 0; c < 5; c++) {
			fscanf(in, " %d", &x[j][c]);
		}
	}
}