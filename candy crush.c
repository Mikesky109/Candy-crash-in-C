#include<stdio.h>
#include<stdlib.h>
#define N 50

int score = 0, finish = 0, start = 0, input = 0, impossiblemove = 0;

void checkend(int array[][N], int row, int column) {
	finish = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (array[i][j] == array[i][j + 2]) {
				if ((array[i][j] == array[i + 1][j + 1]) || (array[i][j] == array[i - 1][j + 1])) {
					finish = 1;
				}
			}
			if (array[i][j] == array[i + 2][j]) {
				if ((array[i][j] == array[i + 1][j + 1]) || (array[i][j] == array[i + 1][j - 1])) {
					finish = 1;
				}
			}
			if (array[i][j] == array[i][j + 1]) {
				if ((array[i][j] == array[i][j - 2]) || (array[i][j] == array[i][j + 3]) || (array[i][j] == array[i + 1][j - 1]) || (array[i][j] == array[i + 1][j + 2]) || (array[i][j] == array[i - 1][j - 1]) || (array[i][j] == array[i - 1][j + 2])) {
					finish = 1;
				}
			}
			if (array[i][j] == array[i + 1][j]) {
				if ((array[i][j] == array[i - 2][j]) || (array[i][j] == array[i + 3][j]) || (array[i][j] == array[i + 2][j - 1]) || (array[i][j] == array[i + 2][j + 1]) || (array[i][j] == array[i - 1][j - 1]) || (array[i][j] == array[i - 1][j + 1])) {
					finish = 1;
				}
			}
		}
	}
}

void refuel(int array[][N], int row, int column) {
	for (int i = row; i >= 0; i--) {
		for (int j = 0; j < column; j++) {
			if (array[i][j] == -1) {
				if (i == 0) {
					array[i][j] = (rand() % 6) + 1;
				}
				else {
					array[i][j] = array[i - 1][j];
					array[i - 1][j] = -1;
				}
			}
		}
	}
	int total = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (array[i][j] == -1) {
				total++;
			}
		}
	}
	if (total != 0) {
		refuel(array, row, column);
	}
}

void gengraph(int array[][N], int row, int column) {
	input = 0, start = 0, finish = 0, score = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			array[i][j] = (rand() % 6) + 1;
		}
	}
}

void check(int array[][N], int row, int column) {
	int x[50];
	int y[50];
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if ((array[i][j] == array[i][j + 1]) && (array[i][j + 1] == array[i][j + 2])) {
				if (array[i][j + 2] == array[i][j + 3]) {
					if (array[i][j + 3] == array[i][j + 4]) {
						x[count] = i; y[count] = j+4; count++;
						//array[i][j + 4] = -1;
					}
					x[count] = i; y[count] = j + 3; count++;
					//array[i][j + 3] = -1;
				}
				//array[i][j] = array[i][j + 1] = array[i][j + 2] = -1;
				x[count] = i; y[count] = j; count++;
				x[count] = i; y[count] = j+1; count++;
				x[count] = i; y[count] = j+2; count++;
			}
			if ((array[i][j] == array[i + 1][j]) && (array[i + 1][j] == array[i + 2][j])) {
				if (array[i + 2][j] == array[i + 3][j]) {
					if (array[i + 3][j] == array[i + 4][j]) {
						x[count] = i + 4; y[count] = j; count++;
						//array[i + 4][j] = -1;
					}
					x[count] = i + 3; y[count] = j; count++;
					//array[i + 3][j] = -1;
				}
				x[count] = i; y[count] = j; count++;
				x[count] = i + 1; y[count] = j; count++;
				x[count] = i + 2; y[count] = j; count++;
				//array[i][j] = array[i + 1][j] = array[i + 2][j] = -1;
			}
		}
	}
	for (int i = 0; i < count; i++) {
		array[x[i]][y[i]] = -1;
	}
	/*if (start == 0) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				switch (array[i][j]) {
				case 1:printf("B\t"); break;
				case 2:printf("G\t"); break;
				case 3:printf("O\t"); break;
				case 4:printf("R\t"); break;
				case 5:printf("P\t"); break;
				case 6:printf("Y\t"); break;
				default:printf("-1\t"); break;
				}
				//printf("%d\t", array[i][j]);
			}
			printf("\n\n");
		}
		printf("==============================================\n");
	}*/
	int total = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (array[i][j] == -1) {
				total++;
				score++;
			}
		}
	}

	if (total == 0) {
		checkend(array, row, column);
	}

	if (total != 0) {
		if (start == 1) {
			for (int i = 0; i < row; i++) {
				printf("\t%d", i);
				if (i == (row - 1)) {
					printf("\n");
				}
			}
			printf("---");
			for (int i = 0; i < row; i++) {
				printf("--------");
				if (i == (row - 1)) {
					printf("\n");
				}
			}
			for (int i = 0; i < row; i++) {
				printf(" %d ", i);
				printf("|\t");
				for (int j = 0; j < column; j++) {
					switch (array[i][j]) {
					case 1:printf("B\t"); break;
					case 2:printf("G\t"); break;
					case 3:printf("O\t"); break;
					case 4:printf("R\t"); break;
					case 5:printf("P\t"); break;
					case 6:printf("Y\t"); break;
					default:printf("-1\t"); break;
					}
					//printf("%d\t", array[i][j]);
				}
				printf("\n   |\n");
			}
			for (int i = 0; i < row; i++) {
				printf("========");
			}
			printf("==\n");
		}
		refuel(array, row, column);
		input = 0;
		check(array, row, column);
	}
	else if ((total == 0) && (input == 1)) {
		printf("Error!\n");
		impossiblemove = 1;
	}
	else if ((start == 0) && (finish == 0)) {
		gengraph(array, row, column);
		check(array, row, column);
	}
	else {
		printf("\nScore: %d \n", score);
		for (int i = 0; i < row; i++) {
			printf("\t%d", i);
			if (i == (row - 1)) {
				printf("\n");
			}
		}
		printf("---");
		for (int i = 0; i < row; i++) {
			printf("--------");
			if (i == (row - 1)) {
				printf("\n");
			}
		}
		for (int i = 0; i < row; i++) {
			printf(" %d ", i);
			printf("|\t");
			for (int j = 0; j < column; j++) {
				switch (array[i][j]) {
				case 1:printf("B\t"); break;
				case 2:printf("G\t"); break;
				case 3:printf("O\t"); break;
				case 4:printf("R\t"); break;
				case 5:printf("P\t"); break;
				case 6:printf("Y\t"); break;
				}
				//printf("%d\t", array[i][j]);
			}
			printf("\n   |\n");
		}
		for (int i = 0; i < row; i++) {
			printf("========");
		}
		printf("==\n");
		checkend(array, row, column);
		if (finish == 0) {
			printf("No possible move!!");
			printf("You got %d score\n", score);
			printf("This is the new graph!!\n");
			gengraph(array, row, column);
			check(array, row, column);
		}
	}
}

