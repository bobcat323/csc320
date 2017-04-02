#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 9
#define COL 9

char* rule_0(char array[ROW][COL], int* clauses){
        char str[100000];
        char* string = (char*)malloc(sizeof(char) * 100000);

        int i, j;
        for(i = 1; i < ROW + 1; i++){
                for(j = 1; j < COL + 1; j++){
                        if(array[i-1][j-1] != '0'){
                                //printf("%d%d  %c 0\n",i, j, array[i - 1][j - 1]);
                                sprintf(str, "%d%d%c 0\n",j, i, array[i-1][j -1]);
                                strcat(string, str);
                                (*clauses)++;
                        }
                }

        }

        return string;
}

char* rule_1(char array[ROW][COL], int* clauses){
	int i, j, k;
	char str[100000];
	char* string = (char*)malloc(sizeof(char) * 100000);
	//printf("%ld", sizeof(string));
	for(i = 1; i < 10; i++){
		for(j = 1; j < 10; j++){
			for(k = 1; k < 10; k++){
				//printf("%d%d%d ",i,j,k);
				sprintf(str, "%d%d%d ",i,j,k);
				strcat(string, str);
//printf("%s", str);
			}
			//printf("0\n");
			strcat(string, "0\n");
//printf("%s\n",str);
			(*clauses)++;
		}
	}
	//printf("%s",string);
	return string;
}

char* rule_2(char array[ROW][COL], int* clauses){
	char str[100000];
        char* string = (char*)malloc(sizeof(char) * 100000);
        int i, j, k, l;
        for(i = 1; i < 10; i++){
                for(j = 1; j < 10; j++){
                        for(k = 1; k < 10; k++){
				for(l = j + 1; l < 10; l++){
					//printf("-%d%d%d -%d%d%d 0\n", i, j, k, i, l, k);
					sprintf(str, "-%d%d%d -%d%d%d 0\n", i, j, k, i, l, k);
					strcat(string, str);
					(*clauses)++;

				}
                        }
                }
        }
        return string;
}

char* rule_3(char array[ROW][COL], int* clauses){
        int i, j, k, l;
	char str[100000];
        char* string = (char*)malloc(sizeof(char) * 100000);
        for(i = 1; i < 10; i++){
                for(j = 1; j < 10; j++){
                        for(k = 1; k < 10; k++){
                                for(l = i + 1; l < 10; l++){
                                        //printf("-%d%d%d -%d%d%d 0\n", i, j, k, l, j, k);
					sprintf(str, "-%d%d%d -%d%d%d 0\n", i, j, k, l, j, k);
                                        strcat(string, str);
                                        (*clauses)++;

                                }
                        }
                }
        }
        return string;
}
char* rule_4(char array[ROW][COL], int* clauses){
	int k, a, b, u, v, w, t;
	char str[100000];
    char* string = (char*)malloc(sizeof(char) * 100000);
	for(k = 1; k <= 9; k++){
		for(a = 0; a <= 2; a++){
			for(b = 0; b <= 2; b++){
				for(u = 1; u <= 3; u++){
					for(v = 1; v <= 2; v++){
						for(w = v+1; w <= 3; w++){
							sprintf(str, "-%d%d%d -%d%d%d 0\n", (3*a + u), (3*b + v), k, (3*a + u),(3*b + w), k);
							strcat(string, str);
							(*clauses)++;
					}}}}}}
	
	for(k = 1; k <= 9; k++){
		for(a = 0; a <= 2; a++){
			for(b = 0; b <= 2; b++){
				for(u = 1; u <= 2; u++){
					for(v = 1; v <= 3; v++){
						for(w = u+1; w <= 3; w++){
							for(t = 1; t <= 3; t++){
							sprintf(str, "-%d%d%d -%d%d%d 0\n", (3*a + u), (3*b + v), k, (3*a + w),(3*b + t), k);
							strcat(string, str);
							(*clauses)++;
}}}}}}}
}

/*
char* rule_4(char array[ROW][COL], int* clauses){
	int a, b, i, j, k, l, m;
	char str[100000];
        char* string = (char*)malloc(sizeof(char) * 100000);
	for(a = 0; a < 9; a+=3){//a+=3
	for(b = 0; b < 9; b+=3){//b+=3
	for(i = 1; i < 4; i++){
	for(j = 1; j < 4; j++){
	for(k = 1; k < 10; k++){
	for(l = 1; l < 4; l++){//l = j
	for(m = 1; m < 4; m++){//m = i
		
		if((m == i && l== j) || (l < j && m == i)){
			continue;
		}
		printf("a=%d,b=%d,i=%d,j=%d,k=%d,l=%d,m=%d,\t",a,b,i,j,k,l,m);
		printf("-%d%d%d -%d%d%d 0\n", i + b, j + a, k, m + b, l + a, k);
		sprintf(str, "-%d%d%d -%d%d%d 0\n", i + b, j + a, k, m + b, l + a, k);
		strcat(string, str);
		(*clauses)++;	
	}}}}}}}
	return string;
}
*/
void print_grid(char array[ROW][COL]){
	int i, j;
	for(i = 0; i < ROW; i++){
		for(j = 0; j < COL; j++){
			printf("%c", array[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
}

int main(int argc, char* argv[]){
	clock_t timer;
	timer = clock();
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

	fgets(buffer, 60, fp);
	//printf("%s", buffer);//print grid # line
	
	int i, j;
	i = j = 0;
	while(1){
		char c = fgetc(fp);
		if(c == EOF){
			//printf("reached EOF!\n");
			break;
		}else if(c == '\n'){
			//printf("continue\n");
			j = 0;
			i++;
			continue;
		}else{
			//printf("[%d][%d]:%c\n", i, j, c);
			array[i][j] = c;
			j++;
		}
	}

	//print_grid(array);

	char* s0 = rule_0(array, &clauses);
	char* s1 = rule_1(array, &clauses);
	char* s2 = rule_2(array, &clauses);
	char* s3 = rule_3(array, &clauses);

	char* s4 = rule_4(array, &clauses);
//printf("%s\n", s4);
//WRITE TO FILE 

	char comment[15];
	sprintf(comment, "c start of rule 4\n");

	fp2 = fopen(argv[2], "w+");
	char firstLine[15];
	sprintf(firstLine, "p cnf %d %d\n", variables, clauses);
	fwrite(firstLine, 1, sizeof(firstLine), fp2);
	fwrite(s0, 1, strlen(s0), fp2);
	fwrite(s1, 1, strlen(s1), fp2);
	fwrite(s2, 1, strlen(s2), fp2);
	//fwrite(comment, 1, strlen(comment), fp2);
	fwrite(s3, 1, strlen(s3), fp2);
	fwrite(s4, 1, strlen(s4), fp2);

	fclose(fp);
	fclose(fp2);

	timer = (((float)clock() - timer) / 1000000.0F) * 1000;
	printf("sud2sat took %ld milliseconds\n", timer);
	exit(0);
}
