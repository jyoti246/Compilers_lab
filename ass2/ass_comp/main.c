#include "myl.h"

int main(){
	char ch[] = "Assignment Done!\n";
	char endl[] = "\n";
	printStr(ch);
	//printStr(endl);
	int x = 7747;
	printInt(x);
	printStr(endl);
	x -= 7834784;
	printInt(x);
	printFlt(1933.0083);
	printStr(endl);
	if (readInt(&x)){
		printInt(x);
		
	}
	else
	{
		char err[] = "wrong input\n";
		printStr(err);
	}
	float f = 0;
	if (readFlt(&f)){
		
		printFlt(f);
		
	}
	else
	{
		char err[] = "wrong input\n";
		printStr(err);
	}
	printStr(endl);
	return 0;
}