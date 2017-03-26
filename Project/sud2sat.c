#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 9
#define COL 9

int rule_1(char array[ROW][COL], int* clauses){
	int i, j, k;
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			for(k = 1; k < 10; k++){
				printf("%d%d%d ",i,j,k);
			}
			printf("0\n");
			(*clauses)++;
		}
	}
	return 1;
}

int rule_2(char array[ROW][COL], int* clauses){
        int i, j, k, l;
        for(i = 1; i < 10; i++){
                for(j = 1; j < 10; j++){
                        for(k = 1; k < 10; k++){
				for(l = j + 1; l < 10; l++){
					printf("-%d%d%d -%d%d%d 0\n", i, j, k, i, l, k);
					(*clauses)++;

				}
                        }
                }
        }
        return 1;
}

int rule_3(char array[ROW][COL], int* clauses){
        int i, j, k, l;
        for(i = 1; i < 10; i++){
                for(j = 1; j < 10; j++){
                        for(k = 1; k < 10; k++){
                                for(l = i + 1; l < 10; l++){
                                        printf("-%d%d%d -%d%d%d 0\n", i, j, k, l, j, k);
                                        (*clauses)++;

                                }
                        }
                }
        }
        return 1;
}

int rule_4(char array[ROW][COL], int* clauses){
	int a, b, i, j, k, l, m;
	char str[12];
	for(a = 0; a < 9; a+=3){
	for(b = 0; b < 9; b+=3){
	for(i = 1; i < 4; i++){
	for(j = 1; j < 4; j++){
	for(k = 1; k < 10; k++){
	for(l = j; l < 4; l++){
	for(m = i; m < 4; m++){
		if(m == i && l== j){
			continue;
		}
		//printf("%d %d %d %d %d %d %d\n",a, b, i, j, k, l, m);
		printf("-%d%d%d -%d%d%d 0\n", i + b, j + a, k, m + b, l + a, k);
		(*clauses)++;	
	}
	}
	}			
        }
	}
	}
	}
	return 1;
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

	int variables, clauses;
	variables = ROW * COL * 9;
	clauses = 0;

	char buffer[100];
	char array[ROW][COL];

	fp = fopen(argv[1], "r");
	if(!fp){
		printf("Error trying to read input, now exiting.\n");
		return -1;
	}
	//check for error fp

	fgets(buffer, 60, fp);
	printf("%s", buffer);//print grid # line
	
	int i, j;
	for(i = 0; i < ROW; i++){
		for(j = 0; j <= COL; j++){//<= is necessary!
			char c = fgetc(fp);
			if(c == '\n'){
				continue;
			}else{
				array[i][j] = c;
			}
		}
	}

	//print_grid(array);


//rule_1(array, &clauses);
//rule_2(array, &clauses);
//rule_3(array, &clauses);
rule_4(array, &clauses);


//WRITE TO FILE 
	fp2 = fopen("output.txt", "w+");
	char firstLine[10];
	sprintf(firstLine, "p cnf %d %d\n", variables, clauses);
	fwrite(firstLine, 1, sizeof(firstLine), fp2);

	fclose(fp);
	fclose(fp2);

/*
	char test[100] = "test 13 bytes";
	char* a = test;
	printf("%ld\n", strlen(a));//malloc strlen of ptr
*/

	exit(0);
}
