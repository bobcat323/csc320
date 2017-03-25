#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 9
#define COL 9

int rule_1(){
	return -1;
}

int to_decimal(int a, int b, char c){
	int i, j, k;
	i = a + 1;
	j = b + 1;
	k = (int)c;
	
	int val;
	
	val = 81 * (i - 1) + 9 * (j - 1) + (k - 1) + 1;	

	return val;
}

void print_grid(char array[ROW][COL]){
	int i, j;
	for(i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++){
			printf("%c", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char* argv[]){
	FILE* fp;
	FILE* fp2;
	//printf("%s\n", argv[1]);
	char buffer[100];
	char array[9][9];

	fp = fopen(argv[1], "r");
	//check for error fp

	fgets(buffer, 60, fp);
	printf("%s", buffer);
	

	int i, j;
	for(i = 0; i < 9; i++){
		for(j = 0; j <= 9; j++){
			char c = fgetc(fp);
			if(c == '\n'){
				continue;
			}else{
				array[i][j] = c;
			}
		}
	}

	print_grid(array);

printf("%d", to_decimal(2, 0,3));


//WRITE TO FILE 
	fp2 = fopen("output.txt", "w+");
	char str[] = "p cnf";
	fwrite(str, 1, sizeof(str), fp2);



	fclose(fp);
	fclose(fp2);
	exit(0);
}
