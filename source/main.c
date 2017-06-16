#include "generator.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
	char *output;
	int smt;
	char spSym, upp, num, op, next; 
	while(1){
		system("CLS");
		printf("Welome to the PasswordGenerator 1.0 \nParameters: length(amount),");
		printf("special symbols(Y/N), capital letters(Y/N), numbers(Y/N)");
		printf(" , output(F - for file output, S - for screen, B - for both)\n>");
		scanf("%d %c %c %c %c",&smt,&spSym,&upp,&num,&op);
		passwordGen(smt,spSym,upp,num,op,output);
		printf("\nNext password?(Y/N): ");
		scanf(" %c",&next);
		if(next != 'y' && next != 'Y') break;
	}
}
