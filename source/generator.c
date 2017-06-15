#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int passwordGen(int len,char spSym,char upp,char num,char op,char *out){
	char *output = (char*) malloc((len+1)*sizeof(char));
	
	if(len == 0){
		printf("\nInput parameters error"); return 0;
	}
	if(spSym != 'Y' && spSym != 'y' && spSym != 'N' && spSym != 'n'){
		printf("\nInput parameters error"); 
		output = ""; 
		return 0;
	}
	if(upp != 'Y' && upp != 'y' && upp != 'N' && upp != 'n'){
		printf("\nInput parameters error"); 
		output = ""; 
		return 0;
	}
	if(num != 'Y' && num != 'y' && num != 'N' && num != 'n'){
		printf("\nInput parameters error"); 
		output = ""; 
		return 0;
	}
	if(op != 'S' && op != 's' && op != 'F' && op != 'f' && op != 'B' && op != 'b'){
		printf("\nInput parameters error"); 
		output = ""; 
		return 0;
	}
	srand(time(NULL));
	int paramAmount = 4;
	int temp1, temp2;
	char tempChar;
	int par = 0;
	int parM[4];
	if(spSym == 'Y' | spSym == 'y') {parM[0] = 1; par++;} else parM[0] = 0;
	if(upp == 'Y' | upp == 'y') {parM[1] = 1; par++;} else parM[1] = 0;
	if(num == 'Y'| num == 'y') {parM[2] = 1; par++;} else parM[2] = 0;
	parM[3] = 2;
	int count = 0;
	output[len] = '\0';
	if(len >= par){
		while(count < par){
			temp1 = rand() % 3;
			if(parM[temp1] == 1){
				parM[temp1] = 2;
				switch(temp1){
					case 0:{
						tempChar = rand() % 15 + 33;
						output[count] = (char)tempChar;
						break;
					}
					case 1:{
						tempChar = rand() % 26 + 65;
						output[count] = (char)tempChar;
						break;
					}
					case 2:{
						tempChar = rand() % 10 + 48;
						output[count] = tempChar; 
						break;
					}
				}
				count++;
			}
		}
		while(count < len){
			temp1 = rand() % 4;
			if(parM[temp1] == 2 || parM[temp1] == 1){
				switch(temp1){
					case 0:{
						tempChar = rand() % 15 + 33;
						output[count] = (char)tempChar;
						count++;
						break;
					}
					case 1:{
						tempChar = rand() % 26 + 65;
						output[count] = (char)tempChar;
						count++;
						break;
					}
					case 2:{
						tempChar = rand() % 10 + 48;
						output[count] = tempChar; 
						count++;
						break;
					}
					case 3:{
						tempChar = rand() % 26 + 97;
						output[count] = (char)tempChar;
						count++;
						break;
					}
				}
			}
		}
	} else {output = "";  return 0;}
	int k = 0;
	switch(op){
		case 'S': case 's':{
			int cc = 0;
			int lg = strlen(output);
			while(cc < lg){
				if(output[cc] != '\n' && output[cc] != '\0')printf("%c",output[cc]);
				cc++;
			}
			break;
		}
		case 'F': case 'f':{
			FILE *f;
			f = fopen("output.txt", "w");
			int cc = 0;			
			while(cc < strlen(output)){
				if(output[cc] != '\n' && output[cc] != '\0')fputc(output[cc],f);
				cc++;
			}

			fclose(f);
			break;
		}
		case 'B': case 'b':{	
			int cc = 0;
			FILE *f;
			f = fopen("output.txt", "w");
			int lg;
			if(strlen(output) <= 7) lg = strlen(output); else lg = strlen(output) - 1;
			while(cc < lg){
				if(output[cc] != '\n' && output[cc] != '\0'){
					printf("%c",output[cc]); 
					fputc(output[cc],f);
				}
				cc++;
			}
			fclose(f);
			break;
		}
	}
	return 0;
}