int main() {
	int row, column, work = 0;
	int row1, column1, row2, column2;
	int temp, end = 0;
	int array[50][50];
	srand(time(NULL));
	while (work == 0) {
		printf("Number of row and column: ");
		scanf_s("%d %d", &row, &column);
		if ((row < 3) || (column < 3)) {
			printf("Error! row and column must larger than 3!!\n");
			printf("Please Input again!\n");
		}
		else {
			work = 1;
		}
	}
	/*for (int i = 0; i < row ; i++) {
		for (int j = 0; j < column; j++) {
			array[i][j] = (rand() % 6) + 1;
			//printf("%d\t", array[i][j]);
		}
		//printf("\n");
	}
	check(array, row, column, input, start);*/
	gengraph(array, row, column);
	check(array, row, column);
	start = 1;
	while (end == 0){
		printf("Input the row and column of the element you choose (Input row: -1 and column: -1 to end)\n");
		scanf_s("%d %d", &row1, &column1);
		if ((row1 != -1) && (column1 != -1)) {
			while ((row1 > row) || (column1 > column)) {
				printf("Error Input! Please input again (row : 0 - %d, column : 0 - %d)\n", row, column);
				scanf_s("%d %d", &row1, &column1);
			}
			printf("Input the row and column of the element you want to change\n");
			scanf_s("%d %d", &row2, &column2);
			while (((row2 != row1) && (row2 != (row1 - 1)) && (row2 != (row1 + 1))) || ((column2 != column1) && (column2 != (column1 - 1)) && (column2 != (column1 + 1))) || ((row2 == row1) && (column2 == column1))) {
				printf("Error Input! Please input again (It should be next to the first element)\n");
				scanf_s("%d %d", &row2, &column2);
			}
			input = 1, start = 1;
			temp = array[row1][column1];
			array[row1][column1] = array[row2][column2];
			array[row2][column2] = temp;
			/*for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					printf("%d\t", array[i][j]);
				}
				printf("\n\n");
			}
			printf("==============================================\n");*/
			//printf("%d", score);
			check(array, row, column);
			if (impossiblemove == 1) {
				temp = array[row1][column1];
				array[row1][column1] = array[row2][column2];
				array[row2][column2] = temp;
			}
			impossiblemove = 0;
			/*checkend(array, row, column);
			if (finish == 1) {
				printf("No possible move , new graph will be given!!!");
				gengraph(array, row, column);
				score = 0;
			}
			checkend(array, row, column);*/
		}
		else {
			end = 1;
		}
	}
	system("pause");
	return 0;
}