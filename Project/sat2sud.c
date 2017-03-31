#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 9
#define COL 9

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

void write_grid(FILE* fp2, char array[ROW][COL], int number){
        int i, j;
	char firstLine[15];
	sprintf(firstLine, "Grid %02d\n", number);
	fwrite(firstLine, 1, strlen(firstLine), fp2);

        for(i = 0; i < ROW; i++){
                for(j = 0; j < COL; j++){
			//printf("%c", array[i][j]);
			fputc(array[i][j], fp2);
                }
                //printf("\n");
		fputc('\n', fp2);
		
        }
        //printf("\n");
}

int main(int argc, char* argv[]){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	double start = tv.tv_usec;
	FILE* fp;
	FILE* fp2;

	int variables, clauses, number;
	variables = ROW * COL * 9;
	clauses = 0;
	
	char array[ROW][COL];
	//read first.out
	fp = fopen(argv[1], "r");
	if(!fp){
		printf("Error trying to read input, now exiting.\n");
		return -1;
	}
	//file size
	fseek(fp, 0, SEEK_END);
	int fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char line[60];
	fgets(line, 60, fp);//skip first line "SAT"

	/*
	int i, j;
	for(i = 0; i < ROW; i++){
		for(j=0; j < COL; j++){
			char c  = fgetc(fp);
			if(c == '\n'){
				continue;
			}else{
				array[i][j] = c;
	}}}
*/
	//parse every string
	char* token;
	char buffer[fileSize];
	fgets(buffer, fileSize, fp);

	token = strtok(buffer, " ");

	while(token != NULL){
		token = strtok(NULL, " ");
		//printf("%s ", token);

		int val = atoi(token);
		if(val == 0){
			break;
		}else if(val < 111){
			continue;
		}else{
			//parse token into digits
			char digit1 = token[0];
			int val1 = digit1 - '0' - 1;;
			char digit2 = token[1];
			int val2 = digit2 - '0' - 1;
			char digit3 = token[2];
			//put in array
			array[val2][val1] = digit3;
		}
	}
	//print_grid(array);

	fp2 = fopen(argv[2], "w+");
	char firstLine[15];
	number++;
	write_grid(fp2, array, number);
	gettimeofday(&tv, NULL);
	double duration = tv.tv_usec - start;
	printf("sat2sud finished in %lf microseconds\n", duration);
	exit(0);
}
