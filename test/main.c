#define CTEST_MAIN
#include <stdio.h>
#include <ctest.h>


void main(int argc, const char** argv){
	int result = ctest_main(argc, argv);
	if(result == 0) printf("\nSucceed\n");
		else printf("\nFailed\n");
	system("PAUSE");
}
