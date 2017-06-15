#include <generator.h>
#include <ctest.h>
#include <string.h>


CTEST(generator, test__1) 
{
	const int len = 2;
	const char spSym = 'y';
	const char upp = 'n';
	const char num = 'n';
	const char op = 's';
	char *output;
	passwordGen(len,spSym,upp,num,op,output);
	int check;
	if(output != "") check = 0;
	ASSERT_EQUAL(check,0);
}

CTEST(generator, test__2) 
{
	const int len = 2;
	const char spSym = 'y';
	const char upp = 'y';
	const char num = 'y';
	const char op = 's';
	char *output;
	passwordGen(len,spSym,upp,num,op,output);
	int check;
	if(output == "") check = 0;
	ASSERT_EQUAL(check,0);
	
}
CTEST(igenerator, test__3) 
{
	const int len = 5;
	const char spSym = 'y';
	const char upp = 'n';
	const char num = 's';
	const char op = 's';
	char *output;
	passwordGen(len,spSym,upp,num,op,output);
	int check;
	if(output == "") check = 0;
	ASSERT_EQUAL(check,0);
	
}

